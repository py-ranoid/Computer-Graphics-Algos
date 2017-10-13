#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include <math.h>
#define AXISLEN 40
#define MAX 20.0f
#define BALLRADIUS 5
#define ORBITRADIUS 25
GLfloat xRotated, yRotated, zRotated;
GLdouble radius=1;
using namespace std;
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
        glVertex3f(0.0,0.0,-AXISLEN);
        glVertex3f(0.0,0.0,AXISLEN);
        glColor3f(0.0f, 1.f, 0.0f);
        glVertex3f(0.0,-AXISLEN,0.0);
        glVertex3f(0.0,AXISLEN,0.0);
        glColor3f(0.0f, 0.f, 1.0f);
        glVertex3f(-AXISLEN,0.0,0.0);
        glVertex3f(AXISLEN,0.0,0.0);
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
        for (; x<=y; x++)
        {
                p = circlefunc(x,y,r);
                cout << p <<"\t"<<x<<"\t"<<y<<"\t"<<r<<endl;
                if ( p < 0) {
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
float x=0,y=0,z=0;
float theta=0.0;
void planet(float orbitmul, float thetaoffset, float thetamul, float r,float g, float b, float radiusmul) {
        float x = ORBITRADIUS * sin(theta*thetamul+thetaoffset) * orbitmul;
        float y = ORBITRADIUS * cos(theta*thetamul+thetaoffset) * orbitmul;
        glTranslatef(x,y,0);
        glColor3f(r, g, b);
        glutSolidSphere(BALLRADIUS*radiusmul,30,30);
        glColor3f(0.8, 0.8, 0.8);
}

void display(void){

        glClear(GL_COLOR_BUFFER_BIT);
        glColor4f(0.8, 0.8, 0.8,0.0);
        plotCircle(0,0,ORBITRADIUS);
        plotCircle(0,0,ORBITRADIUS*1.4);
        plotCircle(0,0,ORBITRADIUS*1.9);
        plotCircle(0,0,ORBITRADIUS*2.1);
        plotCircle(0,0,ORBITRADIUS*2.7);
        glPushMatrix();

        z = 0;
        x = ORBITRADIUS * sin(theta);
        y = ORBITRADIUS * cos(theta);
        theta+=0.05;
        glTranslatef(x,y,z);
        glColor3f(0.9, 0.3, 0.2);
        glutSolidSphere(BALLRADIUS*0.5,30,30);
        glColor3f(0.8, 0.8, 0.8);
        glPopMatrix();

        // Venus
        glPushMatrix();
        planet(1.4,10,1.2,0.9,0.5,0.0,0.7);
        glPopMatrix();

        // Earth
        glPushMatrix();
        planet(1.9,10,1.3,0.0,0.2,0.9,0.9);
        glPopMatrix();

        // Mars
        glPushMatrix();
        planet(2.1,8,1.1,1.0,0.2,0.0,0.6);
        glPopMatrix();

        // Jupiter
        glPushMatrix();
        planet(2.7,2,0.5,0.37,0.05,0.0,2.6);
        glPopMatrix();

        glColor3f(0.8, 0.8, 0.0);
        glutSolidSphere(BALLRADIUS*3,30,30);
        
        /*
        glPushMatrix();
        glTranslatef(x+5,y,z);
        glColor3f(0.0, 0.3, 0.2);
        glutSolidSphere(BALLRADIUS,30,30);
        glPopMatrix();
        */
        glFlush();
        // sawp buffers called because we are using double buffering
        // glutSwapBuffers();
}


void reshape(int x, int y){
        if (y == 0 || x == 0) return;
        glMatrixMode(GL_PROJECTION);
        gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
        gluLookAt(11.0, 10.0, 19.0, /* eye is at (0,0,5) */
                  0.0, 0.0, 0.0, /* center is at (0,0,0) */
                  1.0, 1.0, 0.); /* up is in positive Y direction */
}
void Timer(int value) {
        glutPostRedisplay();
        //display();
        glutTimerFunc(40, Timer, 0);
}

int main (int argc, char **argv)
{
        glutInit(&argc, argv);
        glutInitWindowSize(650,650);
        glutCreateWindow("Solid Sphere");
        //GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 0.0};  /* Red diffuse light. */
        float light_position[] = {-1.0, -1.0, -4.0, 0.0}; /* Infinite light location. */
        //glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); // Assigning light diffuse property to GL_LIGHT0 (colour)
        glLightfv(GL_LIGHT0, GL_POSITION, light_position); // Specify position of GL_LIGHT0 at light_position
        glEnable(GL_LIGHT0);                        // Enable GL_LIGHT0
        glEnable(GL_LIGHTING);                      // Enable all lighting
        glEnable(GL_COLOR_MATERIAL);
        glMatrixMode(GL_PROJECTION);
        gluPerspective( /* field of view in degree */ 60.0,
                                                      /* aspect ratio */ 1.0,
                                                      /* Z near */ 1.0, /* Z far */ 500.0);
//    glMatrixMode(GL_MODELVIEW);
        gluLookAt(50.0, 50.0, 50.0, /* eye is at (0,0,5) */
                  0.0, 0.0, 0.0, /* center is at (0,0,0) */
                  0.0, 0.0, 1.0); /* up is in positive Y direction */

//    glutReshapeFunc(reshape);
        glutDisplayFunc(display);
        Timer(0);
        //Timer(0);
        glutMainLoop();
        return 0;
}
