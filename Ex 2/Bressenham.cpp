#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include "math.h"
//#include<glut/glut.h>
using namespace std;
float xstart,xend,ystart,yend,m;
int l2r;
/*
   Window Size : 400 x 400
   Ortho Plane : 80 x 80
   Point Size : 5 x 5
 */
void myInit()
{
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.01);
        glPointSize(5);
        gluOrtho2D(0, 80, 0, 80);
}



void plotLine(float x1, float y1, float x2, float y2, int l2r = 1)
{
        // (x1,y1) - Start points
        // (x2,y2) - End points
        // m       - Slope
	float delx = float(x2 - x1);
	float dely = float(y2 - y1);
        float m = dely/delx;
	float p,p1,temp;

	if( m>=0 && x2 < x1)
	{
		// Switching Start and End points
		temp=x2;
		x2=x1;
		x1=temp;
		temp=y2;
		y2=y1;
		y1=temp;
		delx = x2 - x1;
		dely = y2 - y1;
	}
	float x = x1;
	float y = y1;
	p = 2 * dely - delx;

        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
	if (m<=1){
		glVertex2d(x1, y1);
		while(x <= x2 && y <= y2)
		{
			cout <<endl<<y<<" "<<x<<"\t"<<p;
			p1 = p + 2 * dely - 2* delx;
			x += 1;
			if( p > 0 ){
				glVertex2d(x, y);
				y = y+m;
			}
			else{
				p1 = p1 + 2*delx;
				glVertex2d(x, y);
			}
			p = p1;
		}
	}
	else
		cout << "Slope > 1 ?";
        glEnd();
        glFlush();
}

void func()
{
        plotLine(xstart, ystart, xend, yend,l2r);
        //plotLine(10, 30, 80, 5,0);
}

int main(int argc, char * argv[])
{
        cout << "Start points (0,0 - 100,100)\n";
        cout << "x: "; cin >> xstart;
        cout << "y: "; cin >> ystart;
        cout << "End points (0,0 - 100,100)\n";
        cout << "x: "; cin >> xend;
        cout << "y: "; cin >> yend;
        cout << "0.Right to Left\t\t1.Left to Right\n :";
        cin >> l2r;
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(400, 400);
        glutCreateWindow("Lines");
        myInit();
        glutDisplayFunc(func);
        glutMainLoop();
        return 1;
}
