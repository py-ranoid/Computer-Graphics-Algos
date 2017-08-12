#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include "math.h"

#define SHAPE_WIDTH 100.0
#define WIN_WIDTH 400.0
#define WIN_HEIGHT 500.0
#define VP_WIDTH 200.0
#define VP_HEIGHT 200.0
#define NUMPOINTS 10
#define POINTSIZE 2

//#include<glut/glut.h>
using namespace std;
void myInit()
{
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        glPointSize(POINTSIZE);
        gluOrtho2D(0, (WIN_WIDTH+VP_WIDTH)/POINTSIZE, 0, (WIN_HEIGHT)/POINTSIZE);
}

void plot()
{
        // Setting colour to red for axes and text
        glColor3f(1.0, 0.0, 0.0);

        glBegin(GL_LINES);
        glVertex2d(VP_WIDTH/POINTSIZE   , 0);
        glVertex2d(VP_WIDTH/POINTSIZE   , WIN_HEIGHT/POINTSIZE);
        glVertex2d(0                    , (WIN_HEIGHT-VP_HEIGHT)/POINTSIZE);
        glVertex2d(VP_WIDTH/POINTSIZE   , (WIN_HEIGHT-VP_HEIGHT)/POINTSIZE);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2d(0                    , (WIN_HEIGHT-VP_HEIGHT)/POINTSIZE);
        glVertex2d(VP_WIDTH/POINTSIZE   , (WIN_HEIGHT-VP_HEIGHT)/POINTSIZE);
        glVertex2d(VP_WIDTH/POINTSIZE   , 0);
        glVertex2d(0                    , 0);
        glEnd();

        //To set the raster position, to enable the call to glutBitmapString().
        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glRasterPos2i(5,WIN_HEIGHT/POINTSIZE - 10);

        //Function to print anything to the output screen.
        const unsigned char* vp = reinterpret_cast<const unsigned char *>("Viewport");
        //Select the font of the text to be printed.
        glutBitmapString(GLUT_BITMAP_HELVETICA_18, vp);

        //To set the raster position, to enable the call to glutBitmapString().
        glRasterPos2i(VP_WIDTH/POINTSIZE+5,WIN_HEIGHT/POINTSIZE - 10);

        //Function to print anything to the output screen.
        const unsigned char* t = reinterpret_cast<const unsigned char *>("Window");
        //Select the font of the text to be printed.
        glutBitmapString(GLUT_BITMAP_HELVETICA_18, t);


        // Setting colour to white for plotting shape
        glColor3f(1.0, 1.0, 1.0);
        // Coordinates of given shape
        float points[NUMPOINTS][2] = {
                {20.0              ,100.0},
                {50.0              ,140.0},
                {50.0              ,120.0},
                {SHAPE_WIDTH + 50.0,120.0},
                {SHAPE_WIDTH + 50.0,140.0},
                {SHAPE_WIDTH + 80.0,100.0},
                {SHAPE_WIDTH + 50.0,60.0},
                {SHAPE_WIDTH + 50.0,80.0},
                {50.0              ,80.0},
                {50.0              ,60.0}
        };

        glBegin(GL_LINE_LOOP);

        for(int i =0; i<NUMPOINTS; i++)
                glVertex2d(VP_WIDTH/POINTSIZE + round(points[i][0]), round(points[i][1]));

        glEnd();

        float Xscale = VP_WIDTH / WIN_WIDTH;
        float Yscale = VP_HEIGHT / WIN_HEIGHT;

        glBegin(GL_LINE_LOOP);
        for(int i =0; i<NUMPOINTS; i++)
                glVertex2d(round(points[i][0])*Xscale, (WIN_HEIGHT - VP_HEIGHT)/POINTSIZE + round(points[i][1])*Yscale);
        glEnd();

        glFlush();
}

void func()
{
        plot();
}

int main(int argc, char * argv[])
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(WIN_WIDTH+VP_WIDTH, WIN_HEIGHT);
        glutCreateWindow("Lines");
        myInit();
        glutDisplayFunc(func);
        glutMainLoop();
        return 1;
}
