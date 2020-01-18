#include "GameState.h"
#include "CollisionsManager.h"
#include "ParticlesManager.h"
#include "glut/include/GL/glut.h"

void myDisplay(void);
void myReshape(GLsizei w, GLsizei h);
void myDraw();
void myKeyboardFunc(unsigned char key, int x, int y);
void mySpecialKeyboardFunc(int key, int x, int y);
void alienTimer(int v);
void bulletTimer(int v);
void randTimer(int v);
void explosionTimer(int v);

float zeroAmb[] = {0.0, 0.0, 0.0, 1.0};
ParticlesManager *_particlesManager = new ParticlesManager();

int main(int argc, char** argv) {
	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize (450, 450);
	glutInitWindowPosition (-1, -1);
	glutCreateWindow("Space Invaders 3D");
	glEnable(GL_DEPTH_TEST);
	GameState::getState()->initPecas();
	CollisionManager::getManager()->init();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_NORMALIZE);
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutKeyboardFunc(myKeyboardFunc);
	glutSpecialFunc(mySpecialKeyboardFunc);
	glutTimerFunc(1000, alienTimer, 0);
	glutTimerFunc(50, bulletTimer, 0);
	glutTimerFunc(1000, randTimer, 0);
	glutTimerFunc(300, explosionTimer, 0);
	glutMainLoop();
	return 0;
}


void myDisplay() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	myDraw();
	glutSwapBuffers();
}

void myReshape(GLsizei w, GLsizei h)  {
	Camera::setWidth((float)w);
	Camera::setHeight((float)h);
}

void myDraw() { 
	GameState::getState()->drawAll();
}

void myKeyboardFunc(unsigned char key, int x, int y) {
	switch((int)key) {
		case ' ' : if(GameState::isRunning()) { GameState::getState()->newBullet(); } break;
		case 'd' : GameState::getState()->debug(); break;
		case 's' : if(!GameState::isRunning() && (GameState::getState()->getScore() == 5500 || GameState::getState()->getLives() < 1)) {
					   GameState::isRunning(!GameState::isRunning());
					   GameState::getState()->reset();
				   }
				   break;
		default  : GameState::getState()->setCamera((int)key-'0');
	}
}

void mySpecialKeyboardFunc(int key, int x, int y) {
	Ship* n = Ship::getShip();
	if(GameState::isRunning()) {
		switch(key) {
			case GLUT_KEY_F1:
				GameState::getState()->setLightSource(0);
				break;
			case GLUT_KEY_F2:
				GameState::getState()->setLightSource(1);
				break;
			case GLUT_KEY_F3:
				glDisable(GL_LIGHT0);
				glDisable(GL_LIGHT1);
				glLightModelfv(GL_LIGHT_MODEL_AMBIENT, zeroAmb);
				break;
			case GLUT_KEY_LEFT:
				n->moveLeft();
				break;
			case GLUT_KEY_RIGHT:
				n->moveRight();
		}
	}

	glutPostRedisplay();
}

void alienTimer(int value) {
	if(GameState::isRunning()) {
		GameState::getState()->animateAliens();
	}

	glutPostRedisplay();
	glutTimerFunc(1000, alienTimer, 0);
}

void bulletTimer(int value) {
	if(GameState::isRunning()) {
		GameState::getState()->animateBullets();
		CollisionManager::getManager()->calculateCollisions();
	}
	glutPostRedisplay();
	glutTimerFunc(50, bulletTimer, 0);
}

void randTimer(int value) {
	if(GameState::isRunning()) {
		int x = rand() % 100;
		if(x > 10) // frequency
			// fire bullet 
			GameState::getState()->enemyFire();
	}
	glutTimerFunc(1000, randTimer, 0);
}

void explosionTimer(int v) {
	if(GameState::isRunning()) {
		GameState::getState()->updateExplosions(1.);
	}
	glutPostRedisplay();
	glutTimerFunc(50, explosionTimer, 0);
};