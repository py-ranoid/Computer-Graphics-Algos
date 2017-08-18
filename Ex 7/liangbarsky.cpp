#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include "math.h"
#include <algorithm>
//#include<glut/glut.h>
#define WIDTH 500.0     // Width of Clipping Area
#define HEIGHT 500.0    // Height of Clipping Area
#define VERPAD 100.0    // Vertical Padding
#define HORPAD 100.0    // Horizontal Padding
#define POINTSIZE 2

using namespace std;
bool TBRL1[4];          // Stores TBRL values of starting point
bool TBRL2[4];          // Stores TBRL values of end point
int xstart,ystart,xend,yend,xstarttemp,ystarttemp;
int xstartinit,ystartinit,xendinit,yendinit;
int xmin,xmax;
int ymin,ymax;
float slope;

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

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
        glVertex2d(xstart,ystart);
        glVertex2d(xend,yend);
        glEnd();

        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POINTS);
        glVertex2d(xstartinit,ystartinit);
        glVertex2d(xendinit,yendinit);
        glEnd();

        glFlush();
}
void solver(){
        float u;
        int del_x,del_y;
        float u1,u2;
        del_x = xend - xstart;
        del_y = yend - ystart;
        int Pvals[4] = {-1 *del_x,
                     del_x,
                 -1 *del_y,
                      del_y
         };
        int Qvals[4] = {
                xstart - xmin,
                 xmax - xstart,
                 ystart - ymin,
                 ymax - ystart
        };

        int flag = 1;
        u1 = 0; u2 = 1;
        for (int i =0 ;i < 4; i++){
                cout << i << " " <<Pvals[i]<<"\t"<<Qvals [i]<<"\t"<<float(Qvals[i])/Pvals[i]<<endl;
                float rk;
                if (Pvals[i] == 0){
                        // Line is parallel to boundary (del_y = 0 or del = 0)
                         if (Qvals[i]<0){
                                // Line is to the left of xmin or right of xmax.
                                // Or Line is above ymax and below ymin
                                // Hence Reject
                                flag = 0;
                                break;
                        }
                        else
                                //  Line is inside the parallel clipping. Accept
                                continue;

                }
                else if (Pvals[i] < 0){
                        // Line proceeds from outside to inside of the infinite extension
                        rk = float(Qvals[i])/Pvals[i];
                        if (u1<rk){
                                u1 = rk;
                        }
                }
                else {
                        // Line proceeds from inside to outside boundary
                        rk = float(Qvals[i])/Pvals[i];
                        u2 = ((rk < u2) ? rk : u2);
                        //cout << "Inside " << rk << u1<<endl;
                }
                cout <<endl<< "u1 : "<<u1<< " u2 : "<<u2<< " delx : "<<del_x<< " dely : "<<del_y<<endl;
        }
        if (u1>u2){
                flag = 0;
        }
        else{
                xstarttemp = xstart + del_x * u1;
                ystarttemp = ystart + del_y * u1;

                xend = xstart + del_x * u2;
                yend = ystart + del_y * u2;

                xstart = xstarttemp;
                ystart = ystarttemp;
        }
        cout << "Start : "<< xstart << " " << ystart << endl;
        cout << "End : "<<xend << " " << yend << endl;

}
void func()
{
        plot();
}

int main(int argc, char * argv[])
{
        // Accepting starting and end points of lines
        xmax = (WIDTH + 2 * HORPAD)/POINTSIZE;
        ymax = (HEIGHT + 2 * VERPAD)/POINTSIZE;
        xmin = 0;
        ymin = 0;                if (u1>u2){
                                flag = 0;
                                break;
                        }
                        else{
                                xstarttemp = xstart + del_x * u1;
                                ystarttemp = ystart + del_y * u1;

                                xend = xstart + del_x * u2;
                                yend = ystart + del_y * u2;

                                xstart = xstarttemp;
                                ystart = ystarttemp;
                                break;
                        }
                cout << "Start : "<< xstart << " " << ystart << endl;
                cout << "End : "<<xend << " " << yend << endl;


        cout << "Start points (0,0 - "<<xmax<<","<<ymax<<")\n";
        cout << "x: "; cin >> xstart;
        cout << "y: "; cin >> ystart;
        cout << "End points (0,0 - "<<xmax<<","<<ymax<<")\n";
        cout << "x: "; cin >> xend;                if (u1>u2){
                                flag = 0;
                                break;
                        }
                        else{
                                xstarttemp = xstart + del_x * u1;
                                ystarttemp = ystart + del_y * u1;

                                xend = xstart + del_x * u2;
                                yend = ystart + del_y * u2;

                                xstart = xstarttemp;
                                ystart = ystarttemp;
                                break;
                        }
                cout << "Start : "<< xstart << " " << ystart << endl;
                cout << "End : "<<xend << " " << yend << endl;
                if (u1>u2){
                        flag = 0;
                        break;
                }
                else{
                        xstarttemp = xstart + del_x * u1;
                        ystarttemp = ystart + del_y * u1;

                        xend = xstart + del_x * u2;
                        yend = ystart + del_y * u2;

                        xstart = xstarttemp;
                        ystart = ystarttemp;
                        break;
                }
        cout << "Start : "<< xstart << " " << ystart << endl;
        cout << "End : "<<xend << " " << yend << endl;

        cout << "y: "; cin >> yend;

        xmax -= HORPAD/POINTSIZE;
        ymax -= VERPAD/POINTSIZE;
        xmin = HORPAD/POINTSIZE;
        ymin = VERPAD/POINTSIZE;
        // Computing slope of line
        slope = float(yend-ystart)/(xend-xstart);
        cout << "Slope : "<< slope <<endl;
        // Storing initial values to plot points in the end
        xstartinit = xstart;    ystartinit = ystart;
        xendinit = xend;        yendinit = yend;
        solver();
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(WIDTH + 2 * HORPAD, HEIGHT + 2 * VERPAD);
        glutCreateWindow("Ex. 7 : Cohen Sutherland Clipping algorithm");
        myInit();
        glutDisplayFunc(func);
        glutMainLoop();
        return 1;
}
