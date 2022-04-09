#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>


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
    glClearColor(0,0,0,0);
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
    glutMouseFunc(mouseClick);
    init();
    glutMainLoop();
    

}
float x_pos1=0, y_pos1=0, x_pos2=0, y_pos2=0;
int m=0;

void display(){
    
    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity(); 

    //conditions on slope
    glPointSize(10.0);
    if(m==0){
        glColor3f(1.0,1.0,1.0);
    }
    else if(m>0&&m<100000){
        glColor3f(0.0,1.0,0.0);
    }
    else if(m<0){
        glColor3f(1.0,0.0,0.0);
    }
    glBegin(GL_LINES);
    glVertex2f(x_pos1,y_pos1);
    glVertex2f(x_pos2,y_pos2);
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
    std::string x = "Computer Graphic Lab Exp_3\n";
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


// mouse click input coordinate  code 

void mouseClick(int button,int state,int x, int y){
  x=(x-942)*20/1885;
  y=(478-y)*20/957;
  
  if(button == GLUT_LEFT_BUTTON){
      if(vertex==1){
        x_pos1=(float)x;
        y_pos1=(float)y;
        vertex++;
      }
      else if(vertex==2){
        x_pos2=(float)x;
        y_pos2=(float)y;
    }
    m = (y_pos2-y_pos1)/(x_pos2-x_pos1);
    glutPostRedisplay();
  }
  else if(button == GLUT_RIGHT_BUTTON){
    
  }

}