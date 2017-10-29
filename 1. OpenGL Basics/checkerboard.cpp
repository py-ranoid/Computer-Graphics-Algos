#include "GL/gl.h"
#include <iostream>
#include "GL/freeglut.h"

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	int k=0,i=0,j=0;
	while(j<=800)
	{
		while(i<=800)
		{
			glVertex2f(i,j);
			j+=100;
			glVertex2f(i,j);
			i+=100;
			glVertex2f(i,j);
			j-=100;
			glVertex2f(i,j);
			i+=100;
		}
		if((j/100)%2!=0)
			i=0;
		else
			i=100;
		j+=100;
	}

	glEnd();
	glFlush();
}

int main(int argc,char* argv[]) {
	glutInit(&argc,argv);
	glutInitWindowSize(600,600);
	glutCreateWindow("Checker Board");
	gluOrtho2D(0.0,800.0,0.0,800.0);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 1;
}
