#include "CollisionsManager.h"

CollisionManager* CollisionManager::_COLISOES = new CollisionManager();

CollisionManager* CollisionManager::getManager() {
	return _COLISOES;
};

CollisionManager::CollisionManager() {
	_hasCollisions = false;
};

void CollisionManager::init() {
	int i;

	_hud = GameState::getState()->getHud();
	_n = Ship::getShip();	
	for(i = 0; i < NUMALIENS; ++i)
		_aliens[i] = ((Alien*)GameState::getState()->getPiece(i));
	for(i = NUMALIENS; i < NUMALIENS+NUMSHIELDS; ++i)
		_escudos[i-NUMALIENS] = ((Shield*)GameState::getState()->getPiece(i));
	for(i = 0; i < NUMBULLETS; ++i)
		_bullets[i] = GameState::getState()->getBullet(i);
	for(i = 0; i < 11; ++i) {
		_balasAlien[i][0] = GameState::getState()->getEnemyBullets(i, 0);
		_balasAlien[i][1] = GameState::getState()->getEnemyBullets(i, 1);
	}
};

void CollisionManager::calculateCollisions() {
	shipBulletsCollision();
	alienBulletsCollision();
	alienCollisions();
};

void CollisionManager::alienCollisions() {
	// dist(C1, C2)^2 ≤ (r1 + r2)^2 then collide
	for(int i = 0; i < NUMALIENS; ++i)
		if(_aliens[i]->isAlive()) {
			// ALIEN -> NAVE
			// dist(C1, C2)^2 = (C2x-C1x)^2+(C2y-C1y)^2
			if(pow(_n->getX() - _aliens[i]->getX(), 2) 
				+ pow(_n->getY() - _aliens[i]->getY(), 2) 
				<= pow(_n->getRaio() + _aliens[i]->getRaio(), 2)) {
				// then colide
				_n->die();
				_hud->takeLife();
				_hud->takeLife();
				_hud->takeLife();
			}
			// ALIEN -> ESCUDOS
			for(int j = 0; j < NUMSHIELDS; ++j)
				if(_escudos[j]->isAlive())
					// dist(C1, C2)^2 = (C2x-C1x)^2+(C2y-C1y)^2
					if(pow(_escudos[j]->getX() - _aliens[i]->getX(), 2) + 
						pow(_escudos[j]->getY() - _aliens[i]->getY(), 2) 
						<= pow(_escudos[j]->getRaio() + _aliens[i]->getRaio(), 2)) {
						// then colide
						_escudos[j]->die();
					}
		}
};

void CollisionManager::shipBulletsCollision() {

	// dist(C1, C2)^2 ≤ (r1 + r2)^2 then collide
	for(int i = 0; i < NUMBULLETS; ++i)
		if(_bullets[i]->isAlive()) {
			// BALAS -> ESCUDOS
			for(int j = 0; j < NUMSHIELDS; ++j)
				if(_escudos[j]->isAlive())
					// dist(C1, C2)^2 = (C2x-C1x)^2+(C2y-C1y)^2
					if(pow(_escudos[j]->getX() - _bullets[i]->getX(), 2) + 
						pow(_escudos[j]->getY() - _bullets[i]->getY(), 2) 
						<= pow(_escudos[j]->getRaio() + _bullets[i]->getRaio(), 2)) {
						// then colide
						_escudos[j]->deplete();
						_bullets[i]->die();
					}
			// BALAS -> ALIENS
			for(int j = 0; j < NUMALIENS; ++j)
				if(_aliens[j]->isAlive())
					// dist(C1, C2)^2 = (C2x-C1x)^2+(C2y-C1y)^2
					if(pow(_aliens[j]->getX() - _bullets[i]->getX(), 2) + 
						pow(_aliens[j]->getY() - _bullets[i]->getY(), 2) 
						<= pow(_aliens[j]->getRaio() + _bullets[i]->getRaio(), 2)) {
						// then colide
						_aliens[j]->die();
						_hud->addScore(KILL_SCORE);
						_bullets[i]->die();
						// se era atirador procura por um amigo vivo atras
						if(_aliens[j]->hasBullets()) {
							int k = j;
							j -= 11;
							// se tiver na ultima fila as balas ja nao disparam
							if(j < 0) {
								_balasAlien[k%11][0]->depleted(); return;
							}
							for( ; j >= 0; j -= 11) {
								if(_aliens[j]->isAlive()) {
									_balasAlien[j%11][0]->setAlien(_aliens[j]);
									_balasAlien[j%11][1]->setAlien(_aliens[j]);
									_aliens[k]->setBullets(false);
									_aliens[j]->setBullets(true);
									return;
								}
							}
								//}
							// se nao encontrou nenhum vivo
							if(j < 0)
								_balasAlien[k%11][0]->depleted(); return;
						}
					}						
		}

};

void CollisionManager::alienBulletsCollision() {
	// dist(C1, C2)^2 ≤ (r1 + r2)^2 then collide
	for(int i = 0; i < 11; ++i)
		for(int k = 0; k < 2; ++k)
			if(_balasAlien[i][k]->isAlive()) {
				// BALASALIEN -> NAVE
				// dist(C1, C2)^2 = (C2x-C1x)^2+(C2y-C1y)^2
				if(pow(_n->getX() - _balasAlien[i][k]->getX(), 2) 
				   + pow(_n->getY() - _balasAlien[i][k]->getY(), 2) 
				   <= pow(_n->getRaio() + _balasAlien[i][k]->getRaio(), 2)) {
					// then colide
					_n->die();
					_n->setCoordinates(0.0, -40., 0.0);
					_hud->takeLife();
					_balasAlien[i][k]->die();
				}
				// BALASALIEN -> SHIELDS
				for(int j = 0; j < NUMSHIELDS; ++j)
					if(_escudos[j]->isAlive())
						// dist(C1, C2)^2 = (C2x-C1x)^2+(C2y-C1y)^2
						if(pow(_escudos[j]->getX() - _balasAlien[i][k]->getX(), 2) 
							+ pow(_escudos[j]->getY() - _balasAlien[i][k]->getY(), 2) 
							<= pow(_escudos[j]->getRaio() + _balasAlien[i][k]->getRaio(), 2)) {
							// then colide
							_escudos[j]->deplete();
							_balasAlien[i][k]->die();
						}

			}
};