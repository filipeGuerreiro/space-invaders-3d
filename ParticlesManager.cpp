#include "ParticlesManager.h"

GLfloat ParticlesManager::_spec[] = {0.5f, 0.5f, 0.5f, 1.0f};
const GLfloat ParticlesManager::_shine[] = {20.0f};

ParticlesManager::ParticlesManager() {};

bool ParticlesManager::isRunning() {
	return _isRunning;
};

float ParticlesManager::getTime() {
	return _time;
}; 

void ParticlesManager::isRunning(bool b) {
	_isRunning = b;
};

void ParticlesManager::setTime(float t) {
	_time = t;
};

void ParticlesManager::init(Material *e) {
	float phi = (2*3.14)/AMOUNT;
	float theta = 3.14/(AMOUNT*10);

	this->setTime(50);
	this->isRunning(true);

	_dif[0] = e->getRed();		_amb[0] = e->getRed()/10;
	_dif[1] = e->getGreen();	_amb[1] = e->getGreen()/10;
	_dif[2] = e->getBlue();		_amb[2] = e->getBlue()/10;

	for(int i = 0; i < AMOUNT; i++) {

		_particles[i].position[0] = e->getX();
		_particles[i].position[1] = e->getY();
		_particles[i].position[2] = e->getZ();
	
		_particles[i].scale = 1;

		_particles[i].velocity[0] = 2.*rand()/RAND_MAX-1 + cos(phi*(i+1));
		_particles[i].velocity[1] = 2.*rand()/RAND_MAX-1 + sin(theta*(i+1));
		_particles[i].velocity[2] = 2.*rand()/RAND_MAX-1 + cos(theta*(i+1));

		_particles[i].color[0] = e->getRed();
		_particles[i].color[1] = e->getGreen();
		_particles[i].color[2] = e->getBlue();

		_particles[i].lifespan = 50;
	}
};

void ParticlesManager::update(Material *e, float elapsed) {
	_time -= elapsed;

	if(_time < 0) {
		this->setTime(0);
		this->isRunning(false);
	}
	// diminui progressivamente o tamanho do objecto
	e->setScale(e->getScale()*0.75);

	for(int i=0; i < AMOUNT; i++) {
		//
		if(_particles[i].velocity[2] < 0.5)
			_particles[i].velocity[2] = -1;

		_particles[i].velocity[0] *= 0.95;
		_particles[i].velocity[1] *= 0.95;
		_particles[i].velocity[2] *= 0.95;

		_particles[i].scale *= 0.95;
		_particles[i].lifespan -= elapsed;

		_particles[i].position[0] += _particles[i].velocity[0]*2;
		_particles[i].position[1] += _particles[i].velocity[1]*2;
		_particles[i].position[2] += _particles[i].velocity[2]*2;
	}
};

void ParticlesManager::draw() {
	
	for(int i = 0; i < AMOUNT; ++i) {

		if(_particles[i].lifespan < 0)
			continue;

		glPushMatrix();

			glTranslatef(_particles[i].position[0],_particles[i].position[1],_particles[i].position[2]);
			glRotatef(rand()%180,rand()%2,rand()%2,rand()%2);
			glScalef(_particles[i].scale,_particles[i].scale,_particles[i].scale);

			if(glIsEnabled(GL_LIGHTING)) {
				glMaterialfv(GL_FRONT, GL_DIFFUSE, _dif);
				glMaterialfv(GL_FRONT, GL_SPECULAR, _spec);
				glMaterialfv(GL_FRONT, GL_AMBIENT, _amb);
				glMaterialfv(GL_FRONT, GL_SHININESS, _shine);
			} else
				glColor3f(_particles[i].color[0], _particles[i].color[1], _particles[i].color[2]);

			glutSolidCube(SIZE);
		
		glPopMatrix();
	}
};