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
    
void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
void init(void){ 
    //set the color of backgroud window to white 
    glClearColor(1.0,1.0,1.0,0.0);
}
//--------------------------------------------------------------------------
class Point {
public:
    float x, y;
    void setxy(float x2, float y2)
    {
        x = x2; y = y2;
    }
    //operator overloading for '=' sign
    const Point & operator=(const Point &rPoint)
    {
        x = rPoint.x;
        y = rPoint.y;
        return *this;
    }

};

int factorial(int n)
{
    if (n<=1)
        return(1);
    else
        n=n*factorial(n-1);
    return n;
}

float binomial_coff(float n,float k)
{
    float ans;
    ans = factorial(n) / (factorial(k)*factorial(n-k));
    return ans;
}


Point drawBezierGeneralized(Point PT[], double t) {
    Point P;
    P.x = 0;P.y=0;
    for(int i=0;i<clicks;i++)
    {
        P.x = P.x + binomial_coff((float)clicks,(float)i) * pow(t,(double)i) * pow((1-t),(clicks-i)) * PT[i].x;
        P.y = P.y + binomial_coff((float)clicks,(float)i) * pow(t,(double)i) * pow((1-t),(clicks-i)) * PT[i].y;
    }
    cout<<P.x<<endl<<P.y;
    cout<<endl<<endl;
    return P;
}/





//-------------------------------------------------------------------------

void Draw()
{
    GLfloat x[4],y[4];
    glClear(GL_COLOR_BUFFER_BIT);
    
    x[0] = 100; x[1] = 200; x[2] = 200;  x[3] = 300;
    x[0] = 450; x[1] = 450; x[2] = 450;  x[3] = 450
    
    for(i=0,t=0,c=0;t<1;i++,t=t+0.01)
    {
       xt[i] = pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
       yt[i] = pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
    }
      glPointsSize(3);    
      glBegin(GL_POINTS);
        for(i=0;i<200;i++)
        {
            glVertex2i(xt[i],y1t[i]);
            glVertex2i(xt[i],y2t[i]);
        }
    glEnd();
    glFlush();
 }





//-------------------------------------------------------------------------



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

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,500);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Bezier Curve");
    printSap();
    printName();
    //glutReshapeFunc(reshape);
    init();
    //glutMouseFunc(myMouse);
    glutKeyboardFunc(keyPress);
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}
