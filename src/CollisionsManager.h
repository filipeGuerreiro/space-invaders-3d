#pragma once

#include "GameState.h"

#define KILL_SCORE 100

class CollisionManager {

public:
	static CollisionManager *getManager();
	void init();
	void calculateCollisions();
	bool _hasCollisions;

private:
	static CollisionManager *_COLISOES;
	CollisionManager();
	Hud *_hud;
	Ship *_n;
	Alien *_aliens[NUMALIENS];
	Shield *_escudos[NUMSHIELDS];
	Bullet *_bullets[NUMBULLETS];
	AlienBullet *_balasAlien[11][2];
	void bulletAlienCollision();
	void bulletShieldCollision();
	void alienBulletsShip();
	void alienBulletsShield();
	void alienShield();
	void alienShip();
	void shipBulletsCollision();
	void alienBulletsCollision();
	void alienCollisions();
};