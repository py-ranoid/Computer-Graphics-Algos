#include <iostream>
#include <glut/glut.h>
void myInit()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,800.0,0.0,480);
}

void myDisplay()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	int x1,x2,y1,y2;
	int temp;
	x1=200;y1=400;
	x2=20;y2=10;
	
	//x1=20;y1=10;
	//x2=200;y2=400;
	int del_x=x2-x1;
	int del_y=y2-y1;
	
	int p[1000];
	int slope;
	slope=del_y/del_x;
	if(slope>=0&&x2<x1)
	{
		temp=x2;
		x2=x1;
		x1=temp;
		temp=y2;
		y2=y1;
		y1=temp;
	}
	del_x=x2-x1;
	
	del_y=y2-y1;
	
	
	
	p[0]=(2*del_y)-del_x;
	
	int max=x2-x1;
	
	int x_k,y_k;
	if(p[0]>=0)
	{
		x_k=x1+1;
		y_k=y1+1;
	}
	else{
		x_k=x1+1;
		y_k=y1;
	}
	
	glVertex2d(x_k, y_k);
	
	glBegin(GL_POINTS);
	
	int k;
	for (k=1;k<max;k++) {
		
		p[k]= p[k-1] + ((2*del_y)-(2*del_x));

		if(p[k-1]>=0){
			
			glVertex2d(x_k+1,y_k+1);
			y_k=y_k+1;
		}
		else{
			p[k]=p[k]+(2*del_x);
			glVertex2d(x_k + 1, y_k);
			
		}
		x_k=x_k+1;
	
	}
	glEnd();
	glFlush();
}

int main(int argc,char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("EX - 2 (b)");
	
	glutInitWindowSize(800,600);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 1;
}
