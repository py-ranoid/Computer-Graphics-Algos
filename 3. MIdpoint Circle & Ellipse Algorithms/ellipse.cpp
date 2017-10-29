# include "GL/freeglut.h"
# include "GL/gl.h"
# include <iostream>
# include "math.h"
//  # include<glut/glut.h>
using namespace std;
float xcentre, ycentre, rx,ry;
/*
   Window Size: 400 x 400
   Ortho Plane: 100 x 100
   Point Size: 4 x 4
 */
void myInit()
{
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.01);
        glPointSize(4);
        gluOrtho2D(0, 100, 0, 100);
}

float ellfunc1(float x,float y,float rx,float ry){
        //Returns [(x + 1.0)^2 * ry^2] + [(y - 0.5)^2 * rx^2] - [ry^2 * rx^2];
        float rx2 = pow(rx,2);
        float ry2 = pow(ry,2);
        float val = pow(x + 1.0,2)*ry2 + pow(y - 0.5,2)*rx2 - rx2*ry2;
        return val;
}

float ellfunc2(float x,float y,float rx,float ry){
        //Returns [(x + 0.5)^2 * ry^2] + [(y - 1.0)^2 * rx^2] - [ry^2 * rx^2];
        float rx2 = pow(rx,2);
        float ry2 = pow(ry,2);
        float val = pow(x + 0.5,2)*ry2 + pow(y - 1,2)*rx2 - rx2*ry2;
        return val;
}


void plotEllipse(float xc, float yc, float rx,float ry)
{
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        float x,y;
        float p;
        /* Region Boundary Calculation :
                Ellipse Slope :
                        dy/dx = - (2 * ry^2 * x) / (2 * rx^2 * y)
                At region boundary, slope == -1
                        Hence, (2 * ry^2 * x) = (2 * rx^2 * y)
                                    ry^2 * x = rx^2 * y
         */
        for (x = 0.0, y = ry; pow(ry,2)*x < pow(rx,2)*y; x++)
        {
                // Magnitude of slope is less than 1
                // Taking unit steps in X until |slope| == 1
                p = ellfunc1(x,y,rx,ry);
                cout << p <<"\t"<<x<<"\t"<<y<<"\t"<<rx<<"\t"<<ry<<endl;
                if ( p >= 0)
                        y -= 1;

                glVertex2d(xc + x,yc + y);
                glVertex2d(xc + x,yc - y);
                glVertex2d(xc - x,yc + y);
                glVertex2d(xc - x,yc - y);
        }
        // Switching to region 2
        x -= 1;
        for (; y>=0; y--)
        {
                // Magnitude of slope is greater than 1
                // Taking unit steps in Y when |slope| > 1
                p = ellfunc2(x,y,rx,ry);
                cout << p <<"\t"<<x<<"\t"<<y<<"\t"<<rx<<"\t"<<ry<<endl;
                if ( p < 0)
                        x = x + 1;

                glVertex2d(xc + x,yc + y);
                glVertex2d(xc + x,yc - y);
                glVertex2d(xc - x,yc + y);
                glVertex2d(xc - x,yc - y);
        }
        glEnd();
        glFlush();
}

void func()
{
        cout << xcentre << ycentre << rx << ry;
        plotEllipse(xcentre, ycentre, rx, ry);
}

int main(int argc, char * argv[])
{
        cout << "Enter circle centre coordinates (0,0 - 80,80)\n";
        cout << "x: "; cin >> xcentre;
        cout << "y: "; cin >> ycentre;
        cout << "Radius x: "; cin >> rx;
        cout << "Radius y: "; cin >> ry;
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(400, 400);
        glutCreateWindow("Lines");
        myInit();
        glutDisplayFunc(func);
        glutMainLoop();
        return 1;
}
