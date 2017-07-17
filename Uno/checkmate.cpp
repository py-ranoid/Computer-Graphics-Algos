#include "GL/freeglut.h"
#include "GL/gl.h"

void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);           // specify clear values for RGBA
    glClear(GL_COLOR_BUFFER_BIT);               // sets the bitplane area of the window to values set by glClearColor
    glColor3f(1.0, 1.0, 1.0);                   //  set the current color. 3f implies 3 Float values
    glOrtho(0.0, 40.0, 0.0, 40.0, 0.0, 40.0);   // multiply the current matrix with an orthographic matrix. Args = (left, right,bottom, top,nearVal, farVal)
                                                // These are the clipping ends of the 3 planes (horizontal, vertical, depth)
    int i,j;
    glBegin(GL_POLYGON);

    glVertex2f(10.0    , 10.0);
    glVertex2f(10.0    , 50.0);
    glVertex2f(50.0 , 50.0);
    glVertex2f(50.0 , 10.0);



    // for (i=0;i<10;i++){
    //   for (j=0;j<10;j++){
    //         glVertex2f(i*10    , j*10);
    //         glVertex2f(i*10    , j*10+40);
    //         glVertex2f(i*10+40 , j*10+40);
    //         glVertex2f(i*10+40 , j*10);
    //   }
    // }
    glEnd();

    // glBegin(GL_QUADS);                   // delimit the vertices of a primitive. (https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glBegin.xml)
    //     glVertex2f(0, 0);
    //     glVertex2f(-0.5, 0.5);
    //     glVertex2f(0.5, 0.5);
    //     glVertex2f(0.5, -0.5);
    // glEnd();

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
    glutInitWindowPosition(100,100);                        // Window Positiong (Top-left)
    glutCreateWindow("OpenGL - First window demo");         // Window Name
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}
