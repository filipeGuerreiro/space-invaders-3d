#include "GameState.h"

GameState* GameState::_state = new GameState();
bool  GameState::_isRunning = true;

GameState::GameState() {
	_activeCamera = ORTHO;
	_luzActiva = 0;
};

GameState* GameState::getState() { 
	return _state;
};

bool GameState::isRunning() {
	return _isRunning;
};

void GameState::isRunning(bool b) {
	_isRunning = b;
};

Entity* GameState::getPiece(int i) {
	return _pieces[i];
};

Bullet* GameState::getBullet(int i) {
	return _bullets[i];
};

AlienBullet* GameState::getEnemyBullets(int i, int j) {
	return _enemyBullets[i][j];
};

Hud* GameState::getHud() {
	return _hud;
};

int GameState::getScore() {
	return _hud->getScore();
};

int GameState::getLives() {
	return _hud->getLives();
};

void GameState::setCamera(int c) {
	if(c > 0 && c <= NUMCAMERAS)
		_activeCamera = c;
	if(c > 1)
		((Alien *)_pieces[0])->set3D(true);
	else if(c == 1)
		((Alien *)_pieces[0])->set3D(false);
};

void GameState::setLightSource(int l) {
	if(l == 0) {
		glDisable(GL_LIGHT1);
		glEnable(GL_LIGHT0);
		_luzActiva = 0;
	} 
	else if(l == 1) {
		glDisable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		_luzActiva = 1;
	}
};

void GameState::debug() {
	((Material*) _pieces[0])->setDebug();
};

void GameState::updateExplosions(int elapsed) {
	for(int i = 0; i < NUMALIENS; ++i)
		if(!_pieces[i]->isAlive())
			((Alien *) _pieces[i])->updateExplosion(elapsed);
	
	if(Ship::getShip()->getExplosion()->isRunning())
		Ship::getShip()->updateExplosion(elapsed);
};

void GameState::reset() {
	float px, py;
	int i, j;

	/* posicao inicial dos aliens */
	px = -40.0;
	py = 35.0;

	for(i = 0; i < ROWS; ++i, py -= Y_DIST) {
		/* recuo do carreto */
		px = -40.0;
		for(j = 0; j < NUMALIENS/ROWS; ++j) {
			_pieces[i*NUMALIENS/ROWS+j]->reset();
			_pieces[i*NUMALIENS/ROWS+j]->setCoordinates(px, py, 0.0);
			px += X_DIST;
		}	
	}

	/* posicao inicial dos escudos */
	px = -35.0;
	py = -25.0;
	for(i = NUMALIENS; i < NUMALIENS+NUMSHIELDS; ++i) {
		((Shield *)_pieces[i])->reset();
		_pieces[i]->setCoordinates(px, py, 0);
		px += DIST_ESC;
	}

	// balas
	for(i = 0; i < NUMBULLETS; ++i)
		_bullets[i]->die();
	// balas inimigas
	for(i = 0; i < 11; ++i){
		for(j = 0; j < 2; ++j) {
			_enemyBullets[i][j]->die();
			_enemyBullets[i][j]->setAlien((Alien *)_pieces[NUMALIENS-(NUMALIENS/ROWS)+i]);
		}
	}

	Ship::getShip()->reset();
	Ship::getShip()->setCoordinates(0.0, -40.0, 0.0);

	_hud->reset();
	_isRunning = true;
};

void GameState::initPecas() {
	int i, j, r;
	float px, py;

	/* criar as cameras */
	_pieces[NUMALIENS+NUMSHIELDS+ORTHO-1] = new CameraOrtogonal();
	_pieces[NUMALIENS+NUMSHIELDS+FIRST_P-1] = new CameraFirstPerson();
	_pieces[NUMALIENS+NUMSHIELDS+THIRD_P-1] = new CameraThirdPerson();

	/* criar luz */
	_luzes[0] = new DirectionalLight(0.0, 0.0, 0.0);
	_luzes[1] = new Headlight(0.0, 0.0, 0.0);
	glEnable(GL_LIGHT0);

	// criar hud
	_hud = new Hud();

	/* posicao inicial dos aliens */
	px = -40.0;
	py = 35.0;

	/* inicializar seed */
	srand(time(NULL));
	
	for(i = 0; i < ROWS; ++i, py -= Y_DIST) {
		/* recuo do carreto */
		px = -40.0;
		for(j = 0; j < NUMALIENS/ROWS; ++j) {
			r = rand() % 3;
			if(r == 0)
				_pieces[i*NUMALIENS/ROWS+j] = new CoolAlien(px, py, 0);
			else if(r == 1)
				_pieces[i*NUMALIENS/ROWS+j] = new SquidAlien(px, py, 0);
			else
				_pieces[i*NUMALIENS/ROWS+j] = new SkullAlien(px, py, 0);
			px += X_DIST;
		}	
	}

	/* posicao inicial dos escudos */
	px = -35.0;
	py = -25.0;
	/* criar os escudos */
	for(i = NUMALIENS; i < NUMALIENS+NUMSHIELDS; ++i) {
		_pieces[i] = new Shield(px, py, 0);
		px += DIST_ESC;
	}

	// criar balas
	for(i = 0; i < NUMBULLETS; ++i)
		_bullets[i] = new Bullet();
	// balas inimigas
	for(i = 0; i < 11; ++i){
		for(j = 0; j < 2; ++j) {
			_enemyBullets[i][j] = new AlienBullet();
			_enemyBullets[i][j]->setAlien((Alien *)_pieces[NUMALIENS-(NUMALIENS/ROWS)+i]);
			((Alien *)_pieces[NUMALIENS-(NUMALIENS/ROWS)+i])->setBullets(true);
		}
	}

	// criar o background
	_pieces[NUMALIENS+NUMSHIELDS+3] = new Background();
};


void GameState::drawAll() {
	int i, j;

	if(_hud->getLives() < 1) {
		_hud->youLose(((Camera *) _pieces[NUMALIENS+NUMSHIELDS+_activeCamera-1])->getWidth(),
					  ((Camera *) _pieces[NUMALIENS+NUMSHIELDS+_activeCamera-1])->getHeight());
		isRunning(false);
	}
	if(_hud->getScore() == 5500) {
		_hud->youWin(((Camera *) _pieces[NUMALIENS+NUMSHIELDS+_activeCamera-1])->getWidth(),
					  ((Camera *) _pieces[NUMALIENS+NUMSHIELDS+_activeCamera-1])->getHeight());
		isRunning(false);
	}


	/* desenhar luz */
	_luzes[_luzActiva]->draw();

	// desenhar o HUD
	_hud->draw(((Camera *) _pieces[NUMALIENS+NUMSHIELDS+_activeCamera-1])->getWidth(),
			   ((Camera *) _pieces[NUMALIENS+NUMSHIELDS+_activeCamera-1])->getHeight());
	
	/* desenhar camera */
	if(_pieces[NUMALIENS+NUMSHIELDS+_activeCamera-1]->isAlive())
		_pieces[NUMALIENS+NUMSHIELDS+_activeCamera-1]->draw();

	/* desenhar aliens */
	for(i = 0; i < NUMALIENS; ++i) {
		if(_pieces[i]->isAlive())
			_pieces[i]->draw();
		// se tiver morrido e tiver a explodir
		else if(((Alien *) _pieces[i])->getExplosion()->isRunning())
			((Alien *) _pieces[i])->getExplosion()->draw();
	}

	// desenhar escudos
	for( ; i < NUMALIENS + NUMSHIELDS; ++i)
		if(_pieces[i]->isAlive())
			_pieces[i]->draw();

	/* desenhar nave */
	if(Ship::getShip()->isAlive())
		Ship::getShip()->draw();
	// se tiver a explodir
	if(Ship::getShip()->getExplosion()->isRunning())
		Ship::getShip()->drawExplosion();
	

	/* desenhar balas */
	for(i = 0; i < NUMBULLETS; ++i)
		if(_bullets[i]->isAlive())
			_bullets[i]->draw();
	for(i = 0; i < 11; ++i){
		for(j = 0; j < 2; ++j)
			if(_enemyBullets[i][j]->isAlive())
				_enemyBullets[i][j]->draw();
	}

	// desenhar o background
	_pieces[NUMALIENS+NUMSHIELDS+NUMCAMERAS]->draw();
};


void GameState::animateAliens() {
	int i;

	Alien::changeAnimation();

	if(Alien::isGoingDown()) {
		for(i = 0; i < NUMALIENS; ++i)
			((Alien *)_pieces[i])->moveDown();
	}
	else {
		if(Alien::isGoingRight())
			for(i = 0; i < NUMALIENS; ++i) {
				((Alien *)_pieces[i])->moveRight();
			}
		else
			for(i = 0; i < NUMALIENS; ++i) {
				((Alien *)_pieces[i])->moveLeft();
			}
	}
};

void GameState::animateBullets() {
	int i, j;
	for(i = 0; i < NUMBULLETS; ++i) {
		_bullets[i]->move();
	}
	for(i = 0; i < 11 ; ++i){
		for(j = 0; j < 2; ++j)
			_enemyBullets[i][j]->move();
	}
};

void GameState::newBullet() {
	int i;
	for(i = 0; i < NUMBULLETS; ++i)
		if(!_bullets[i]->isAlive()) {
			_bullets[i]->fire();
			break;
		}
};

void GameState::enemyFire() {
	int r;
	// escolhe o alien a disparar
	r = rand() % 11;
	// procura balas ainda nao disparadas
	while(true) {
		if(_enemyBullets[r][0]->isDepleted()) {
			++r;
			r %= 11;
			continue;
		}
		if(!_enemyBullets[r][0]->isAlive()) {
			_enemyBullets[r][0]->fire(); break;
		}
		else if(!_enemyBullets[r][1]->isAlive()) {
			_enemyBullets[r][1]->fire(); break;
		}
		else {
			++r;
			r %= 11;
			continue;
		}
	}
};