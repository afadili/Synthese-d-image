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
		  glVertex2f(-0.5,-0.5);
		  glVertex2f(-0.5,0.5);
		  glVertex2f(0.5,0.5);
		  glVertex2f(0.5,-0.5);
		  glVertex2f(-0.5,-0.5);
		  glEnd();
	}
	else 
	{
		  glBegin(GL_POLYGON);
		  glVertex2f(-0.5,-0.5);
		  glVertex2f(-0.5,0.5);
		  glVertex2f(0.5,0.5);
		  glVertex2f(0.5,-0.5);
		  glVertex2f(-0.5,-0.5);
		  glEnd();
	}
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
    		glVertex2f(0.5*cos(i),0.5*sin(i));
  		 }
  		 glEnd();
  	}
  	else 
  	{
 		 glBegin(GL_POLYGON);
  		for (float i = 0; i < 6.28; i=i+0.1)
 		 {
    		glVertex2f(0.5*cos(i),0.5*sin(i));
  		 }
  		 glEnd();
  	}
}

int main ()
{
	pointListe liste = NULL;
  float x=0;
  float y=0;
  int bol=0,i=0;
  float a,b;
    //int x0, y0;

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
//int debut = 1;
glScalef(2.,2.,0);
    while(loop) {
    	Uint32 startTime = SDL_GetTicks();

      glClear(GL_COLOR_BUFFER_BIT); /*le dessin commence ici toujours avec cette fonction */



        glColor3ub(255,255,0);
        drawSquare(1);
        glColor3ub(255,0,255);
        drawCircle(1);
        drawLandmark();

        glTranslatef(1,2,0);
        glColor3ub(237,127,16);
        drawCircle(1);
        glTranslatef(-1,-2,0);
        glRotatef(45,0.0,0.0,1.0);
        glTranslatef(2,0,0);

        glColor3ub(255,0,0);
        drawSquare(1);
        glTranslatef(-2,0,0);
        glRotatef(45,0.0,0.0,-1.0);
        
        glTranslatef(2,0,0);
        glRotatef(45,0.0,0.0,1.0);
        glColor3ub(138,43,226);
        drawSquare(1);
        glRotatef(45,0.0,0.0,-1.0);
        glTranslatef(-2,0,0);

        glTranslatef(x,y,0);
        glRotatef(i,0.0,0.0,1.0);
        glColor3ub(255,255,0);
        drawSquare(1);
        glRotatef(i,0.0,0.0,-1.0);
        glTranslatef(-x,-y,0); 
        
        SDL_Delay(1000);
        a = rand()%16 -8;
        b = rand()%12 -6;
        glTranslatef(a,b,0);
        glColor3ub(0,0,255);
        drawCircle(1);
        glTranslatef(-a,-b,0);


       SDL_Event e;
        while(SDL_PollEvent(&e)) {
          if(e.type == SDL_QUIT) {
              loop = 0;
              break;
          }
          switch(e.type) {
            case SDL_MOUSEBUTTONUP:
                  bol = 0;

                  /*if (e.button.button == SDL_BUTTON_LEFT) {

                    allocpoint(&liste,e.button.x,e.button.y);
                    pointListe tmp = liste;
                    glColor3ub(255,255,255);
                    glBegin(GL_LINE_STRIP);
                    while (tmp != NULL)
                    {
                      glVertex2f(-1 + 2. * tmp->x/WINDOW_WIDTH,-(-1 + 2. * tmp->y/WINDOW_HEIGHT));
                          tmp = tmp->next;
                    }
                    glEnd();
                  }*/
                  break;
            case SDL_MOUSEBUTTONDOWN:
                  bol = 1;
                  break;

            case SDL_MOUSEMOTION:
                  if (bol == 1)
                  {
                    x = (-1 + 2. * e.button.x/WINDOW_WIDTH)*4 ;
                    y = -(-1 + 2. * e.button.y/WINDOW_HEIGHT)*4 ;
                    i++;
                  }
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