#include<GL/gl.h>

#include<GL/glut.h>

#include<iostream>

using namespace std;


void myInit(void)
{
	
	glClearColor(1.0, 0.5, 0.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void myDisplay(void)      
{	
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(4.0);
	
	// Rectangular part of hut
	glColor3f(0.5f, 0.0f, 1.0f);


	glBegin(GL_POLYGON);

	glVertex2i(40, 40);
	glVertex2i(320, 40);

	glVertex2i(40, 200);
	glVertex2i(320, 200);

	glVertex2i(40, 200);
	glVertex2i(40, 40);

	glVertex2i(320, 200);
	glVertex2i(320, 40);

	glEnd();

	// Right Window 
	glColor3f(1.0f, 1.1f, 0.0f);


	glBegin(GL_POLYGON);


	glVertex2i(220, 60);
	glVertex2i(300, 60);

	glVertex2i(220, 150);
	glVertex2i(300, 150);

	glVertex2i(220, 60);
	glVertex2i(220, 150);

	glVertex2i(300, 150);
	glVertex2i(300, 60);

	glEnd();

	// Right Window part 2
	glColor3f(0.1f, 0.f, 0.1f);

	
	glBegin(GL_POLYGON);

	
	glVertex2f(220, 170);
	glVertex2f(300, 170);

	glVertex2f(220, 190);
	glVertex2f(300, 190);

	glVertex2f(220, 170);
	glVertex2f(220, 190);

	glVertex2f(300, 190);
	glVertex2f(300, 170);

	glEnd();

	// Door  of hut
  	glColor3f(0, 1, 0);

	
	glBegin(GL_POLYGON);

	
	glVertex2f(130, 40);
	glVertex2f(130, 160);

	glVertex2f(130, 160);
	glVertex2f(180, 160);

	glVertex2f(180, 100);
	glVertex2f(180, 40);

	glVertex2f(120, 40);
	glVertex2f(170, 40);

	glEnd();

	// Create Door Part 2
	glColor3f(0.1f, 0.2f, 0.1f);

	glBegin(GL_POLYGON);


	glVertex2f(130, 170);
	glVertex2f(130, 180);

	glVertex2f(130, 180);
	glVertex2f(180, 180);

	glVertex2f(180, 170);
	glVertex2f(180, 180);

	glVertex2f(130, 170);
	glVertex2f(180, 170);

	glEnd();

	// Hut's top triangle part
	
	glBegin(GL_POLYGON);

	glColor3f(1, 0, 0); glVertex2f(100, 200);
	glColor3f(0, 0, 1);glVertex2f(340, 200);

	glColor3f(0, 1, 0);glVertex2f(200, 390);

	glColor3f(0, 0, 1);glVertex2f(10, 200);
	glColor3f(1, 0, 1);glVertex2f(200, 390);

	glEnd();

	// Sends all output to display
	glFlush();
	
}

// Driver Code

int main(int argc, char** argv)
{
	
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(1200, 740);

	
	glutInitWindowPosition(500, 400);

	glutCreateWindow("Akhand Pratap Singh  500085043");

	glutDisplayFunc(myDisplay);
	myInit();

	glutMainLoop();

	return 0;
}

