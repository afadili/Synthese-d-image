#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<math.h>


static unsigned int WINDOW_WIDTH = 800;
static unsigned int WINDOW_HEIGHT = 800;

typedef struct point
{
	int x,y;
	struct point* next;
}point, *pointListe;

static const unsigned int BIT_PER_PIXEL = 32;
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

/* fonction qui actualise l'affichage lors d'un redimensionnement */

void windowUpdate() {
  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-8., 8., -8., 8.);
  SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_RESIZABLE);
}

/* fonction alooc point */
void allocpoint(pointListe *liste, float x, float y)
{
	pointListe tmp;
	tmp = (point*)malloc(sizeof(point));
	if (tmp != NULL)
	{
		tmp->x = x;
		tmp->y = y;
		tmp->next = NULL;
	}
	tmp->next = *liste;
	*liste = tmp;
}

/* Fonction qui dessine un carré */
void drawSquare(int full)
{
	if (full == 0)
	{
		  glBegin(GL_LINE_STRIP);

	}
	else 
	{
		  glBegin(GL_POLYGON);

	}
	glVertex2f(-0.5,-0.5);
	glVertex2f(-0.5,0.5);
	glVertex2f(0.5,0.5);
	glVertex2f(0.5,-0.5);
	glVertex2f(-0.5,-0.5);
	glEnd();
}

/* fonction qui dessine un repère */

void drawLandmark()
{
  glColor3ub(0,255,0);
  glBegin(GL_LINES);
  glVertex2f(-8,0);
  glVertex2f(8,0);
  glEnd();
  glColor3ub(0,0,255);
  glBegin(GL_LINES);
  glVertex2f(0,6);
  glVertex2f(0,-6);
  glEnd();
}

/* fonctio qui dessine un cercle */

void drawCircle(int full)
{
	if (full == 0)
	{
 		 glBegin(GL_LINE_STRIP);
  		for (float i = 0; i < 6.28; i=i+0.1)
 		 {
    		glVertex2f(0.25*cos(i),0.25*sin(i));
  		 }
  		 glEnd();
  	}
  	else 
  	{
 		 glBegin(GL_POLYGON);
  		for (float i = 0; i < 6.28; i=i+0.1)
 		 {
    		glVertex2f(0.25*cos(i),0.25*sin(i));
  		 }
  		 glEnd();
  	}
}

/* fonction drawRoundedSquare */
void drawRoundedSquare()
{
		glPushMatrix();
    	glColor3ub(255,255,255);
		glScalef(0.5,1,1);
		drawSquare(0);
		glPopMatrix();
		glPushMatrix();
    	glColor3ub(255,255,255);
		glScalef(1,0.5,1);
		drawSquare(0);
		glPopMatrix();
		glPushMatrix();
		glColor3ub(255,255,255);
		glTranslatef(0.25,0.25,0);
		drawCircle(0);
		glPopMatrix();
		glPushMatrix();
		glColor3ub(255,255,255);
		glTranslatef(0.25,-0.25,0);
		drawCircle(0);
		glPopMatrix();
		glPushMatrix();
		glColor3ub(255,255,255);
		glTranslatef(-0.25,0.25,0);
		drawCircle(0);
		glPopMatrix();
		glPushMatrix();
		glColor3ub(255,255,255);
		glTranslatef(-0.25,-0.25,0);
		drawCircle(0);
		glPopMatrix();
}
 /* fonction drawFirstArm */
void drawFirstArm()
{
	glColor3ub(255,255,255);
		drawCircle(0);

		glPushMatrix();
		glColor3ub(255,255,255);
		glTranslatef(-6,0,0);
		glScalef(2,2,1);
		drawCircle(0);
		glPopMatrix();

		glBegin(GL_LINE_STRIP);
		glColor3ub(255,255,255);
		glVertex2f(-6,0.5); // coté droit
		glVertex2f(0,0.25);
		glVertex2f(0,-0.25);
		glVertex2f(-6,-0.5); 
		glVertex2f(-6,0.5);
		glEnd();

}
/* fonction drawSecondArm() */
void drawSecondArm()
{
    	drawRoundedSquare();
    	glPushMatrix();
		glTranslatef(-4.6,0,0);
		drawRoundedSquare();
		glPopMatrix();
		glBegin(GL_LINE_STRIP);
		glColor3ub(255,255,255);
		glVertex2f(-4.9,0.35); // coté droit
		glVertex2f(0.35,0.35);
		glVertex2f(0.35,-0.35);
		glVertex2f(-4.9,-0.35); 
		glVertex2f(-4.9,0.35);
		glEnd();
}

void drawThirdArm()
{
	drawRoundedSquare();
    	glPushMatrix();
		glTranslatef(3,0,0);
		glScalef(2,2,1);
		drawCircle(1);
		glPopMatrix();
		glBegin(GL_LINE_STRIP);
		glColor3ub(255,255,255);
		glVertex2f(3,0.35); // coté droit
		glVertex2f(0,0.35);
		glVertex2f(0,-0.35);
		glVertex2f(3,-0.35); 
		glVertex2f(3,0.35);
		glEnd();
}

int main ()
{
	pointListe liste = NULL;
  float x=0;
  float y=0;
  int bol=0,i=0;
  float a,b;


	 if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,0);

    if(NULL == SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_RESIZABLE)) {
        fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
        return EXIT_FAILURE;
    }
SDL_WM_SetCaption("TP 2 synthèse d'image", NULL);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  windowUpdate();

int loop = 1;
int gamma, beta, alpha;
    while(loop) {
    	Uint32 startTime = SDL_GetTicks();

      glClear(GL_COLOR_BUFFER_BIT); /*le dessin commence ici toujours avec cette fonction */

  	for (int i=0; i<20; i++)
  	{  	
    	drawRoundedSquare();
    	glPushMatrix();
    	glRotatef(alpha,0,0,1);
    	drawFirstArm();
    	glPopMatrix();
    	glPushMatrix();
    	
    	glTranslatef(4.6,0,0);
    	glRotatef(beta,0,0,1);
    	drawSecondArm();
    	glPopMatrix();
		glPushMatrix();

    	glTranslatef(4.6,0,0);
    	glRotatef(gamma,0,0,1);
    	drawThirdArm();
    	glPopMatrix();

    	alpha++;
    	beta++;
    	gamma++;
    }

       SDL_Event e;
        while(SDL_PollEvent(&e)) {
          if(e.type == SDL_QUIT) {
              loop = 0;
              break;
          }
          switch(e.type) {
            case SDL_MOUSEBUTTONUP:
                  break;
            case SDL_MOUSEBUTTONDOWN:
                  break;

            case SDL_MOUSEMOTION:

                  break;
            case SDL_VIDEORESIZE:
                WINDOW_WIDTH = e.resize.w;
                WINDOW_HEIGHT = e.resize.h;
                windowUpdate();
                break;

          }
            
        }


    	 SDL_GL_SwapBuffers();/* le dessin termine toujours avec cette fonction */
    }
}