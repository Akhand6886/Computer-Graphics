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

//glutReshapeFunc(reshape);
    
void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
void init(void){ 
    //set the color of backgroud window to white 
    glClearColor(1.0,1.0,1.0,0.0);
}


void Draw(){   
	glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity(); 
        GLfloat x[4], y[4]; // we will use this array to store our control points
        GLfloat xt[500], yt[500], t;
        int i;
    
   
   // we will specify our control points below.
    x[0] = 100; x[1] = 300; x[2] = 500; x[3] = 700;
    y[0] = 500; y[1] = 1000; y[2] = 100; y[3] = 500;

    

}
    
void display(){
    Draw();
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(1,1,0);
    int j;
    for(j=0;j<200;j++){
        glVertex2i(xt[j],yt[j]);
    }
    glEnd();
    glColor3f(0.988,0.729,0.011);
    printName();
    glColor3f(0.0,1.0,0.0);
    printSap();
    glFlush(); 
}

void drawLine(Point p1, Point p2) {
    glBegin(GL_LINES);
      glVertex2f(p1.x, p1.y);
      glVertex2f(p2.x, p2.y);
    glEnd();
    glFlush();
}
Point drawBezierGeneralized(Point PT[], double t) {
    Point P;
    P.x = 0;P.y=0;
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
    //for(int i=0;i<clicks;i++)
    //{
      //  P.x = P.x + binomial_coff((float)clicks,(float)i) * pow(t,(double)i) * pow((1-t),(clicks-i)) * PT[i].x;
        //P.y = P.y + binomial_coff((float)clicks,(float)i) * pow(t,(double)i) * pow((1-t),(clicks-i)) * PT[i].y;
    //}
    cout<<P.x<<endl<<P.y;
    cout<<endl<<endl;
    return P;
}

void beziercurvedraw{
for(double t = 0.0;t <= 1.0; t += 0.02)
        {
            Point p2 = drawBezierGeneralized(abc,t);
            cout<<p1.x<<"  ,  "<<p1.y<<endl;
            cout<<p2.x<<"  ,  "<<p2.y<<endl;
            cout<<endl;
            drawLine(p1, p2);
            p1 = p2;
        }
}
   
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,500);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Bezier Curve");
    
    //glutReshapeFunc(reshape);
 
    //glutMouseFunc(myMouse);
    glutKeyboardFunc(keyPress);
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}




