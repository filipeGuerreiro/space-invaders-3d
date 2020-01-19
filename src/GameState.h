#pragma once

#include <time.h>     /* time */
#include <stdio.h>

#include "CoolAlien.h"
#include "SquidAlien.h"
#include "SkullAlien.h"
#include "Shield.h"
#include "Ship.h"
#include "Bullet.h"
#include "AlienBullet.h"
#include "CameraOrtogonal.h"
#include "CameraFirstPerson.h"
#include "CameraThirdPerson.h"
#include "DirectionalLight.h"
#include "Headlight.h"
#include "Background.h"
#include "ParticlesManager.h"
#include "Hud.h"

#define ROWS 5

#define NUMALIENS 55
#define NUMSHIELDS 4
#define NUMCAMERAS 3
#define NUMBULLETS 5

#define X_DIST 8
#define Y_DIST 7
#define DIST_ESC 23.5

#define ORTHO 1
#define FIRST_P 2
#define THIRD_P 3

class GameState {

public:
	static GameState *getState();
	static bool isRunning();
	static void isRunning(bool);
	int getScore();
	int getLives();
	Entity *getPiece(int);
	Bullet *getBullet(int);
	AlienBullet *getEnemyBullets(int, int);
	Hud *getHud();
	void reset();
	void setCamera(int);
	void setLightSource(int);
	void drawAll();
	void initPecas();
	void moveAliens();
	void animateAliens();
	void animateBullets();
	void newBullet();
	void enemyFire();
	void debug();
	void updateExplosions(int);

private:
	GameState();
	static GameState *_state;
	int _activeCamera;
	int _luzActiva;
	// devolve nao se o jogo tiver parado e sim caso contrario
	static bool _isRunning;
	Entity *_pieces[NUMALIENS+NUMSHIELDS+NUMCAMERAS+1];
	Hud *_hud;
	Background *_pf;
	Bullet *_bullets[NUMBULLETS];
	// 1- luz direccional, 2- spotlight
	LightSource *_luzes[2];
	// aliens with the ability to fire
	Alien *_firingSquad[11];
	// and their bullets
	AlienBullet *_enemyBullets[11][2];
};