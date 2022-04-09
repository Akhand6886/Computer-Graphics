#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
#include <stdlib.h>

#include<unistd.h>


#define SPACE 32
#define ESC 27


void display();
void printlabname();
void printName();
void printSap();
void keyPress(unsigned char key, int x, int y);
void mouseClick(int button,int state,int x, int y);


void reshape(int, int);
void init(){ 
    //glClearColor(0.0,0.0,0.0,0.0);   
    glClearColor(1.0,1.0,1.0,0.0);
}
int main(int argc, char**argv){
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_RGB); 

    glutInitWindowPosition(200, 100); 
    glutInitWindowSize(500,500); 

    glutCreateWindow("Computer Graphic Lab Exp_3");
    
    glutDisplayFunc(display);
    
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPress);
    //glutMouseFunc(mouseClick);
    init();
    glutMainLoop();
    

}
void drawrefx(double x, double y, double z){
    glVertex3d(-x,y,z);
}


float x_pos1=0, y_pos1=0, x_pos2=0, y_pos2=0;
int m=0;

GLfloat ya = 50,xa = 10;
int yFlag = 1, xFlag = 1,AniFlag=1;

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


void display(){
 

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







    glFlush();
    //printing the name sap and lab on window
    glColor3f(0.988,0.729,0.011);
    printlabname(); 
    glColor3f(0.988,0.729,0.011);
    printName();
    glColor3f(0.988,0.729,0.011);
    printSap();
    
    
}

void reshape(int w, int h){
  
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
   
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}

void printlabname()
{
    //for printing lab name
    std::string x = "Computer Graphi LAB viva 2\n";
    glRasterPos2f(6, 9);
    int n = x.size();
    for (int i = 0; i < n; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, x[i]);
    glEnd();
    glFlush();
    glutSwapBuffers();
}
void printName()
{
    //for printing name
    std::string s = "Akhand Pratap Singh\n";
    glRasterPos2f(6, 8);
    int n = s.size();
    for (int i = 0; i < n; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

void printSap(){
    std::string t="SAP ID: 500085043";
    glRasterPos2f(6,7);
    int o=t.size();
    for (int i = 0; i < o; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,t[i]);
    }
    glEnd();
    glFlush();
    glutSwapBuffers();

}

// keyprees reset and exit code
int vertex=1;

void keyPress(unsigned char key, int x, int y){
  if(key==SPACE){
   x_pos1=0;
    y_pos1=0;
    x_pos2=0;
    y_pos2=0;
    vertex=1;
    glutPostRedisplay();
  }
  else if(key==ESC){
    //exit(0);
    glutDestroyWindow(1);
  }
}
