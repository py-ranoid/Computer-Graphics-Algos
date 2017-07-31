#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include "math.h"
#define WIDTH 100.0
#define WIN_WIDTH 400.0
#define WIN_HEIGHT 500.0
#define VP_WIDTH 200.0
#define VP_HEIGHT 200.0
#define NUMPOINTS 10
#define POINTSIZE 2
//#include<glut/glut.h>
using namespace std;
float xstart,xend,ystart,yend,m;
int l2r;

/*
   Window Size : 400 x 400
   Ortho Plane : 80 x 80
   Point Size : 5 x 5
 */
void myInit(float r=1.0,float g = 1.0,float b=1.0)
{
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        glPointSize(POINTSIZE);
        gluOrtho2D(0, (WIN_WIDTH+VP_WIDTH)/POINTSIZE, 0, (WIN_HEIGHT)/POINTSIZE);
}

void plotLine(float x1, float y1, float x2, float y2, int l2r = 1)
{
        // (x1,y1) - Start points
        // (x2,y2) - End points
        // m       - Slope
        // Axis color is Red
        glColor3f(1.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINES);
        glVertex2d(VP_WIDTH/POINTSIZE, 0);
        glVertex2d(VP_WIDTH/POINTSIZE, WIN_HEIGHT/POINTSIZE);
        glVertex2d(0, (WIN_HEIGHT-VP_HEIGHT)/POINTSIZE);
        glVertex2d(VP_WIDTH/POINTSIZE, (WIN_HEIGHT-VP_HEIGHT)/POINTSIZE);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2d(0, (WIN_HEIGHT-VP_HEIGHT)/POINTSIZE);
        glVertex2d(VP_WIDTH/POINTSIZE, (WIN_HEIGHT-VP_HEIGHT)/POINTSIZE);
        glVertex2d(VP_WIDTH/POINTSIZE, 0);
        glVertex2d(0, 0);
        glEnd();

        // Axis color is White
        glColor3f(1.0, 1.0, 1.0);
        float points[NUMPOINTS][2] = {
                {20.0,100.0},
                {50.0,140.0},
                {50.0,120.0},
                {WIDTH + 50.0,120.0},
                {WIDTH + 50.0,140.0},
                {WIDTH + 80.0,100.0},
                {WIDTH + 50.0,60.0},
                {WIDTH + 50.0,80.0},
                {50.0,80.0},
                {50.0,60.0}
        };
        float Xscale = VP_WIDTH / WIN_WIDTH;
        float Yscale = VP_HEIGHT / WIN_HEIGHT;
        cout << Xscale << endl << Yscale <<endl;
        glBegin(GL_LINE_LOOP);
        for(int i =0; i<NUMPOINTS; i++) {
                glVertex2d(VP_WIDTH/POINTSIZE + round(points[i][0]), round(points[i][1]));
                //glVertex2d(VP_WIDTH/POINTSIZE + round(points[i][0]), round(points[i][1]));
        }
        glEnd();
        //(WIN_HEIGHT - VP_HEIGHT)/POINTSIZE + round(points[i][1]*Yscale)
        glBegin(GL_LINE_LOOP);
        for(int i =0; i<NUMPOINTS; i++) {
                //glVertex2d(3+VP_WIDTH/POINTSIZE + round(points[i][0]), 5+round(points[i][1]));
                glVertex2d(round(points[i][0])*Xscale, (WIN_HEIGHT - VP_HEIGHT)/POINTSIZE + round(points[i][1])*Yscale);
        }
        glEnd();
        //
        // glBegin(GL_LINE_LOOP);
        // for(int i =0; i<NUMPOINTS; i++) {
        //         glVertex2d(round(points[i][0])*Xscale, 40);
        // }
        // glEnd();
        // for (int i =0;i<NUMPOINTS;i++){
        //         glVertex2d(round(points[i][0]), VP_HEIGHT + round(points[i][1]));
        // }
        // glVertex2d(round(), round());
        // glVertex2d(round(), round());
        // glVertex2d(round(), round());
        // glVertex2d(round(), round());
        // glVertex2d(round(WIDTH + 50.0), round());
        // glVertex2d(round(WIDTH + 80.0), round());
        // glVertex2d(round(WIDTH + 50.0), round());
        // glVertex2d(round(WIDTH + 50.0), round());
        // glVertex2d(round(), round());
        // glVertex2d(round(), round());

        glFlush();
}

void func()
{
        plotLine(xstart, ystart, xend, yend,l2r);
        //plotLine(10, 30, 80, 5,0);
}

int main(int argc, char * argv[])
{
        // cout << "Start points (0,0 - 100,100)\n";
        // cout << "x: "; cin >> xstart;
        // cout << "y: "; cin >> ystart;
        // cout << "End points (0,0 - 100,100)\n";
        // cout << "x: "; cin >> xend;
        // cout << "y: "; cin >> yend;
        // cout << "0.Right to Left\t\t1.Left to Right\n :";
        // cin >> l2r;
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(WIN_WIDTH+VP_WIDTH, WIN_HEIGHT);
        glutCreateWindow("Lines");
        myInit();
        glutDisplayFunc(func);
        glutMainLoop();
        return 1;
}
