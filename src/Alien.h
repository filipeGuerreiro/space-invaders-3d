#pragma once
#include "Material.h"
#include "ParticlesManager.h"

#define MOVE_X 1
#define MOVE_Y 5

#define X_MAX 45
#define Y_MAX -30

class Alien : public Material { 
	
public:
	Alien(float px, float py, float pz);
	Alien *getAlien();
	bool equals(Alien *);
	static void changeAnimation();
	static bool isGoingRight();
	static bool isGoingDown();
	bool hasBullets();
	void setBullets(bool);
	virtual void draw() =0;
	void moveLeft();
	void moveRight();
	void moveDown();
	virtual void firstAnimation() =0;
	virtual void secondAnimation() =0;
	void fire();
	void set3D(bool);
	void die();
	void updateExplosion(int);
	ParticlesManager *getExplosion();

protected:
	ParticlesManager *_explosion;
	bool _hasBullets;
	/* indica se deve usar o desenho 1 ou 2 para animar */
	static bool _animate;
	/* indica a direccao dos aliens, se true vai para direita, falso para esquerda */
	static bool _moveRight;
	/* indica se um alien chegou a ponta da tela */
	static bool _moveDown;
	// indica se a vista ÅEperspectiva ou nao (ortogonal)
	static bool _3D;
};
