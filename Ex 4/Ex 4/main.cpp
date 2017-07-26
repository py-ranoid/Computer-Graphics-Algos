#include <iostream>
//#include <glut/glut.h>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#define NUMPOINTS 4
#define H 1
const float PI = 3.14;
float prepoints[NUMPOINTS][2];
float postpoints[NUMPOINTS][2];
float P[3][NUMPOINTS], P1[3][NUMPOINTS];

using namespace std;

void matrixMul(float feedMatrix[3][3],float P[3][NUMPOINTS],float newP[3][NUMPOINTS])
{
        int i,j,k;
        for (i = 0; i < 3; i++)
                for (j=0; j<NUMPOINTS; j++)
                        newP[i][j] = 0;
        cout << endl;
        /*
        for (i = 0; i < 3; i++){
                for (j=0; j<3; j++)
                        cout <<  feedMatrix[i][j] << "\t" ;
                cout << endl;
        }
        cout << endl;
        for (i = 0; i < 3; i++){
                for (j=0; j<NUMPOINTS; j++)
                        cout <<  P[i][j] << "\t" ;
                cout << endl;
        }
        cout << endl;
        for (i = 0; i < 3; i++){
                for (j=0; j<NUMPOINTS; j++)
                        cout <<  newP[i][j] << "\t" ;
                cout << endl;
        }
        */
        for (k=0; k<NUMPOINTS; k++)
                for(i=0; i<3; i++)
                        for(j=0; j<3; j++)
                                newP[i][k] += feedMatrix[i][j]*P[j][k];
                                //cout <<i<<j<<k<<"\t"<<newP[i][k]<<"\t"<<feedMatrix[i][j]<<"\t"<<P[j][k];
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
        float rotmatrix[3][3] = {
          {cosTheta ,-1*sinTheta  ,0},
          {sinTheta ,cosTheta     ,0},
          {0        ,0            ,1}};

        matrixMul(rotmatrix, P, newP);
}

void translation(float P[3][NUMPOINTS], float newP[3][NUMPOINTS], float tx, float ty)
{
        float transmatrix[3][3] = {
          {1,0,tx},
          {0,1,ty},
          {0,0,1}};
        matrixMul(transmatrix, P, newP);
}

void reflection(float P[3][NUMPOINTS], float newP[3][NUMPOINTS], int ch)
{
        switch(ch)
        {
        case 1:{        // Reflection along X Axis
                        float refmatrix[3][3] = {
                          {1, 0,0},
                          {0,-1,0},
                          {0, 0,1}};

                        //refmatrix[0][0] = 1;
                        //refmatrix[1][1] = -1;
                        matrixMul(refmatrix, P, newP);
                        break;
                }
        case 2:{
                        // Reflection along Y Axis
                        float refmatrix[3][3] = {
                          {-1,0,0},
                          { 0,1,0},
                          { 0,0,1}};

                        //refmatrix[0][0] = -1;
                        //refmatrix[1][1] = 1;
                        matrixMul(refmatrix, P, newP);
                        break;
                }
        default:
                cout<<"\nWrong choice";
                break;
        }
}


void shear(float P[3][NUMPOINTS], float newP[3][NUMPOINTS], int ch, float sh, float yref)
{
        switch(ch)
        {
        case 1: {
                        // Shearing along X axis
                        float refmatrix[3][3] = {
                          {1,sh,-1*sh*yref},
                          {0, 1,         0},
                          {0, 0,         0}};

                        matrixMul(refmatrix, P, newP);
                        break;
                }
        case 2:
                {
                        // Shearing along Y axis
                        float refmatrix[3][3] = {
                          { 1, 0,         0},
                          {sh, 1,-1*sh*yref},
                          { 0, 0,         0}};

                        matrixMul(refmatrix, P, newP);
                        break;
                }
        default:
                cout<<"\nWrong choice";
                break;
        }
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
        glColor3f(c1, c2, c2);
        glPointSize(10);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-500, 500, -400, 400);
}


void originFunc()
{
        // To draw Origin and axes
        glClear(GL_ACCUM_BUFFER_BIT);
        glBegin(GL_LINES);
        glVertex2d(-500, 0);
        glVertex2d(500, 0);
        glVertex2d(0, -400);
        glVertex2d(0, 400);
        glEnd();
}

void displayFunc(float points[NUMPOINTS][2])
{
        // To Print and display quad P
        originFunc();
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
                float tx,ty;
                cout<<"\nEnter Translation along x axis :";
                cin>>tx;
                cout<<"\nEnter Translation along y axis :";
                cin>>ty;
                translation(P, P1, tx, ty);
                break;
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
        case 4:
                cout<<"\nEnter reflection plane\n1.X axis\n2.Y axis\nEnter choice : ";
                int ch2;
                cin>>ch2;
                reflection(P, P1, ch2);
                break;

        case 5:{
                        cout<<"\nEnter Shearing plane\n1.X axis\n2.Y axis\nEnter choice : ";
                        cin>>ch2;
                        cout<<"\nEnter shear coeff and yreff : ";
                        float sh, yref;
                        cin>>sh>>yref;
                        int mx1 =0, mx2 = 0;
                        int my1 =0, my2 = 0;

                        for(int j=1; j<4; j++)
                        {
                                if(prepoints[j][0] > prepoints[mx1][0])
                                {
                                        if(prepoints[mx1][0] > prepoints[mx2][0])
                                        {
                                                mx2 = mx1;
                                        }

                                        mx1 = j;
                                }
                                else if (prepoints[j][0] > prepoints[mx2][0])
                                {
                                        mx2 = j;
                                }
                                if(prepoints[j][1] > prepoints[my1][1])
                                {
                                        if(prepoints[my1][1] > prepoints[my2][1])
                                        {
                                                my2 = my1;
                                        }
                                        my1 = j;
                                }
                                else if (prepoints[j][1] > prepoints[my2][1])
                                {
                                        my2 = j;
                                }
                        }

                        cout<<mx1<<" "<<mx2<<endl;
                        cout<<my1<<" "<<my2<<endl;

                        for (int i = 0; i < NUMPOINTS; i++)
                        {
                                P[0][0] = prepoints[i][0]*H;
                                P[1][0] = prepoints[i][1]*H;
                                P[2][0] = H;

                                if(ch2 == 1)
                                {
                                        if(i == my1 || i == my2)
                                        {
                                                shear(P, P1, ch2, sh, yref);
                                                postpoints[i][0] = P1[0][0]/H;
                                                postpoints[i][1] = P1[1][0]/H;
                                        }
                                        else
                                        {
                                                postpoints[i][0] = P[0][0]/H;
                                                postpoints[i][1] = P[1][0]/H;
                                        }
                                }
                                else
                                {
                                        if(i == mx1 || i == mx2)
                                        {
                                                shear(P, P1, ch2, sh, yref);
                                                postpoints[i][0] = P1[0][0]/H;
                                                postpoints[i][1] = P1[1][0]/H;
                                        }
                                        else
                                        {
                                                postpoints[i][0] = P[0][0]/H;
                                                postpoints[i][1] = P[1][0]/H;
                                        }
                                }
                        }
                        break;
                        }

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
        displayFunc(prepoints);
        glEnd();
        glFlush();
        myInit(255.0, 0.0);
        displayFunc(postpoints);
        glEnd();
        glFlush();
}


void graphicMain(int argc, char* argv[])
{
        int ch;
        cout<<"\nEnter prepoints in clockwise order starting from topleft ";
        for(int i=0; i<4; i++){
                cout << "Point "<<i+1<<"\n";
                cout << "x :";
                cin>>prepoints[i][0];
                cout << "y :";
                cin>>prepoints[i][1];
        }
        for (int i = 0; i < NUMPOINTS; i++) {
                P[0][i] = prepoints[i][0]*H;
                P[1][i] = prepoints[i][1]*H;
                P[2][i] = H;
        }
        cout << "\n1.Translation\n2.Rotation\n3.Scale\n4.Reflection\n5.Shearing\nChoice : ";
        cin>>ch;
        ops(ch);
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(1000, 800);
        glutCreateWindow("T-R-S");
        if (ch > 0 && ch < 6)
                glutDisplayFunc(Func);
        myInit(255.0, 0.0);
        glutMainLoop();
}

int main(int argc,char * argv[])
{
        graphicMain(argc, argv);
}
