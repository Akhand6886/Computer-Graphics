#include <iostream>
#include <GL/glut.h>

using namespace std;



#define SPACE 32
#define ESC 27
int looptime = 60; // the delay required in the animation 
string s = "  ";
int scaleFactor = 3;
float radiusDifference = 0.5;  // this is factor by which radius will gradually change
int count = 0;  //to keep account of the number of lines SPACE is presssed




struct Point {
	int x;
	int y;
};

Point p1, p2;

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(1.0f);
}

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

	for(float i = 1; i <= step; i++) {
		glVertex2i(x1, y1);
		x1 += xInc;
		y1 += yInc;
	}
}

void draw_square(Point p1, Point p2) {
	GLint width = p2.x - p1.x;
	GLint height = p2.y - p1.y;

	Point p3 = {p1.x+width, p1.y},
		  p4 = {p1.x, p1.y+height};
	

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
		draw_dda(p1, p3);
		draw_dda(p3, p2);
		draw_dda(p2, p4);
		draw_dda(p4, p1);
	glEnd();
	glFlush();
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

void display() {}

void onMouseClick(int button, int state, int x, int y) {
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		p1.x = x;
		p1.y = 480 - y;
	}
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		p2.x = x;
		p2.y = 480 - y;
		draw_square(p2, p1);
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(400, 200);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("OpenGL");
	glutMouseFunc(onMouseClick);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}