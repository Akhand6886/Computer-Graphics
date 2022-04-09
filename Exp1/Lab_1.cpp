#include<GL/gl.h>

#include<GL/glut.h>

#include<cstdio>

#include<cstring>

#include<cmath>

#include<iostream>



void myinit(void)

{

// glClearColor(0,0.75,1,0.0);

glClearColor(1,1,1,0.0);

glMatrixMode(GL_PROJECTION);

glLoadIdentity();

//glOrtho(0,0,0,0,0,-1);

}



void printName(){





//for printing name

std::string s="Pankaj Badoni";

glRasterPos2f(-0.98,0.8);



int n=s.size();

for(int i=0;i<n;i++)

glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);

glEnd();

glFlush();

glutSwapBuffers();

}



void display(){

glClear(GL_COLOR_BUFFER_BIT);

const int point1=0.3;





glColor3f(0.5,0.3,0.05);



//triangle

glBegin(GL_TRIANGLES);

glVertex2f(0.3, 0);

glVertex2f(-0.3, 0);

glVertex2f(0.0,0.75);

glEnd();



//lower square

glColor3f(0.05, 0.3, 0.5);

glBegin(GL_POLYGON);

glVertex3f (-0.3, 0, 0.0);

glVertex3f (0.3, 0, 0.0);

glVertex3f (0.3, -0.75, 0.0);

glVertex3f (-0.3, -0.75, 0.0);

glEnd();



//door

glColor3f(1, 1, 1);

glBegin(GL_POLYGON);

glVertex3f (-0.1, -0.25, 0.0);

glVertex3f (0.1, -0.25, 0.0);

glVertex3f (0.1, -0.75, 0.0);

glVertex3f (-0.1, -0.75, 0.0);

glEnd();

glColor3f(0, 0, 0);

glBegin(GL_LINES);

glVertex3f (0.1, -0.75, 0.0);

glVertex3f (-0.1, -0.75, 0.0);

glEnd();

// upper parallelogram

glColor3f(0.5,0.40,0.1);

glBegin(GL_POLYGON);

glVertex3f (0.0, 0.75, 0.0);

glVertex3f (0.5, 0.75, 0.0);

glVertex3f (0.8, 0, 0.0);

glVertex3f (0.3, 0, 0.0);

glEnd();

// rightside square

glColor3f(1, 0, 0.6);

glBegin(GL_POLYGON);

glVertex3f (0.8, 0, 0.0);

glVertex3f (0.8, -0.75, 0.0);

glVertex3f (0.3, -0.75, 0.0);

glVertex3f (0.3, 0, 0.0);

glEnd();

// window

glColor3f(0, 1,1);

glBegin(GL_POLYGON);

glVertex3f (0.7, -0.25, 0.0);

glVertex3f (0.7, -0.6, 0.0);

glVertex3f (0.45, -0.6, 0.0);

glVertex3f (0.45, -0.25, 0.0);

glEnd();

// lines of window

glColor3f(0, 0,0);

glBegin(GL_LINES);

glVertex3f ((0.7+0.45)/2, -0.25, 0.0);

glVertex3f ((0.7+0.45)/2, -0.6, 0.0);

glEnd();

glBegin(GL_LINES);

glVertex3f (0.45, -0.425, 0.0);

glVertex3f (0.7, -0.425, 0.0);

glEnd();

glFlush();

//for name

printName();



}

int main(int argc, char** argv){



glutInit(&argc, argv);

glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);



glutInitWindowSize(800,450);

glutInitWindowPosition(500,400);



glutCreateWindow("Hut-Pankaj Badoni");

myinit();



glutDisplayFunc(display);

glutMainLoop();

return EXIT_SUCCESS;

}