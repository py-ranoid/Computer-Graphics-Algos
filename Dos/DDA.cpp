// #include "GL/freeglut.h"
// #include "GL/gl.h"
// #include "iostream"
// using namespace std;
// void renderFunction()
// {
//     glClearColor(0.0,0.0,0.0,0.0);
//     glClear(GL_COLOR_BUFFER_BIT);
//     glColor3f(1.0,1.0,1.0);
// //    glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
//     gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
//     glBegin(GL_POINTS);
//       //glVertex2f(0.0,0.0,0.0);
//     float m = 1.0;
//     float x = -2000.0;
//     float y = -2000.0;
//     float X,Y;
//     for (float k=0.0;k<4000.0;k++){
//       X = x + 1.0;
//       Y = y + m;
//       x=X;
//       y=Y;
//       cout <<X<<" "<<Y<<endl;
//       glVertex3f(X,Y,0.0);
//     }
//     glEnd();
//     glFlush();
// }
// int main(int argc, char** argv)
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE);
//     glutInitWindowSize(400,400);                            // Window Size
//     glutInitWindowPosition(0,0);                            // Window Positiong (Top-left)
//     glutCreateWindow("OpenGL - First window demo");         // Window Name
//     glutDisplayFunc(renderFunction);
//     glutMainLoop();
//     return 0;
// }


#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
//#include<glut/glut.h>

using namespace std;

void myInit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.01);
    //glPointSize(5);
    gluOrtho2D(0, 100, 0, 100);
}



void plotLine(float x1 , float y1 , float x2 , float y2)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    float m = float(y2 - y1)/float(x2 - x1);

    if ( m > 0)
        if(m <= 1)
              while(x1 <= x2 && y1 <= y2)
              {
                  glVertex2d(x1, y1);
                  x1 = x1 + 1;
                  y1 = y1 + m;
              }
        else
            while(x1 <= x2 && y1 <= y2)
            {
                glVertex2d(x1, y1);
                x1 = x1 + 1/m;
                y1 = y1 + 1;
            }
    else
        if(m > -1)
            while(x1 <= x2 && y1 <= y2)
            {
                glVertex2d(x1, y1);
                x1 = x1 + 1;
                y1 = y1 - m;
            }
        else
            while(x1 <= x2 && y1 <= y2)
            {
                glVertex2d(x1, y1);
                x1 = x1 + 1/m;
                y1 = y1 - 1;
            }
    glEnd();
    glFlush();
}

void func()
{
    plotLine(10, 10, 90, 65);
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(720, 480);
    glutCreateWindow("Lines");
    myInit();
    glutDisplayFunc(func);
    glutMainLoop();
    return 1;
}
