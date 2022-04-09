#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<cstring>
#include<cstdio>
#include<math.h>
#include<iostream>

void display();
void printName();
void printSap();

void reshape(int, int);
void init(){ 
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glLoadIdentity();
    glColor3f(0.0, 1.0, 0.0);
    gluOrtho2D(0, 1920, 0, 957);
    glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc, char**argv){
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_RGB); 

    glutInitWindowPosition(0, 0); 
    glutInitWindowSize(1920,957); 

    glutCreateWindow("window 1");
    
    glutDisplayFunc(display);
    
    glutReshapeFunc(reshape);

    init();
    glutMainLoop();
    

}

void display(){
    
    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity(); 
    GLfloat x[4], y[4]; // we will use this array to store our control points
    GLfloat xt[500], yt[500], t;
    int i;
    // we will specify our control points below.
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
    glFlush();
     
}

void reshape(int w, int h){
  
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
   
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0,1920,0,957);
    glMatrixMode(GL_MODELVIEW);
}

void printName()
{
    //for printing name
    std::string s = "Ishan Rawat\n";
    glRasterPos2f(1700, 900);
    int n = s.size();
    for (int i = 0; i < n; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

void printSap(){
    std::string t="SAP ID: 500087524";
    glRasterPos2f(1700,850);
    int o=t.size();
    for (int i = 0; i < o; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,t[i]);
    }
    glEnd();
    glFlush();
    glutSwapBuffers();

}

