
#include <stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<unistd.h>

float j=0;
int flag=0;

void init()
{
glClearColor(1,1,1,0.0);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_DEPTH_TEST);
glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
glShadeModel(GL_SMOOTH);

float lightpos[]={0,0,30,0};
glLightfv(GL_LIGHT0,GL_POSITION,lightpos);

float amb[4]={1,1,1,1};
glLightfv(GL_LIGHT0,GL_DIFFUSE,amb);

glMatrixMode(GL_PROJECTION|GL_MODELVIEW);
glLoadIdentity();
//glOrtho(-10,10,-10,10,-10,10);
gluPerspective(100,640/480,1,30);
gluLookAt(0,1,9,0.0,0.0,0.0,0.0,1.0,0.0);
glPointSize(5);
}

void drawrefx(double x, double y, double z){
    glVertex3d(-x,y,z);
}

 

void display()
{
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glColor3f(0,0,0);
glPushMatrix();
glRotatef(0.4,0,1,0);
glutSolidCube(2);
glRotatef(0.1,0,1,0);

glBegin(GL_POLYGON);
    glVertex3d(0,1,0);
    glVertex3d(1,1,2);
    glVertex3d(1,0,2);
    glVertex3d(0,0,0);
glEnd();
glutSolidCube(1);

glTranslatef(0,.4,0);

glutWireCube(5); glTranslatef(0,-.4,0);
 
glBegin(GL_POLYGON);
    glVertex3d(0,1.4,0);
    glVertex3d(.1,1.37,0);
    glVertex3d(.2,1.35,0);
    glVertex3d(.2,0,0);
    glVertex3d(0,0,0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3d(.2,1.35,0);
    glVertex3d(.4,2,0);
    glVertex3d(.5,1,0);
    glVertex3d(.5,-1,0);
    glVertex3d(.2,0,0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3d(0,0,0);
    glVertex3d(.6,0,0);
    glVertex3d(.5,-1,0);
    glVertex3d(0,-2,0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3d(0.3,0.9,0);
    glVertex3d(0.8,0.9,0);
    glVertex3d(1.1,-0.6,0);
    glVertex3d(0.5,-1,0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3d(0,0,0);
    glVertex3d(0.85,-.75,0);
    glVertex3d(0.4,-1.15,0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3d(0.8,0.9,0);
    glVertex3d(1.2,1,0);
    glVertex3d(2.35,-0.1,0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3d(0.8,0.9,0);
    glVertex3d(1.1,-0.6,0);
    glVertex3d(2.35,-0.1,0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3d(1.2,1,0);
    glVertex3d(1.4,1.1,0);
    glVertex3d(3.9,0,0);
    glVertex3d(2.35,-0.1,0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3d(1.4,1.1,0);
    glVertex3d(1.6,1.3,0);
    glVertex3d(4.15,0.5,0);
    glVertex3d(3.9,0,0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3d(1.6,1.3,0);
    glVertex3d(1.75,1.6,0);
    glVertex3d(4.4,0.85,0);
    glVertex3d(4.15,0.5,0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3d(1.75,1.6,0);
    glVertex3d(1.85,1.9,0);
    glVertex3d(5,1.3,0);
    glVertex3d(4.4,0.85,0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3d(1.85,1.9,0);
    glVertex3d(1.9,2.2,0);
    glVertex3d(7,2.2,0);
    glVertex3d(5,1.3,0);
glEnd();

//------------------------leftSIDE
glBegin(GL_POLYGON);
    drawrefx(0,1.4,0);
    drawrefx(.1,1.37,0);
    drawrefx(.2,1.35,0);
    drawrefx(.2,0,0);
    drawrefx(0,0,0);
glEnd();
glBegin(GL_POLYGON);
    drawrefx(.2,1.35,0);
    drawrefx(.4,2,0);
    drawrefx(.5,1,0);
    drawrefx(.5,-1,0);
    drawrefx(.2,0,0);
glEnd();
glBegin(GL_POLYGON);
    drawrefx(0,0,0);
    drawrefx(.6,0,0);
    drawrefx(.5,-1,0);
    drawrefx(0,-2,0);
glEnd();
glBegin(GL_POLYGON);
    drawrefx(0.3,0.9,0);
    drawrefx(0.8,0.9,0);
    drawrefx(1.1,-0.6,0);
    drawrefx(0.5,-1,0);
glEnd();
glBegin(GL_POLYGON);
    drawrefx(0,0,0);
    drawrefx(0.85,-.75,0);
    drawrefx(0.4,-1.15,0);
glEnd();
glBegin(GL_POLYGON);
    drawrefx(0.8,0.9,0);
    drawrefx(1.2,1,0);
    drawrefx(2.35,-0.1,0);
glEnd();
glBegin(GL_POLYGON);
    drawrefx(0.8,0.9,0);
    drawrefx(1.1,-0.6,0);
    drawrefx(2.35,-0.1,0);
glEnd();
glBegin(GL_POLYGON);
    drawrefx(1.2,1,0);
    drawrefx(1.4,1.1,0);
    drawrefx(3.9,0,0);
    drawrefx(2.35,-0.1,0);
glEnd();
glBegin(GL_POLYGON);
    drawrefx(1.4,1.1,0);
    drawrefx(1.6,1.3,0);
    drawrefx(4.15,0.5,0);
    drawrefx(3.9,0,0);
glEnd();
glBegin(GL_POLYGON);
    drawrefx(1.6,1.3,0);
    drawrefx(1.75,1.6,0);
    drawrefx(4.4,0.85,0);
    drawrefx(4.15,0.5,0);
glEnd();
glBegin(GL_POLYGON);
    drawrefx(1.75,1.6,0);
    drawrefx(1.85,1.9,0);
    drawrefx(5,1.3,0);
    drawrefx(4.4,0.85,0);
glEnd();
glBegin(GL_POLYGON);
    drawrefx(1.85,1.9,0);
    drawrefx(1.9,2.2,0);
    drawrefx(7,2.2,0);
    drawrefx(5,1.3,0);
glEnd();
 
glFlush();
glutSwapBuffers();
glutPostRedisplay();
}
 
int main(int argc, char ** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
glutInitWindowSize(700,700);
glutCreateWindow("Batman");
init();
glutDisplayFunc(display);
 
glutMainLoop();
return 0;
}