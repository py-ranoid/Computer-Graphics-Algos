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
        float m = float(y2 - y1)/float(x2 - x1);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        cout<< "slope :"<<m;
        if ( m > 0 )
                // Positive Slope
                if ( l2r ==1 )
                        // Case 1
                        // Positive slope and left to right
                        if(m <= 1)
                                while(x1 <= x2 && y1 <= y2)
                                {
                                        cout << "--p1--";
                                        glVertex2d(round(x1), round(y1));
                                        x1 = x1 + 1;
                                        y1 = y1 + m;
                                }
                        else
                                while(x1 <= x2 && y1 <= y2)
                                {
                                        cout << "--p2--";
                                        glVertex2d(round(x1), round(y1));
                                        x1 = x1 + 1/m;
                                        y1 = y1 + 1;
                                }
                else{
                        // Case 2
                        // Positive slope and right to left
                        if(m <= 1)
                                while(x1 <= x2 && y1 <= y2)
                                {
                                        cout << "--p3--";
                                        glVertex2d(round(x2), round(y2));
                                        x2 = x2 - 1;
                                        y2 = y2 - m;
                                }
                        else
                                while(x1 <= x2 && y1 <= y2)
                                {
                                        cout << "--p3--";
                                        glVertex2d(round(x2), round(y2));
                                        x2 = x2 - 1/m;
                                        y2 = y2 - 1;
                                }
                }
        else{
                // Negative Slope
                if (l2r==1)
                        // Case 3
                        // Negative slope and left to right
                        if( m >= -1)
                                while(x1 <= x2 && y1 >= y2)
                                {
                                        cout << "--n1--";
                                        glVertex2d(round(x1), round(y1));
                                        x1 = x1 + 1;
                                        y1 = y1 + m;
                                        /* Note :
                                            Actual formula is y1 = y1 - m
                                            However since slope is Negative,
                                            the above formula would result a line
                                            with Positive slope
                                         */
                                }
                        else
                                while(x1 <= x2 && y1 >= y2)
                                {
                                        cout << "--n2--";
                                        glVertex2d(round(x1), round(y1));
                                        x1 = x1 - 1/m;
                                        y1 = y1 - 1;
                                        /* Note :
                                            Actual formula is x1 = x1 + 1/m;
                                            However since slope is Negative,
                                            the above formula would result a line
                                            with Positive slope
                                         */
                                }
                else{
                        // Case 4
                        // Negative slope and right to left
                        if(m > -1)
                                while(x1 <= x2 && y1 >= y2)
                                {
                                        cout << "--n3--";
                                        glVertex2d(round(x2), round(y2));
                                        x2 = x2 - 1;
                                        y2 = y2 - m;
                                        /* Note :
                                            Actual formula is y2 = y2 + m;
                                            However since slope is Negative,
                                            the above formula would result a line
                                            with Positive slope
                                         */

                                }
                        else
                                while(x1 <= x2 && y1 >= y2)
                                {
                                        cout << "--n4--";
                                        glVertex2d(round(x2), round(y2));
                                        x2 = x2 + 1/m;
                                        y2 = y2 + 1;
                                        /* Note :
                                            Actual formula is x2 = x2 - 1/m;
                                            However since slope is Negative,
                                            the above formula would result a line
                                            with Positive slope
                                         */
                                }
                }
        }
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
