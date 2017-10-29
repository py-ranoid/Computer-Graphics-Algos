# include "GL/freeglut.h"
# include "GL/gl.h"
# include <iostream>
# include "math.h"
//  # include<glut/glut.h>
using namespace std;
float xcentre, ycentre, r;
int l2r;
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
        glPointSize(2);
        gluOrtho2D(0, 200, 0, 200);
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
                cout << p <<"\t"<<x<<"\t"<<y<<"\t"<<r<<endl;
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

void func()
{
        cout << xcentre << ycentre << r;
        plotCircle(xcentre, ycentre, r);
        plotCircle(xcentre, ycentre, r - 60);
        plotCircle(xcentre, ycentre, r - 45);
        plotCircle(xcentre, ycentre, r - 30);
        plotCircle(xcentre, ycentre, r - 15);
}

int main(int argc, char * argv[])
{
        xcentre = 100;
        ycentre = 100;
        r = 80;
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(400, 400);
        glutCreateWindow("Target");
        myInit();
        glutDisplayFunc(func);
        glutMainLoop();
        return 1;
}
