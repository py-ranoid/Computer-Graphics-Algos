/*
 To run in terminal :
 1. g++ X.cpp -lX11 -lGL -lGLU -lglut -g -Wall -O2 -o X
 2. ./X
*/
#include <iostream>
//#include <glut/glut.h>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#define NUMPOINTS 8
#define H 1
const float PI = 3.14;
float prepoints[NUMPOINTS][2];
float postpoints[NUMPOINTS][2];
float sqpoints[NUMPOINTS][2];
float P[4][NUMPOINTS], P1[4][NUMPOINTS];
//Fixed point for rotation.
float xr,yr;

using namespace std;

void matrixMul(float feedMatrix[4][4],float P[3][NUMPOINTS],float newP[3][NUMPOINTS])
{
        int i,j,k;
        for (i = 0; i < 3; i++)
                for (j=0; j<NUMPOINTS; j++)
                        newP[i][j] = 0;
        cout << endl;

        for (k=0; k<NUMPOINTS; k++)
                for(i=0; i<3; i++)
                        for(j=0; j<3; j++)
                                newP[i][k] += feedMatrix[i][j]*P[j][k];

        cout << "P Matrix after multiplication : ";
        for (i = 0; i < 3; i++){
                for (j=0; j<NUMPOINTS; j++)
                        cout <<  newP[i][j] << "\t" ;
                cout << endl;
        }
}

void rotation(float P[3][NUMPOINTS], float newP[3][NUMPOINTS], float theta)
{
        float sinTheta = sin( theta * PI / 180);
        float cosTheta = sin( theta * PI / 180);
	xr = -1 * prepoints[3][0];
	yr = -1 * prepoints[3][1];
        float rotmatrix[3][3] = {
          {cosTheta ,-1*sinTheta  ,xr*(cosTheta - 1) - (yr*sinTheta)},
          {sinTheta ,cosTheta     ,yr*(cosTheta - 1) + (xr*sinTheta)},
          {0        ,0            ,1}};

        matrixMul(rotmatrix, P, newP);
}

void translation(float P[3][NUMPOINTS], float newP[3][NUMPOINTS], float tx, float ty)
{
        float transmatrix[4][4] = {
          {1,0,0,tx},
          {0,1,1,ty},
          {0,0,1,tz},
          {0,0,0, 1}};
        matrixMul(transmatrix, P, newP);
}

void scaling(float P[3][NUMPOINTS], float newP[3][NUMPOINTS], float sx, float sy)
{
        float scalematrix[3][3] = {
          {sx,0,0},
          {0,sy,0},
          {0,0,1}};
        matrixMul(scalematrix, P, newP);
}

void myInit(float c1 = 1.0, float c2 = 1.0)
{
        glClearColor(0.0, 0.0, 0.0, 0.0);
        //glClear(GL_COLOR_BUFFER_BIT);
        //glColor3f(c1, c2, c2);
        glPointSize(10);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-500, 500, -400, 400);
}


void originFunc()
{
        // To draw Origin and axes
        glBegin(GL_LINES);
        glVertex2d(-500, 0);
        glVertex2d(500, 0);
        glVertex2d(0, -400);
        glVertex2d(0, 400);
        glEnd();
	glFlush();
}

void displayFunc(float points[NUMPOINTS][2])
{

        cout<<"plotting quads";
        glBegin(GL_QUADS);

        for(int i=0; i<NUMPOINTS; i++)
                cout<<endl<<points[i][0]<<" "<<points[i][1];

        for(int i=0; i<NUMPOINTS; i++)
                glVertex2d( points[i][0], points[i][1]);

}

void ops(int ch)
{
        switch (ch) {
        case 1:
                float tx,ty,tz;
                cout<<"\nEnter Translation along x axis :";
                cin>>tx;
                cout<<"\nEnter Translation along y axis :";
                cin>>ty;
                cout<<"\nEnter Translation along z axis :";
                cin>>tz;
                translation(P, P1, tx, ty, tz);
                break;
	//Rotation about a fixed point. (xr, yr) : left-corner point of the quad.
        case 2:
                float theta;
                cout<<"\nEnter theta value :";
                cin>>theta;
                rotation(P, P1, theta);
                break;
        case 3:
                float sx, sy;
                cout<<"\nEnter Scale along x axis :";
                cin>>sx;
                cout<<"\nEnter Scale along y axis :";
                cin>>sy;
                scaling(P, P1, sx, sy);
                break;

        default:cout<<"\nWrong choice";
                break;
        }
        for (int i=0;i<NUMPOINTS;i++){
                postpoints[i][0] = P1[0][i]/H;
                postpoints[i][1] = P1[1][i]/H;
                cout << postpoints[i][0] << " \t" << postpoints[i][1];
        }
}
void Func()
{
	originFunc();
	myInit(255.0,0.0);
        glColor3f(0.0f,1.0f,1.0f);
        displayFunc(prepoints);
        glEnd();
        glFlush();

        myInit(255.0, 0.0);
        glColor3f(0.0f,0.0f,1.0f);
        displayFunc(postpoints);
        glEnd();
        glFlush();
}


void graphicMain(int argc, char* argv[])
{
        int ch;
        /*
        cout<<"\nEnter prepoints in clockwise order starting from topleft ";
        for(int i=0; i<4; i++){
                cout << "Point "<<i+1<<"\n";
                cout << "x :";
                cin>>prepoints[i][0];
                cout << "y :";
                cin>>prepoints[i][1];
        } */
	sqpoints[0][0]=-20;
	sqpoints[0][1]=-20;
	sqpoints[1][0]=50;
	sqpoints[1][1]=50;
	sqpoints[2][0]=50;
	sqpoints[2][1]=5;
	sqpoints[3][0]=5;
	sqpoints[3][1]=5;
        prepoints = {
                {-20,20,-20,20,-20,20,-20,20},
                {-20,-20,20,20,-20,-20,20,20},
                {-20,-20,-20,-20,20,20,20,20},
        }
        for (int i = 0; i < NUMPOINTS; i++) {
                P[0][i] = prepoints[i][0]*H;
                P[1][i] = prepoints[i][1]*H;
                P[2][i] = prepoints[i][1]*H;
                p[3][i] = H;
        }
        cout << "\n1.Translation\n2.Rotation\n3.Scale\n4.Reflection\n5.Shearing\nChoice : ";
        cin>>ch;
        ops(ch);
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(1000, 800);
        glutCreateWindow("T-R-S");
	//Set the inital color of everything.
 	glColor3f(1.0f,0.0f,0.0f);
        if (ch > 0 && ch < 6)
                glutDisplayFunc(Func);
        myInit(255.0, 0.0);
        glutMainLoop();
}

int main(int argc,char * argv[])
{
        graphicMain(argc, argv);
}
