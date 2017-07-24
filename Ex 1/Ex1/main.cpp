//
//  main.cpp
//  Ex1
//
//  Created by Sundararaman on 19/06/17.
//  Copyright © 2017 Sundararaman. All rights reserved.
//

#include <iostream>
#include<glut/glut.h>

void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void Points()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glVertex2d(150, 100);
    glVertex2d(200, 200);
    glVertex2d(250, 300);
    glEnd();
    glFlush();
}

void Lines()
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
    glVertex2d(250 , 200);
    glVertex2d(300, 200);
    glVertex2d(300, 250);
    
    glVertex2d(250  , 250);
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
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Exercice 1");
    glutDisplayFunc(line_loop);
//    glutDisplayFunc(quads);
    myInit();
    glutMainLoop();
    return 1;
    
}
