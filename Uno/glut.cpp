#include "GL/freeglut.h"
#include "GL/gl.h"

void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);           // specify clear values for RGBA
    glClear(GL_COLOR_BUFFER_BIT);               // sets the bitplane area of the window to values set by glClearColor
    glColor3f(1.0, 1.0, 1.0);                   //  set the current color. 3f implies 3 Float values
//  glOrtho(-1.5, 5.0, -1.5, 5.0, -1.5, 5.0);   // multiply the current matrix with an orthographic matrix. Args = (left, right,bottom, top,nearVal, farVal)
   gluOrtho2D(-0.5, 5.0, -0.5, 5.0, -0.5, 5.0);   // multiply the current matrix with an orthographic matrix. Args = (left, right,bottom, top,nearVal, farVal)
                                                // These are the clipping ends of the 3 planes (horizontal, vertical, depth)
    glBegin(GL_QUADS);                   // delimit the vertices of a primitive. (https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glBegin.xml)
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}

/* Main method - main entry point of application
the freeglut library does the window creation work for us,
regardless of the platform. */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400,400);                            // Window Size
    glutInitWindowPosition(0,0);                            // Window Positiong (Top-left)
    glutCreateWindow("OpenGL - First window demo");         // Window Name
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}
/*
Primitives :
  GL_POINTS - Treats each vertex as a single point. Vertex i defines point i. Hence n points are drawn
  GL_LINES  - Treats each pair of vertices as an independent line segment. Last point ignored if odd number of vertices are given
  GL_LINE_STRIP - Similar to GL_LINES. Joins continous vertices.
  GL_LINE_LOOP - GL_LINE_STRIP + Connects First and last Vertex
  GL_TRIANGLES - Treats each triplet of vertices as an independent triangle.
  GL_TRIANGLE_STRIP - Draws a connected group of triangles.  One triangle is defined for each vertex presented after the first two vertices.
  GL_TRIANGLE_FAN - Triangle n is defined by (1,n+1,n+2)
  GL_QUADS - Treats each group of four vertices as an independent quadrilateral.
  GL_QUAD_STRIP - One quadrilateral is defined for each pair of vertices presented after the first pair.
  GL_POLYGON - Creates a polygon whose vertices are defined below
*/
