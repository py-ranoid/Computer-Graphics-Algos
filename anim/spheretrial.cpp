#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include <math.h>
#define AXISLEN 40
#define MAX 20.0f
#define BALLRADIUS 2
GLfloat xRotated, yRotated, zRotated;
GLdouble radius=1;

//float x=MAX/4+100,y=MAX/2;
float horizontal_velocity = -0.2;
float vertical_velocity = -0.1;
float upward_velocity = -0.1;
float magnitude = 10;


void display(void);
void reshape(int x, int y);

void drawAxes()
{
        glBegin(GL_LINES);
        glColor3f(1.0f, 0.f, 0.0f);
        glVertex3f(0.0    ,0.0        ,-AXISLEN);
        glVertex3f(0.0    ,0.0        ,AXISLEN);
        glColor3f(0.0f, 1.f, 0.0f);
        glVertex3f(0.0    ,-AXISLEN   ,0.0);
        glVertex3f(0.0    ,AXISLEN    ,0.0);
        glColor3f(0.0f, 0.f, 1.0f);
        glVertex3f(-AXISLEN,0.0       ,0.0);
        glVertex3f(AXISLEN,0.0        ,0.0);
        glEnd();

        glRasterPos3i(0.0,0.0,5.0);
        const unsigned char* z = reinterpret_cast<const unsigned char *>("Z");
        glutBitmapString(GLUT_BITMAP_HELVETICA_12, z);

        glRasterPos3i(0.0,5.0,0.0);
        const unsigned char* y = reinterpret_cast<const unsigned char *>("Y");
        glutBitmapString(GLUT_BITMAP_HELVETICA_12, y);

        glRasterPos3i(5.0,0.0,0.0);
        const unsigned char* x = reinterpret_cast<const unsigned char *>("X");
        glutBitmapString(GLUT_BITMAP_HELVETICA_12, x);

}
float x=0,y=0,z=0;
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();
    glPushMatrix();
    glTranslatef(x,y,z);
    x = x + magnitude*(horizontal_velocity);
    y = y + magnitude*(vertical_velocity);
    z = z + magnitude*(upward_velocity);

    if (x>=MAX-BALLRADIUS || x <=-1*MAX+BALLRADIUS)
            horizontal_velocity *= -1;
    if (y>=2*MAX-BALLRADIUS || y <=-1.5*MAX+BALLRADIUS)
            vertical_velocity *= -1;
    if (z>=2*MAX-BALLRADIUS || z <=-1*MAX+BALLRADIUS)
        upward_velocity *= -1;
    glColor3f(0.9, 0.3, 0.2);
    glutSolidSphere(BALLRADIUS,30,30);
    glPopMatrix();
    glFlush();
    // sawp buffers called because we are using double buffering
   // glutSwapBuffers();
}


void reshape(int x, int y){
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    gluLookAt(11.0, 10.0, 19.0, /* eye is at (0,0,5) */
              0.0, 0.0, 0.0,  /* center is at (0,0,0) */
              1.0, 1.0, 0.);  /* up is in positive Y direction */
}
void Timer(int value) {
        display();
	glutTimerFunc(10, Timer, 0);
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(350,350);
    glutCreateWindow("Solid Sphere");
    //GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 0.0};  /* Red diffuse light. */
    GLfloat light_position[] = {-1.0, -1.0, -4.0, 0.0};  /* Infinite light location. */
    //glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); // Assigning light diffuse property to GL_LIGHT0 (colour)
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); // Specify position of GL_LIGHT0 at light_position
    glEnable(GL_LIGHT0);                            // Enable GL_LIGHT0
    glEnable(GL_LIGHTING);                          // Enable all lighting
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    gluPerspective( /* field of view in degree */ 60.0,
                                                  /* aspect ratio */ 1.0,
                                                  /* Z near */ 1.0, /* Z far */ 100.0);
//    glMatrixMode(GL_MODELVIEW);
    gluLookAt(30.0, 50.0, 30.0, /* eye is at (0,0,5) */
              0.0, 10.0, 0.0,  /* center is at (0,0,0) */
              0.0, 0.0, 1.0);  /* up is in positive Y direction */

//    glutReshapeFunc(reshape);
    //glutDisplayFunc(display);
    Timer(0);
    //Timer(0);
    glutMainLoop();
    return 0;
}
