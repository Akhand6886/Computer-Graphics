#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
#include <math.h>

static GLfloat spin =0.0;
void init()
{
	glClearColor (0,0,0,0);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT); 
	glPushMatrix();
	glRotatef(spin,0.0,0.0,0.0);
	glColor3f(1,0,0);
	glRectf(-25.0, -25.0, 25.0, 25.0);
	glPopMatrix();
	//glutSwapBuffers();
	glFlush();
}
void spinDisplay()
{
	spin=spin + 0.1;
	if (spin > 360.0)
	{spin=0.0;}
	glutPostRedisplay();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1,0,1,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void mouse(int buton, int state, int x, int y)
{
	switch(buton){
case GLUT_LEFT_BUTTON:
	if (state==GLUT_DOWN)
		glutIdleFunc(spinDisplay);
	break;
case GLUT_RIGHT_BUTTON:
	glutIdleFunc(NULL);
default:glutIdleFunc(NULL);

	break;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600,600);
	//glutInitWindowPosition(50,50);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}