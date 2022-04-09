#include <GL/glut.h>
#include <math.h>

#include <iostream>
using namespace std;




#define SPACE 32
#define ESC 27
int looptime = 60; // the delay required in the animation 
string s = "  ";
int scaleFactor = 3;
float radiusDifference = 0.5;  // this is factor by which radius will gradually change
int count = 0;  //to keep account of the number of lines SPACE is presssed



struct Point {
	GLint x;
	GLint y;
};

Point p1, p2;

void draw_dda(Point p1, Point p2) {
	GLfloat dx = p2.x - p1.x;
	GLfloat dy = p2.y - p1.y;

	GLfloat x1 = p1.x;
	GLfloat y1 = p1.y;

	GLfloat step = 0;

	if(abs(dx) > abs(dy)) {
		step = abs(dx);
	} else {
		step = abs(dy);
	}

	GLfloat xInc = dx/step;
	GLfloat yInc = dy/step;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for(float i = 1; i <= step; i++) {
		glVertex2i(x1, y1);
		x1 += xInc;
		y1 += yInc;
	}
	glEnd();
	glFlush();
}

void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		p1.x = x;
		p1.y = 480 - y;
	}
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		p2.x = x;
		p2.y = 480 - y;
		draw_dda(p1, p2);
	}
}


void keyPress(unsigned char key, int x, int y){
  if(key==SPACE){
    if (count%2==0){
      scaleFactor+=2;
      count++;
    }
    else{
      scaleFactor-=2;
      count--;
    }
  }
  else if(key==ESC){
    //exit(0);
    glutDestroyWindow(1);
  }
}



void init() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.5, 0.0,0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(2.0f);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

void display(void) {}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	
	
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(840, 680);
	glutCreateWindow("Mouse Func");
	
	glutDisplayFunc(display);
	glutMouseFunc(myMouseFunc);
	glutKeyboardFunc(keyPress);
	init();
	glutMainLoop();

	return 0;
}