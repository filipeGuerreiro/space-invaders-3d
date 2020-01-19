#include "Background.h"

Background::Background() : Material(0.0, 0.0, 0.0) {

	_texture = loadTexture("textures/earth_space_400x400.raw", TRUE, W, H);

	diffuse[0] = 1.;
	diffuse[1] = 1.;
	diffuse[2] = 1.;
	diffuse[3] = 1.0;
	ambient[0] = 1.0;
	ambient[1] = 1.0;
	ambient[2] = 1.0;
	ambient[3] = 1.0;
	shininess[0] = 50; 
};

GLuint Background::loadTexture(const char * filename, int wrap, int width, int height) {
  BYTE * data;
  FILE * file;

  // Abrir o ficheiro
  file = fopen( filename, "rb" );
  if ( file == NULL ) return 0;

  // Alojar a memória necessária para o ficheiro
  width = 400;
  height = 400;
  data = (BYTE*)malloc( width * height * 3 );

  // Ler o ficheiro .raw
  fread( data, width * height * 3, 1, file );
  fclose( file );

  // Alojar o nome de ficheiro da textura
  glGenTextures( 1, &_texture );

  // Selecionar a textura
  glBindTexture( GL_TEXTURE_2D, _texture );

  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

  // Cria o MipMaps
  gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data );

  free( data );

  return _texture;
};

void Background::draw(){
	int i = 0, j = 0;
	// mapeamento do objecto
	float x, y;
	// mapeamento da textura
	float s, t;

	//_texture = SOIL_load_OGL_texture("textures/earth_space_400x400.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_DDS_LOAD_DIRECT);
    glBindTexture(GL_TEXTURE_2D, _texture);

	if(_texture == 0)
		printf("Could not find texture\n");
	
	glEnable(GL_TEXTURE_2D);

	glPushMatrix();

		if(glIsEnabled(GL_LIGHTING)) {
			glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
			glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
			glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
		} else
			glColor3f(1., 1., 1.);

		glTranslatef(_x, _y, _z);
		
		glBindTexture(GL_TEXTURE_2D, _texture);

		// comeca no canto superior esquerdo
		for(x = -W, y = -H, s = 0.0, t = 0.0; y < H; y += (H*2)/N_QUAD, t += 1.0/N_QUAD) {
			// mapeia linha a linha
			for(x = -W, s = 0.0; x < W; x += (W*2)/N_QUAD, s += 1/N_QUAD) {
				glBegin(GL_POLYGON);
					// desenha anti-clockwise
					glNormal3f(0.0, 0.0, 1.0);
					glTexCoord2f(s, t);
					glVertex3f(x, y, D);
					glTexCoord2f(s + 1.0/N_QUAD, t);
					glVertex3f(x + (2.0*W)/N_QUAD, y, D);
					glTexCoord2f(s + 1.0/N_QUAD, t + 1.0/N_QUAD);
					glVertex3f(x + (2.0*W)/N_QUAD, y + (2.0*H)/N_QUAD, D);
					glTexCoord2f(s, t + 1.0/N_QUAD);
					glVertex3f(x, y + (2.0*H)/N_QUAD, D);
				glEnd();
			}
		}

		glDisable(GL_TEXTURE_2D);
		
	glPopMatrix();
};