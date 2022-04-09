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

int vertex=1;
void display();
void printName();
void printSap();
void mouseClick(int button,int state,int x, int y);


void keyPress(unsigned char key, int x, int y);
float x_pos1=0, y_pos1=0, x_pos2=0, y_pos2=0;

void keyPress(unsigned char key, int x, int y){
  // press space to reset |||| press ESC to exit the window
   
  if(key==SPACE){
   x_pos1=0;
    y_pos1=0;
    x_pos2=0;
    y_pos2=0;
    vertex=1;
    glutPostRedisplay();
  }
  else if(key==ESC){
    glutDestroyWindow(1);
  }
}
 
 
 
void display(){
   
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity(); 
    GLfloat x[4], y[4]; // we will use this array to store our control points
    GLfloat xt[500], yt[500], t;
    int i;
    	x[0] = 100; x[1] = 300; x[2] = 500; x[3] = 700;
    y[0] = 500; y[1] = 1000; y[2] = 100; y[3] = 500;

    for(i=0, t=0; t<=1; i++, t+=0.01){
        xt[i] = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] +3*pow(t,2)*(1-t)*x[2] +pow(t,3)*x[3];
        yt[i] = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] +3*pow(t,2)*(1-t)*y[2] +pow(t,3)*y[3];
    }
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(1,1,0);
    for(i=0;i<200;i++){
        glVertex2i(xt[i], yt[i]);
    }
    glEnd();
    
    glColor3f(0.988,0.729,0.011);
    printName();
    glColor3f(0.988,0.729,0.011);
    printSap();
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
  
void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glEnd();
    glFlush(); 
    glColor3f(0.988,0.729,0.011);
    printName();
    glColor3f(0.0,1.0,0.0);
    printSap();
 
}

void init(void){ 
    //set the color of backgroud window to white 
    glClearColor(1.0,1.0,1.0,0.0);
 
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,500);
    glutInitWindowPosition(100,150);
    glutCreateWindow("CG viva");
    
    //glutReshapeFunc(reshape);
    init();
    //glutMouseFunc(myMouse);
    glutKeyboardFunc(keyPress);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
