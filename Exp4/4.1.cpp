#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>

void display();
void printName();
void printSap();
void keyPress(unsigned char key, int x, int y);
void mouseClick(int button,int state,int x, int y);
void reshape(int, int);
void putPixel(int , int); //this is to "glow" the pixel decided by the bresenham algorithm
void bresenhamAlgo(int, int, int, int);
//before mouse clicks
int x_pos1=76, y_pos1=79, x_pos2=71, y_pos2=79; //76 and 79 are the coordinates of the top most point on the window
float m; //slope

void init(){ 
    glClearColor(0,0,0,0);
}

int main(int argc, char**argv){
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_RGB); 

    glutInitWindowPosition(0, 0); 
    glutInitWindowSize(1920, 950); 

    glutCreateWindow("Lab 4");
    
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPress);
    glutMouseFunc(mouseClick);
    
    init();
    glutMainLoop();
}
 
void putPixel(int x, int y){
    glPointSize(5.0);
    glBegin(GL_POINTS);
    if(m<1&&m>-1){
        glColor3f(1.0,0.0,0.0); // RED if slope of line is smaller than 1
    }
    else if(m>=1){
        glColor3f(0.0,1,0.0); // GREEN if slope of line equal to 1
    }
    else if(m<=-1){
        glColor3f(0.0,0.0,1.0);
    }

    glVertex2f(x, y);
    glEnd();
}

void bresenhamAlgo(int x_1, int y_1, int x_2, int y_2){
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x, y;
    dx = x_2 - x_1;
    dy = y_2 - y_1;
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    incx = 1;
    if (x_2 < x_1)
        incx = -1;
    incy = 1;
    if (y_2 < y_1)
        incy = -1;
    x = x_1;
    y = y_1;
    if (dx > dy)
    {
        putPixel(x, y);
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for (i = 0; i < dx; i++)
        {
            if (e >= 0)
            {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;
            putPixel(x, y);
        }
    }

    else
    {
        putPixel(x, y);
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        for (i = 0; i < dy; i++)
        {
            if (e >= 0)
            {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
            putPixel(x, y);
        }
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity(); 
    
    //put your stuff here
    
    bresenhamAlgo(x_pos1, y_pos1, x_pos2, y_pos2);
    printName();
    printSap();
    glFlush();
}

void reshape(int w, int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1920, 0, 950);
    glMatrixMode(GL_MODELVIEW);
}

void printName()
{
    //for printing name
    std::string s = "Ishan Rawat\n";
    glRasterPos2f(1440, 20);
    int n = s.size();
    for (int i = 0; i < n; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

void printSap(){
    std::string t="SAP ID: 500087524";
    glRasterPos2f(1650, 20);
    int o=t.size();
    for (int i = 0; i < o; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,t[i]);
    }
    glEnd();
    glFlush();
    glutSwapBuffers();

}

int vertex=1;
void keyPress(unsigned char key, int x, int y){
  if(key=='r'){
    x_pos1=0;
    y_pos1=0;
    x_pos2=0;
    y_pos2=0;
    vertex=1;
    glutPostRedisplay();
  }
  else if(key=='e'){
    exit(0);
    
  }
}
void mouseClick(int button,int state,int x, int y){
  y = 950-y;  
  if(button == GLUT_LEFT_BUTTON){
      if(vertex==1){
        x_pos1=x;
        y_pos1=y;
        vertex++;
      }
      else if(vertex==2){
        x_pos2=x;
        y_pos2=y;
    }
    float delta_y= y_pos2-y_pos1;
    float delta_x= x_pos2-x_pos1;
    if(delta_x==0){
        delta_x=1;
    }
    m = delta_y/delta_x;
    glutPostRedisplay();
  }
  else if(button == GLUT_RIGHT_BUTTON){
    
  }

}