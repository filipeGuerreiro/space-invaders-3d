#include "Hud.h"

Hud::Hud() {
	_lives = 3;
	_score = 0;
};

int Hud::getLives() {
	return _lives;
};

int Hud::getScore() {
	return _score;
};

void Hud::addScore(int s) {
	_score += s;
};

void Hud::takeLife() {
	--_lives;
};

void Hud::reset() {
	_lives = 3;
	_score = 0;
};

void Hud::message(std::string message, void *font, int x, int y) {
	glRasterPos2i(x, y);
	for(int i=0, j = message.length(); i < j; i++)
		glutBitmapCharacter(font, message[i]);
};

void Hud::draw(float w, float h) {

		float ratio = w/h;
		
		glDisable(GL_LIGHTING);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); 
		if(ratio > 1)
			gluOrtho2D(-VERTICAL*ratio, VERTICAL*ratio, -HORIZONTAL, HORIZONTAL);
		else
			gluOrtho2D(-VERTICAL, VERTICAL, -HORIZONTAL/ratio, HORIZONTAL/ratio);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glPushMatrix();
		
			glTranslatef(0.0, 0.0, 0.0);

			glColor3f(1.0, 1.0, 1.0);
			_snprintf_s(_text, sizeof(_text), 256, "SCORE: %04d", _score);
			message(_text, GLUT_BITMAP_HELVETICA_18, -45, 42.5);

			_snprintf_s(_text, sizeof(_text), 256, "LIVES: %d", _lives);
			message(_text, GLUT_BITMAP_HELVETICA_18, 28, 42.5);

		glPopMatrix();
	glEnable(GL_LIGHTING);
};

void Hud::youWin(float w, float h) {
	float ratio = w/h;
		
		glDisable(GL_LIGHTING);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); 
		if(ratio > 1)
			gluOrtho2D(-VERTICAL*ratio, VERTICAL*ratio, -HORIZONTAL, HORIZONTAL);
		else
			gluOrtho2D(-VERTICAL, VERTICAL, -HORIZONTAL/ratio, HORIZONTAL/ratio);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glPushMatrix();
		
			glTranslatef(0.0, 0.0, 0.0);

			glColor3f(1.0, 1.0, 1.0);
			_snprintf_s(_text, sizeof(_text), 256, "YOU WIN!");
			message(_text, GLUT_BITMAP_HELVETICA_18, -10., 0.);
			_snprintf_s(_text, sizeof(_text), 256, "PRESS S TO RESET");
			message(_text, GLUT_BITMAP_HELVETICA_18, -17., -5.);

		glPopMatrix();
	glEnable(GL_LIGHTING);
};

void Hud::youLose(float w, float h) {
		float ratio = w/h;
		
		glDisable(GL_LIGHTING);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); 
		if(ratio > 1)
			gluOrtho2D(-VERTICAL*ratio, VERTICAL*ratio, -HORIZONTAL, HORIZONTAL);
		else
			gluOrtho2D(-VERTICAL, VERTICAL, -HORIZONTAL/ratio, HORIZONTAL/ratio);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glPushMatrix();
		
			glTranslatef(0.0, 0.0, 0.0);

			glColor3f(1.0, 1.0, 1.0);
			_snprintf_s(_text, sizeof(_text), 256, "YOU LOSE!");
			message(_text, GLUT_BITMAP_HELVETICA_18, -10., 0.);
			_snprintf_s(_text, sizeof(_text), 256, "PRESS S TO RESET");
			message(_text, GLUT_BITMAP_HELVETICA_18, -17., -5.);

		glPopMatrix();
	glEnable(GL_LIGHTING);
};

GLuint Hud::loadTexture(const char * filename, int wrap, int w, int h) {
  BYTE * data;
  FILE * file;
  int width, height;
  GLuint texture;

  // Abrir o ficheiro
  file = fopen( filename, "rb" );
  if ( file == NULL ) return 0;

  // Alojar a memoria necessaria para o ficheiro
  width = w;
  height = h;
  data = (BYTE*)malloc( width * height * 3 );

  // Ler o ficheiro .raw
  fread( data, width * height * 3, 1, file );
  fclose( file );

  // Alojar o nome de ficheiro da textura
  glGenTextures( 1, &texture );

  // Selecionar a textura
  glBindTexture( GL_TEXTURE_2D, texture );

  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

  // Cria o MipMaps
  gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data );

  free( data );

  return texture;
};