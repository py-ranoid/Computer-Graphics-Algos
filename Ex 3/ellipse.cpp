# include "GL/freeglut.h"
# include "GL/gl.h"
# include <iostream>
# include "math.h"
//  # include<glut/glut.h>
using namespace std;
float xcentre, ycentre, rx,ry;
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
        glPointSize(4);
        gluOrtho2D(0, 100, 0, 100);
}

float ellfunc1(float x,float y,float rx,float ry){
    //return pow(x + 1.0,2) + pow(y + 0.5,2) - pow(y + 0.5,2);
    float rx2 = pow(rx,2);
    float ry2 = pow(ry,2);
    float val = pow(x + 1.0,2)*ry2 + pow(y - 0.5,2)*rx2 - rx2*ry2;
    return val;
}

float ellfunc2(float x,float y,float rx,float ry){
    //return pow(x + 1.0,2) + pow(y + 0.5,2) - pow(y + 0.5,2);
    float rx2 = pow(rx,2);
    float ry2 = pow(ry,2);
    float val = pow(x + 0.5,2)*ry2 + pow(y - 1,2)*rx2 - rx2*ry2;
    return val;
}


void plotLine(float xc, float yc, float rx,float ry)
{
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        float x = 0.0;
        float y = ry;
        float p;
        for (;pow(ry,2)*x < pow(rx,2)*y;x++)
        {
                p = ellfunc1(x,y,rx,ry);
                cout << p <<"\t"<<x<<"\t"<<y<<"\t"<<rx<<"\t"<<ry<<endl;
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
        }
        cout << "Switch"<<endl;
        x=x-1;
        for (;y>=0;y--)
        {
                p = ellfunc2(x,y,rx,ry);
                cout << p <<"\t"<<x<<"\t"<<y<<"\t"<<rx<<"\t"<<ry<<endl;
                if ( p < 0){
                        x = x + 1;
                        //y = y;
                }
                else{
                        x = x;
                        //y = y - 1;
                }
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
        plotLine(xcentre, ycentre, rx, ry);
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
