#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
#include <math.h>


#define SPACE 32
#define ESC 27

using namespace std;

//declaration for animations
GLfloat ya = 50,xa = 10;
int yFlag = 1, xFlag = 1,AniFlag=0;

static GLfloat spin =0.0;


void Animate(int x);

int vertex=1;
void display();
void printName();
void printSap();
void mouseClick(int button,int state,int x, int y);


void keyPress(unsigned char key, int x, int y);
float x_pos1=0, y_pos1=0, x_pos2=0, y_pos2=0;
/*
void keyPress(unsigned char key, int x, int y){
  // press space to reset |||| press ESC to exit the window
   
  if(key==SPACE){
       glutIdleFunc(Animate);
    glutPostRedisplay();
  }
  else if(key==ESC){
    glutDestroyWindow(1);
  }
}
*/



void Animate()
{
    if(AniFlag == 1)
    {
        if(ya>-50 && yFlag == 1)
            ya = ya - 0.2;

        if(ya<=-50 && yFlag == 1)
            yFlag = 0;

        if(ya<50 && yFlag == 0)
            ya = ya + 0.2;

        if(ya>=50 && yFlag == 0)
            yFlag = 1;


        if(xa>-10 && xFlag == 1)
            xa = xa - 0.2;

        if(xa<=-10 && xFlag == 1)
            xFlag = 0;

        if(xa<10 && xFlag == 0)
            xa = xa + 0.2;

        if(xa>=10 && xFlag == 0)
            xFlag = 1;
    }
    glutPostRedisplay();
}

void Draw()
{
    GLfloat x[4],y1[4],y2[4],y3[4],y4[4];
    GLdouble xt[200],y1t[200],y2t[200],y3t[200],y4t[200],t;
    int i,c;
    glClear(GL_COLOR_BUFFER_BIT);
    glRotatef(spin,0.0,0.0,0.0);

    x[0] = 150; x[1] = 250; x[2] = 250;  x[3] = 350-xa;
    y1[0] = 450; y1[1] = 450+ya; y1[2] = 450-ya;  y1[3] = 450;
    y2[0] = 400; y2[1] = 400+ya; y2[2] = 400-ya;  y2[3] = 400;
    y3[0] = 350; y3[1] = 350+ya; y3[2] = 350-ya;  y3[3] = 350;
    y4[0] = 300; y4[1] = 300+ya; y4[2] = 300-ya;  y4[3] = 300;

    for(i=0,t=0,c=0;t<1;i++,t=t+0.01)
    {
       xt[i] = pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
       y1t[i] = pow(1-t,3)*y1[0]+3*t*pow(1-t,2)*y1[1]+3*pow(t,2)*(1-t)*y1[2]+pow(t,3)*y1[3];
       y2t[i] = pow(1-t,3)*y2[0]+3*t*pow(1-t,2)*y2[1]+3*pow(t,2)*(1-t)*y2[2]+pow(t,3)*y2[3];
       y3t[i] = pow(1-t,3)*y3[0]+3*t*pow(1-t,2)*y3[1]+3*pow(t,2)*(1-t)*y3[2]+pow(t,3)*y3[3];
       y4t[i] = pow(1-t,3)*y4[0]+3*t*pow(1-t,2)*y4[1]+3*pow(t,2)*(1-t)*y4[2]+pow(t,3)*y4[3];
       c++;
    }

    glColor3f(1,0.25,0);
    glBegin(GL_QUAD_STRIP);
        for(i=0;i<c;i++)
        {
            glVertex2d(xt[i],y1t[i]);
           glVertex2d(xt[i],y2t[i]);
        }
    glEnd();
    

   glColor3f(1,1,1);
    glBegin(GL_QUAD_STRIP);
        for(i=0;i<c;i++)
        {
            glVertex2d(xt[i],y2t[i]);
            glVertex2d(xt[i],y3t[i]);
        }
    glEnd();

    glColor3f(0.1,0.5,0.1);
    glBegin(GL_QUAD_STRIP);
        for(i=0;i<c;i++)
        {
            glVertex2d(xt[i],y3t[i]);
            glVertex2d(xt[i],y4t[i]);
        }
    glEnd(); 
    glFlush();
}

void Menu(int n)
{
    if(n == 1)
        AniFlag = 1;
    else if(n == 2)
        AniFlag = 0;
    if(n == 3)
        exit(0);
    glutPostRedisplay();
}


///----------

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

///----------------

void MyInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,0.0);
 
    glutCreateMenu(Menu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argC,char *argV[])
{
    glutInit(&argC,argV);
    glutInitWindowSize(1024,700);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Animate Flag");
    
    MyInit();
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    //glutKeyboardFunc(keyPress);
    glutDisplayFunc(Draw);
    glutIdleFunc(Animate);
    glutMainLoop();
    
    return 0;
}