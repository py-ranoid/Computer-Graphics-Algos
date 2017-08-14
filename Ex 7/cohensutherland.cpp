#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include "math.h"
#define WIDTH 400.0
#define HEIGHT 500.0
#define VERPAD 100.0
#define HORPAD 100.0
#define NUMPOINTS 10
#define POINTSIZE 2
//#include<glut/glut.h>
using namespace std;
bool TBRL1[4];
bool TBRL2[4];
int xstart,ystart,xend,yend;
float slope;

void points2TBRL(bool TBRL[],int x,int y){
        TBRL[0] = ((y > (VERPAD+HEIGHT  )/POINTSIZE) ? 1 : 0);
        TBRL[1] = ((y < (VERPAD         )/POINTSIZE) ? 1 : 0);
        TBRL[2] = ((x > (HORPAD+WIDTH   )/POINTSIZE) ? 1 : 0);
        TBRL[3] = ((x < (HORPAD         )/POINTSIZE) ? 1 : 0);
}

int x2y(int x){
        return (yend + slope*(x - xend));
}

int y2x(int y){
        return (xend + (y - yend)/slope);
}

/*
void rectify(){
        switch (pos) {
                case 0: y = (VERPAD+HEIGHT)/POINTSIZE;  x = y2x(y);
                        break;
                case 1: y = (VERPAD)/POINTSIZE);        x = y2x(y);
                        break;
                case 2: x = (HORPAD+WIDTH)/POINTSIZE;   y= x2y(x);
                        break;
                case 3: x = (HORPAD)/POINTSIZE;         y= x2y(y);
                        break;
        }
}
*/
bool check_trivial_accept(bool TBRL1[], bool TBRL2[] ){
        for (int i =0; i < 4; i++) {
                if (TBRL1[i]|TBRL2[i])
                        return 0;
        }
        return 1;
}

bool check_trivial_reject(bool TBRL1[], bool TBRL2[] ){
        for (int i =0; i < 4; i++) {
                if (TBRL1[i]&TBRL2[i])
                        return 1;
        }
        return 0;
}

int find_TBRL_pos(bool TBRL[]){
        for (int i = 0; i < 4; i++)
                if (TBRL[i])
                        return i;
        return -1;
}

void myInit()
{
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        glPointSize(POINTSIZE);
        gluOrtho2D(0, (WIDTH + 2*HORPAD)/POINTSIZE, 0, (HEIGHT + 2*VERPAD)/POINTSIZE);
}
void plot()
{
        // Setting colour to red for axes and text
        glColor3f(1.0, 0.0, 0.0);

        // Horizontal Lines
        glBegin(GL_LINES);
        glVertex2d(0, VERPAD/POINTSIZE);
        glVertex2d((WIDTH+2*HORPAD)/POINTSIZE, VERPAD/POINTSIZE);
        glVertex2d(0, (VERPAD+HEIGHT)/POINTSIZE);
        glVertex2d((WIDTH+2*HORPAD)/POINTSIZE, (VERPAD+HEIGHT)/POINTSIZE);

        // Vertical Lines
        glVertex2d(HORPAD/POINTSIZE, 0);
        glVertex2d(HORPAD/POINTSIZE, (HEIGHT + 2 * VERPAD)/POINTSIZE);
        glVertex2d((HORPAD + WIDTH)/POINTSIZE, 0);
        glVertex2d((HORPAD + WIDTH)/POINTSIZE, (HEIGHT + 2 * VERPAD)/POINTSIZE);

        glEnd();

        glRasterPos2i((WIDTH+2*HORPAD)/(POINTSIZE*2),(HEIGHT+2*VERPAD)/POINTSIZE-10);
        const unsigned char* toptext = reinterpret_cast<const unsigned char *>("Top : 1000");
        glutBitmapString(GLUT_BITMAP_HELVETICA_12, toptext);

        glRasterPos2i((WIDTH+2*HORPAD)/(POINTSIZE*2),10);
        const unsigned char* bottomtext = reinterpret_cast<const unsigned char *>("Bottom : 0100");
        glutBitmapString(GLUT_BITMAP_HELVETICA_12, bottomtext);

        glRasterPos2i(10,(HEIGHT+2*VERPAD)/(POINTSIZE*2));
        const unsigned char* lefttext = reinterpret_cast<const unsigned char *>("Left : 0001");
        glutBitmapString(GLUT_BITMAP_HELVETICA_12, lefttext);

        glRasterPos2i((WIDTH+HORPAD)/POINTSIZE + 10,(HEIGHT+2*VERPAD)/(POINTSIZE*2));
        const unsigned char* righttext = reinterpret_cast<const unsigned char *>("Right : 0010");
        glutBitmapString(GLUT_BITMAP_HELVETICA_12, righttext);

        // glRasterPos2i(5,WIN_HEIGHT/POINTSIZE - 10);
        // const unsigned char* vp = reinterpret_cast<const unsigned char *>("Top : 1000");
        // glutBitmapString(GLUT_BITMAP_HELVETICA_18, vp);
        //
        // glRasterPos2i(5,WIN_HEIGHT/POINTSIZE - 10);
        // const unsigned char* vp = reinterpret_cast<const unsigned char *>("Top : 1000");
        // glutBitmapString(GLUT_BITMAP_HELVETICA_18, vp);

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
        glVertex2d(xstart,ystart);
        glVertex2d(xend,yend);
        // glVertex2d(VP_WIDTH/POINTSIZE   , (WIN_HEIGHT-VP_HEIGHT)/POINTSIZE);
        // glVertex2d(VP_WIDTH/POINTSIZE   , 0);
        // glVertex2d(0                    , 0);
        glEnd();
        //
        //
        // glRasterPos2i(VP_WIDTH/POINTSIZE+5,WIN_HEIGHT/POINTSIZE - 10);
        // const unsigned char* t = reinterpret_cast<const unsigned char *>("Window");
        // glutBitmapString(GLUT_BITMAP_HELVETICA_18, t);
        //
        // glBegin(GL_LINE_LOOP);
        // for(int i =0; i<NUMPOINTS; i++)
        //         glVertex2d(round(points[i][0])*Xscale, (WIN_HEIGHT - VP_HEIGHT)/POINTSIZE + round(points[i][1])*Yscale);
        // glEnd();

        glFlush();
}
void solver(){
        int x,y;
        points2TBRL(TBRL1,xstart,ystart);
        points2TBRL(TBRL2,xend,yend);
        for (int i =0; i <4; i++) {
                cout << TBRL1[i] << TBRL2[i]<<endl;
        }
        if (check_trivial_accept(TBRL1,TBRL2))
                cout<<"Trivially accepted"<<endl;
        else{
                cout<<"Not Trivially accepted"<<endl;
                if (check_trivial_reject(TBRL1,TBRL2)) {
                        cout << "Trivially rejected."<<endl;
                }
                else {
                        cout << "Trivial reject failed"<<endl;
                        bool empty[4] = {0,0,0,0};
                        // Checking if (xstart,ystart) is in window
                        if (!check_trivial_accept(TBRL1,empty)) {
                                int pos = find_TBRL_pos(TBRL1);
                                // Reset xstart and ystart
                                x = xstart;
                                y = ystart;
                                cout<<"1. Trivial accept of start failed at pos :"<<pos<<endl;
                                switch (pos) {
                                        case 0: y = (VERPAD+HEIGHT)/POINTSIZE;  x = y2x(y);
                                                cout <<pos<<" changed to " << x << " " << y << endl;
                                                break;
                                        case 1: y = (VERPAD)/POINTSIZE;         x = y2x(y);
                                                cout <<pos<<" changed to " << x << " " << y << endl;
                                                break;
                                        case 2: x = (HORPAD+WIDTH)/POINTSIZE;   y= x2y(x);
                                                cout <<pos<<" changed to " << x << " " << y << endl;
                                                break;
                                        case 3: x = (HORPAD)/POINTSIZE;         y= x2y(x);
                                                cout <<pos<<" changed to " << x << " " << y << endl;
                                                break;
                                }
                                cout << "Start changed to " << x << " " << y << endl;
                                xstart = x;
                                ystart = y;
                                points2TBRL(TBRL1,xstart,ystart);
                                if (!check_trivial_accept(TBRL1,empty)) {
                                        int pos = find_TBRL_pos(TBRL1);
                                        // Reset xstart and ystart
                                        x = xstart;
                                        y = ystart;
                                        cout<<"2. Trivial accept of start failed at pos :"<<pos<<endl;
                                        switch (pos) {
                                                case 0: y = (VERPAD+HEIGHT)/POINTSIZE;  x = y2x(y);
                                                        break;
                                                case 1: y = (VERPAD)/POINTSIZE;        x = y2x(y);
                                                        break;
                                                case 2: x = (HORPAD+WIDTH)/POINTSIZE;   y= x2y(x);
                                                        break;
                                                case 3: x = (HORPAD)/POINTSIZE;         y= x2y(y);
                                                        break;
                                        }
                                        cout << "Start changed to " << x << " " << y << endl;
                                        xstart = x;
                                        ystart = y;
                                        points2TBRL(TBRL1,xstart,ystart);
                                }
                        }
                        // Checking if (xend,yend) is in window
                        if (!check_trivial_accept(TBRL2,empty)) {
                                int pos = find_TBRL_pos(TBRL2);
                                // Reset xend and yend
                                x = xend;
                                y = yend;
                                cout<<"1. Trivial accept of end failed at pos :"<<pos<<endl;
                                switch (pos) {
                                        case 0: y = (VERPAD+HEIGHT)/POINTSIZE;  x = y2x(y);
                                                break;
                                        case 1: y = (VERPAD)/POINTSIZE;        x = y2x(y);
                                                break;
                                        case 2: x = (HORPAD+WIDTH)/POINTSIZE;   y= x2y(x);
                                                break;
                                        case 3: x = (HORPAD)/POINTSIZE;         y= x2y(y);
                                                break;
                                }
                                cout << "End changed to " << x << " " << y << endl;
                                xend = x;
                                yend = y;
                                points2TBRL(TBRL2,xend,yend);
                                if (!check_trivial_accept(TBRL2,empty)) {
                                        int pos = find_TBRL_pos(TBRL2);
                                        // Reset xend and yend
                                        x = xend;
                                        y = yend;
                                        cout<<"2. Trivial accept of end failed at pos :"<<pos<<endl;
                                        switch (pos) {
                                                case 0: y = (VERPAD+HEIGHT)/POINTSIZE;  x = y2x(y);
                                                        break;
                                                case 1: y = (VERPAD)/POINTSIZE;        x = y2x(y);
                                                        break;
                                                case 2: x = (HORPAD+WIDTH)/POINTSIZE;   y= x2y(x);
                                                        break;
                                                case 3: x = (HORPAD)/POINTSIZE;         y= x2y(y);
                                                        break;
                                        }
                                        cout << "End changed to " << x << " " << y << endl;
                                        xend = x;
                                        yend = y;
                                        points2TBRL(TBRL2,xend,yend);
                                }
                        }

                }
        }
        cout << xstart << " " << xend << endl;
        cout << ystart << " " << yend << endl;
}
void func()
{
        plot();
}

int main(int argc, char * argv[])
{
        cout << "Start points (0,0 - "<<(WIDTH + 2 * HORPAD)/POINTSIZE<<","<<(HEIGHT + 2 * VERPAD)/POINTSIZE<<")\n";
        cout << "x: "; cin >> xstart;
        cout << "y: "; cin >> ystart;
        cout << "Start points (0,0 - "<<(WIDTH + 2 * HORPAD)/POINTSIZE<<","<<(HEIGHT + 2 * VERPAD)/POINTSIZE<<")\n";
        cout << "x: "; cin >> xend;
        cout << "y: "; cin >> yend;
        slope = (yend-ystart)/(xend-xstart);
        solver();
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(WIDTH + 2 * HORPAD, HEIGHT + 2 * VERPAD);
        glutCreateWindow("Lines");
        myInit();
        glutDisplayFunc(func);
        glutMainLoop();
        return 1;
}
