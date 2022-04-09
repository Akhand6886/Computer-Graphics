#include<GL/gl.h>
#include<GL/glut.h>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>


#define SPACE 32
#define ESC 27


float xin, yin; //input points
float r; //radius
float a,b; //ellipse axis
int mainWindow, subWindow1, subWindow2;
void keyPress(unsigned char key, int x, int y);


void myinit(void)
{
	glClearColor(0.0f, 0.5f, 0.5f, 0.0f);
	glLoadIdentity();
	glColor3f(0.5f, 1.0f, 1.0f);
	gluOrtho2D(0,700,0,800);
	glClear(GL_COLOR_BUFFER_BIT);
}
void myinit1(void)
{
	glClearColor(0.5f, 1.0f, 1.0f,0.0);
	glLoadIdentity();
	gluOrtho2D(0,700,0,800);
	glClear(GL_COLOR_BUFFER_BIT);
}

void printName(){
	//for printing name and sap id
	std::string s="Akhand Pratap Singh";
	std::string s1="SAP ID - 500085043";

	glRasterPos2f(50,750);
	int n=s.size();
	for(int i=0;i<n;i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);

	glRasterPos2f(50,700);
	int n1=s1.size();
	for(int i=0;i<n1;i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s1[i]);
	
	glEnd();
	glFlush();
	glutSwapBuffers();
	}
	void draw_pixel(int x, int y) { //function to draw points
	glColor3f(1,0,0);
	glBegin(GL_POINTS);
	glVertex2i(x+xin, y+yin);
	glEnd();
}
	
  void draw_circle() { 
	r=50;
	int x = 0;
	int y = r;
	float p = 1.25 - r; // intial decision parameter at (0,r)
	draw_pixel(x, y);

	while (y > x) //to generate cirlce sector wise
	{	
		if (p < 0) //mid point is inside the circle
		{
			x++; 
			p += 2*x+1;
		}
	else //mid point is outside the cirlce
		{
			y--;
			x++;
			p += 2*(x-y)+1;
		}
		//for 8 sectors
		draw_pixel(x, y);
		draw_pixel(x, -y);
		draw_pixel(-x, y);
		draw_pixel(-x, -y);
		draw_pixel(y, x);
		draw_pixel(-y, x);
		draw_pixel(y, -x);
		draw_pixel(-y, -x);
	}
}


void draw_ellipse()
{
	a=70;
	b=50;
	float x = 0;
	float y = b;//(0,b)
    
	float dx = 2 * (b * b) * x;
	float dy = 2 * (a * a) * y;

	
	
//1st region of 1st quad m<-1


	float p1 = (b * b) - (a * a)* b + (a * a) * (0.25) ;
	while(dx < dy)
	{
       
		draw_pixel(+x, +y);
		draw_pixel(-x, +y);
		draw_pixel(+x, -y);
		draw_pixel(-x, -y);
	if(p1 < 0)
	{
		x++;
		dx = 2 * (b * b) * x;
		p1 += dx + (b * b);
	}
	else
	{
		x++;
		y--;
		dx =  2 * (b * b) * x;
		dy =  2 * (a * a) * y;
		p1 += dx - dy +(b * b);
	}
}

//2nd region of 1st quad m>-1
	float p2 = (b * b)*(x + 0.5)*(x + 0.5)+(a * a)*(y - 1)*(y - 1)-(a * a)*(b * b);
	
	while(y > 0)
	{
		draw_pixel(+x, +y);
		draw_pixel(-x, +y);
		draw_pixel(+x, -y);
		draw_pixel(-x, -y);
		if(p2 > 0)
		{
			x = x;
			y--;
			dy = 2 * (a * a) * y;
			p2 -= dy + (a * a);
		}	
	else
	{
		x++;
		y--;
		dy = dy - 2 * (a * a) ;
		dx = dx + 2 * (b * b) ;
		p2 += dx - dy + (a * a);
	}
}
}

void mouseClick(int button,int state,int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		xin = x;
		yin = 800-y;
		draw_ellipse();
		glutPostRedisplay();

		}
   }
   
void mouseClick1(int button,int state,int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		xin = x;
		yin = 800-y;
		draw_circle();
		glutPostRedisplay();
	}
}

void keyPress(unsigned char key, int x, int y){
  if(key==SPACE){
     glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
  }
  else if(key==ESC){
    //exit(0);
    glutDestroyWindow(1);
  }
}


void subwindow_1_display() {
	glColor3f(0.5,0.3,0.05);
	std::string c="Sub window 1 - Ecclipse";
	
	glRasterPos2f(50,650);
	int n=c.size();
	for(int i=0;i<n;i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c[i]);
	
	glutKeyboardFunc(keyPress);
	glColor3f(0.0f, 0.0f, 1.0f);//Blue
	printName();
	glFlush();
	
	}


void subwindow_2_display() {
	glColor3f(0.0f, 0.5f, 0.5f);//Blue-Green
	std::string e="Sub window 2 - Circle";

	glRasterPos2f(50,650);
	int n=e.size();	
	for(int i=0;i<n;i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,e[i]);
	printName();

	glFlush();
}





int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
//glutCreateWindow"Computer Graphics Viva 1";

	mainWindow = glutCreateWindow("Computer Graphics Viva 1");
//sub window1 (ellipse)


	subWindow1 = glutCreateSubWindow(mainWindow, 0,0,700,800);
	glutMouseFunc(mouseClick);
	glutKeyboardFunc(keyPress);
	glutDisplayFunc(subwindow_1_display);
	myinit();
	
//sub window2 (circle)

	subWindow2 = glutCreateSubWindow(mainWindow, 700,0,700,800);
	glutMouseFunc(mouseClick1);
	glutKeyboardFunc(keyPress);
	glutDisplayFunc(subwindow_2_display);
	myinit1();
	
	glutMainLoop();
	return EXIT_SUCCESS;
}
