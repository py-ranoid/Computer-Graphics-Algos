#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <iostream>

using namespace std;

#define MAX 900.0f
#define BALLRADIUS 18
void init() {
	glClearColor(1.0, 1.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.5f);
	gluOrtho2D(0, MAX, 0, MAX*2);
}

float circlefunc(float x,float y,float r){
    //return pow(x + 1.0,2) + pow(y + 0.5,2) - pow(y + 0.5,2);
    float val = pow(x + 1.0,2) + pow(y - 0.5,2) - pow(r,2);
    return val;
}

void plotCircle(float xc, float yc, float r)
{
        //glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        float x = 0.0;
        float y = r-1;
        float p;
        for (;x<=y;x++)
        {
                p = circlefunc(x,y,r);
                if ( p < 0){
                        //x = x + 1;
                        y = y;
                }
                else{
                        //x = x + 1;
                        y = y - 1;
                }
                glVertex2d(xc + x,yc + y);
                glVertex2d(xc + x,yc - y);
                glVertex2d(xc - x,yc + y);
                glVertex2d(xc - x,yc - y);
                glVertex2d(xc + y,yc + x);
                glVertex2d(xc + y,yc - x);
                glVertex2d(xc - y,yc + x);
                glVertex2d(xc - y,yc - x);

        }
        glEnd();
        glFlush();
}

float x=MAX/4+100,y=MAX/2;
float horizontal_velocity = -0.2;
float vertical_velocity = -0.1;
float magnitude = 30;

void display(void) {
        cout << x <<"\t"<< y <<"\t"<<horizontal_velocity <<"\t"<< vertical_velocity<<endl;
        x = x + magnitude*(horizontal_velocity);
        y = y + magnitude*(vertical_velocity);

        if (x>=MAX-BALLRADIUS || x <=BALLRADIUS)
                horizontal_velocity *= -1;
        if (y>=2*MAX-BALLRADIUS || y <=BALLRADIUS)
                vertical_velocity *= -1;

	//glClear(GL_COLOR_BUFFER_BIT);
        plotCircle(x,y,BALLRADIUS);
}

void Timer(int value) {
        display();
	glutTimerFunc(1, Timer, 0);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(400, 800);
	glutCreateWindow("Bounce Tales");
//	glutDisplayFunc(display);
	init();
	Timer(0);
	glutMainLoop();

	return 0;
}
