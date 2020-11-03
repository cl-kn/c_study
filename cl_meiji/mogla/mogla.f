/* mogla.f: ver.0911181 */

#include <windows.h>
#include <math.h>

#pragma comment (lib, "winmm.lib")     /* link MultiMedia	*/
#pragma comment (lib, "opengl32.lib")  /* link OpenGL		*/
#pragma comment (lib, "glu32.lib")     /* link glu		*/
#pragma comment (lib, "glut32.lib")    /* link glut		*/

#include "glut.h"

#define M_RAD	0.01745329252		/* pi/180.0 */

#define gl_clearbuffer()		glClear(0x00004000);	/* sgl|dle */
#define gl_displayfunc(func)		glutDisplayFunc(func)
#define gl_loop()			glutMainLoop()
#define gl_flush()			glFlush()

int	perif_div=60;
double	half_dv=30.0;
double	_Width_Height_size=256.0;
double	_Fvy=60.0, _zNr=1.0, _zFr=20.0;	/* perspective values */

void color16(int c){
	switch(c){
		case  0: glColor3d(0.0,0.0,0.0); break;	  /* black */
		case  1: glColor3d(0.0,0.0,0.5); break;	  /* dark_blue */
		case  2: glColor3d(0.8,0.3,0.2); break;	  /* brown */
		case  3: glColor3d(0.5,0.0,0.5); break;	  /* dark_magnt*/
		case  4: glColor3d(0.0,0.5,0.0); break;	  /* dark_green*/
		case  5: glColor3d(0.0,0.5,0.5); break;	  /* dark_cyan */
		case  6: glColor3d(0.5,0.5,0.0); break;	  /* dark_yelw */
		case  7: glColor3d(0.5,0.5,0.5); break;	  /* dark_gray */
		case  8: glColor3d(0.7,0.7,0.7); break;	  /* gray */
		case  9: glColor3d(0.0,0.0,1.0); break;	  /* blue */
		case 10: glColor3d(1.0,0.0,0.0); break;   /* red */
		case 11: glColor3d(1.0,0.0,1.0); break;   /* magenta */
		case 12: glColor3d(0.0,1.0,0.0); break;	  /* green */
		case 13: glColor3d(0.0,1.0,1.0); break;   /* cyan */
		case 14: glColor3d(1.0,1.0,0.0); break;	  /* yellow */
		case 15: glColor3d(1.0,1.0,1.0); break;	  /* white */
		default: glColor3d(1.0,1.0,1.0);
	}
}

void pset(double x1,double y1,int c){
	color16(c);
	glBegin(GL_POINTS);
	glVertex2d( x1,y1 );
	glEnd();
}

void line(double x1,double y1,double x2,double y2,int c){ 
	color16(c);
	glBegin(GL_LINES);
	glVertex2d( x1,y1 );
	glVertex2d( x2,y2 );
	glEnd();
}

void box(double x1, double y1, double x2, double y2, int c){
/* NOT PAINTED */
	color16(c);
	glBegin(GL_LINE_LOOP);
	glVertex2d(x1,y1);	glVertex2d(x2,y1);
	glVertex2d(x2,y2);	glVertex2d(x1,y2);
	glEnd();
}

void circle(double xc,double yc, double r, int c){
/* NOT PAINTED */
	double xx,yy,rad;
	int j;

	rad=M_PI/half_dv;

	color16(c);
	glBegin(GL_LINE_LOOP);
	for(j=0; j<=perif_div; j++){
		xx=xc+r*cos(rad*j);	yy=yc+r*sin(rad*j);
		glVertex2d(xx,yy);
	}
	glEnd();
}

void  ortho_window(int wide, int hite){
	double ss=_Width_Height_size; 
	glViewport(0,0,wide,hite);	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(wide<=hite)glOrtho(-ss,ss,-ss*(GLdouble)hite/(GLdouble)
		wide,ss*(GLdouble)hite/(GLdouble)wide, -ss, ss);
	else glOrtho(-ss*(GLdouble)wide/(GLdouble)hite,
		ss*(GLdouble)wide/(GLdouble)hite,-ss,ss,-ss,ss);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void  perspect_window(int wide, int hite){
	glViewport(0,0,wide,hite);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_Fvy,(GLfloat)wide/(GLfloat)hite,_zNr,_zFr);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void reshapefunc(int op){
	if(op==1) glutReshapeFunc(ortho_window);
	if(op==2) glutReshapeFunc(perspect_window);
}

void gl_int(int rx, int ry){
	glutInitDisplayMode(0|0);		/* sngl,rgb */
	glutInitWindowPosition(0,0);		/* origin:0,0 */
	glutInitWindowSize(rx, ry);		/* int:x,y:512,512 */
	glutCreateWindow( "Mogra_OpenGL" );	/* open the named window */
	glClearColor(0.0,0.0,0.0,1.0);		/* clear with black */
	glClear(GL_COLOR_BUFFER_BIT);		/* clear Window */
	glColor3d(1.0,1.0,1.0);			/* default draw_color: white */
	glShadeModel(GL_FLAT);			/* or GL_SMOOTH */
	reshapefunc(1);
}
