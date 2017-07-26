#include "GL/gl.h"
#include <iostream>
//#include <glut/glut.h>
#include "GL/freeglut.h"

using namespace std;

void myInit()
{
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glColor3f(0.0, 0.0, 0.0);
        glPointSize(10);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void points()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        glVertex2d(150, 100);
        glVertex2d(200, 200);
        glVertex2d(250, 300);
        glEnd();
        glFlush();
}

void lines()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINES);
        glVertex2d(150, 200);
        glVertex2d(200, 250);
        glEnd();
        glFlush();
}

void line_strip()
{

        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINE_STRIP);
        glVertex2d(150, 200);
        glVertex2d(200, 250);
        glVertex2d(300, 300);
        glVertex2d(100, 100);
        glEnd();
        glFlush();
}

void line_loop()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glVertex2d(250, 200);
        glVertex2d(300, 200);
        glVertex2d(300, 250);

        glVertex2d(250, 250);
        glEnd();
        glFlush();
}

void triangle()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        glVertex2d(150, 200);
        glVertex2d(200, 250);
        glVertex2d(300, 300);
        glVertex2d(100, 100);
        glEnd();
        glFlush();

}

void triangle_strip()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLE_STRIP);
        glVertex2d(150, 200);
        glVertex2d(200, 250);
        glVertex2d(300, 300);
        glVertex2d(100, 100);
        glEnd();
        glFlush();

}

void triangle_fan()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2d(150, 200);
        glVertex2d(200, 250);
        glVertex2d(300, 300);
        glVertex2d(100, 100);
        glEnd();
        glFlush();
}

void quads()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glVertex2d(150, 200);
        glVertex2d(200, 250);
        glVertex2d(300, 300);
        glVertex2d(100, 100);
        glEnd();
        glFlush();
}

void quad_strip()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUAD_STRIP);
        glVertex2d(150, 200);
        glVertex2d(200, 250);
        glVertex2d(300, 300);
        glVertex2d(100, 100);
        glEnd();
        glFlush();
}

void polygon()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glVertex2d(150, 200);
        glVertex2d(200, 250);
        glVertex2d(300, 300);
        glVertex2d(100, 100);
        glVertex2d(250, 150);
        glEnd();
        glFlush();
}

int main(int argc, char * argv[])
{
        char ch;
        cout << " a. GL_POINTS \t\t : Treats each vertex as a single point. Vertex i defines point i. Hence n points are drawn\n\n";
        cout << " b. GL_LINES \t\t : Treats each pair of vertices as an independent line segment. Last point ignored if odd number of vertices are given.\n";
        cout << " c. GL_LINE_STRIP \t : Similar to GL_LINES. Joins continous vertices.\n";
        cout << " d. GL_LINE_LOOP \t : GL_LINE_STRIP + Connects First and last Vertex.\n\n";
        cout << " e. GL_TRIANGLES \t : Treats each triplet of vertices as an independent triangle.\n";
        cout << " f. GL_TRIANGLE_STRIP \t : Draws a connected group of triangles.  One triangle is defined for each vertex presented after the first two vertices.\n";
        cout << " g. GL_TRIANGLE_FAN \t : Triangle n is defined by (1,n+1,n+2).\n\n";
        cout << " h. GL_QUADS \t : Treats each group of four vertices as an independent quadrilateral.\n";
        cout << " i. GL_QUAD_STRIP \t : One quadrilateral is defined for each pair of vertices presented after the first pair.\n";
        cout << " j. GL_POLYGON \t : Creates a polygon whose vertices are defined below\n\n";
        cout << "Choice :";cin >>ch;
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(640, 480);
        glutCreateWindow("Exercise 1");
        switch (ch) {
                case 'a':glutDisplayFunc(points);break;
                case 'b':glutDisplayFunc(lines);break;
                case 'c':glutDisplayFunc(line_strip);break;
                case 'd':glutDisplayFunc(line_loop);break;
                case 'e':glutDisplayFunc(triangle);break;
                case 'f':glutDisplayFunc(triangle_strip);break;
                case 'g':glutDisplayFunc(triangle_fan);break;
                case 'h':glutDisplayFunc(quads);break;
                case 'i':glutDisplayFunc(quad_strip);break;
                case 'j':glutDisplayFunc(polygon);break;
                default:cout<<"Wrong Choice";break;
        }
//    glutDisplayFunc(quads);
        myInit();
        glutMainLoop();
        return 1;

}
