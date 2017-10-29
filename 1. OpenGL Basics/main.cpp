#include "GL/gl.h"
#include <iostream>
//#include <glut/glut.h>
#include "GL/freeglut.h"

using namespace std;
char ch;
void myInit()
{
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glColor3f(0.0, 0.0, 0.0);
        glPointSize(10);
        gluOrtho2D(0.0, 320.0, 0.0, 320.0);
}

void points()
{
        glClear(GL_COLOR_BUFFER_BIT);
        switch (ch) {
                case 'a':glBegin(GL_POINTS);;break;
                case 'b':glBegin(GL_LINES);;break;
                case 'c':glBegin(GL_LINE_STRIP);;break;
                case 'd':glBegin(GL_LINE_LOOP);;break;
                case 'e':glBegin(GL_TRIANGLES);;break;
                case 'f':glBegin(GL_TRIANGLE_STRIP);;break;
                case 'g':glBegin(GL_TRIANGLE_FAN);;break;
                case 'h':glBegin(GL_QUADS);;break;
                case 'i':glBegin(GL_QUAD_STRIP);;break;
                case 'j':glBegin(GL_POLYGON);;break;
                default:cout<<"Wrong Choice";break;
        }
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
        glutInitWindowSize(320, 320);
        glutCreateWindow("Exercise 1");
        glutDisplayFunc(points);
//    glutDisplayFunc(quads);
        myInit();
        glutMainLoop();
        return 1;

}
