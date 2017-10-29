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
        glPointSize(2);
        gluOrtho2D(0, 300, 0, 300);
}
void switchpoints(int x1,int y1,int x2,int y2,int ch){
        
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
        cout << m ;
	if( m>=0 && x2 < x1)
	{
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
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        glVertex2d(x1, y1);
        //if (delx>=0 && dely>=0)
        int step = dely/abs(dely);
	if (abs(dely)<=abs(delx)){
                // |Slope| <= 1
                p = 2 * abs(dely) - abs(delx);
                for (x = x1; x <= x2; x++){
			p += 2 * abs(dely);
			if( p > 0 ){
                                p -= 2*abs(delx);
                                y += step;
			}
                        glVertex2d(x, y);
		}
	}
	else{
                // |Slope| > 1
                p = 2 * abs(dely) - abs(delx);
                for (y = y1; y <= y2; y++){
			p += 2 * abs(delx);
			if( p > 0 ){
                                p -= 2*abs(dely);
                                x += step;
			}
                        glVertex2d(x, y);
		}
        }
        /*
        else{
                if (dely<=delx){
                        //Positive Slope <= 1
                        p = 2 * dely - delx;
        		while(x <= x2)
        		{
        			cout <<endl<<y<<" "<<x<<"\t"<<p;
        			p += 2 * dely;
        			x += 1;
        			if( p > 0 ){
                                        p -= 2*delx;
                                        y = y+1;
        			}
                                glVertex2d(x, y);
        		}
        	}
        	else{
                        //Positive Slope > 1
                        p = 2 * delx - dely;
        		while(y <= y2)
        		{
        			cout <<endl<<y<<" "<<x<<"\t"<<p;
        			p += 2 * delx;
        			y += 1;
        			if( p > 0 ){
                                        p -= 2*dely;
                                        x += 1;
        			}
                                glVertex2d(x, y);
        		}
                }
        }*/
        glEnd();
        glFlush();

        glColor3f(1.0,1.0,0.0);
        glBegin(GL_LINES);
        glVertex2d(x1,y1+10);
        glVertex2d(x2,y2+10);
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
        glutInitWindowSize(600, 600);
        glutCreateWindow("Lines");
        myInit();
        glutDisplayFunc(func);
        glutMainLoop();
        return 1;
}
