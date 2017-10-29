#include <iostream>
//#include <glut/glut.h>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define NUMPOINTS 4
#define H 1
const float PI = 3.14;
float prepoints[NUMPOINTS][2];
float postpoints[NUMPOINTS][2];
float P[3][NUMPOINTS], P1[3][NUMPOINTS];

//Fixed point for rotation.
float xr,yr;

using namespace std;

//Function for plotting coordinates onto the screen.
void drawBitmapTextSmall(char *string, float x,float y){
        char *c;
        glRasterPos2f(x,y);
        for(c=string; *c!='\0'; c++)
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*c);
}

void matrixMul(float feedMatrix[3][3],float P[3][NUMPOINTS],float newP[3][NUMPOINTS])
{
        int i,j,k;

        //Initialization of newP[] to 0.
        for (i = 0; i < 3; i++)
                for (j=0; j<NUMPOINTS; j++)
                        newP[i][j] = 0;
        cout <<"\n"<<endl;

        //Multiplication of the matrices, to get the new positions.
        for (k=0; k<NUMPOINTS; k++)
                for(i=0; i<3; i++)
                        for(j=0; j<3; j++)
                                newP[i][k] += feedMatrix[i][j]*P[j][k];

        cout << "P Matrix after multiplication : "<<endl;
        //Dimensions of newP : 3 x 4 matrix, for all the four points.
        //Each point vector is arranged column-wise.
        for (i = 0; i < 3; i++) {
                for (j=0; j<NUMPOINTS; j++)
                        cout <<  newP[i][j] << "\t";
                cout <<endl;
        }
}

void rotation(float P[3][NUMPOINTS], float newP[3][NUMPOINTS], float theta)
{

        //Rotation about a fixed point.
        float sinTheta = sin( (theta * PI) / 180);
        float cosTheta = cos( (theta * PI) / 180);
        cout<<endl<<"Enter the fixed point(X,Y) : "<<endl;
        cin>>xr>>yr;

        float sx,sy;
        cout<<endl<<"Enter the scale factors : "<<endl;
        cin>>sx>>sy;
        float rotmatrix[3][3] = {
                {sx*cosTheta,-1*sy*sinTheta,-1*xr*sx*cosTheta + yr*sy*sinTheta + xr},
                {sx*sinTheta,sy*cosTheta,-1*xr*sx*sinTheta - yr*sy*cosTheta + yr},
                {0,0,1}
        };

        matrixMul(rotmatrix, P, newP);
}

void reflection(float P[3][NUMPOINTS], float newP[3][NUMPOINTS], int ch)
{

        float sh;
        cout<<"Enter the shearing factor : "<<endl;
        cin>>sh;

        switch(ch)
        {
        case 1: {        // Reflection along X Axis
                float refmatrix[3][3] = {
                        {1, sh,0},
                        {0,-1,0},
                        {0, 0,1}
                };

                //refmatrix[0][0] = 1;
                //refmatrix[1][1] = -1;
                matrixMul(refmatrix, P, newP);
                break;
        }
        case 2: {
                // Reflection along Y Axis
                float refmatrix[3][3] = {
                        {-1,0,0},
                        { sh,1,0},
                        { 0,0,1}
                };

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

void myInit(float c1 = 1.0, float c2 = 1.0)
{
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        //glColor3f(c1, c2, c2);
        glPointSize(10);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-250, 250, -250, 250);
}

void ops(int ch)
{
        int ch2;
        switch (ch) {
        case 1: {
                float theta;
                cout<<"\nEnter theta value :";
                cin>>theta;
                rotation(P, P1, theta);
                break;
        }
        case 2: {
                cout<<"\nEnter reflection plane\n1.X axis\n2.Y axis\nEnter choice : ";
                cin>>ch2;
                reflection(P,P1, ch2);
                break;
        }
        default: cout<<"\nWrong choice";
                break;
        }
        cout<<"Points after transformation : "<<endl;
        for (int i=0; i<NUMPOINTS; i++) {
                postpoints[i][0] = P1[0][i]/H;
                postpoints[i][1] = P1[1][i]/H;
                cout << postpoints[i][0] << " \t" << postpoints[i][1]<<endl;
        }
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

        glBegin(GL_QUADS);
        for(int i=0; i<NUMPOINTS; i++)
                glVertex2d( points[i][0], points[i][1]);
        glEnd();
        glFlush();
}

void Func()
{
        glColor3f(0.0f,0.0f,0.0f);
        originFunc();
        glColor3f(0.0f,1.0f,0.0f);
        displayFunc(prepoints);
//        myInit(255.0, 0.0);
        glColor3f(0.0f,0.0f,1.0f);
        displayFunc(postpoints);
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
           }
         */

        prepoints[0][0]=0;
        prepoints[0][1]=0;
        prepoints[1][0]=0;
        prepoints[1][1]=50;
        prepoints[2][0]=50;
        prepoints[2][1]=50;
        prepoints[3][0]=50;
        prepoints[3][1]=0;

        for (int i = 0; i < NUMPOINTS; i++) {
                P[0][i] = prepoints[i][0]*H;    //All the x-coordinates.
                P[1][i] = prepoints[i][1]*H;    //All the y-coordinates.
                P[2][i] = H;
        }

        cout << "1.Rotation and Scaling. \n2.Reflection and Shearing. \nChoice : ";
        cin>>ch;
        ops(ch);
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutCreateWindow("T-R-S");
        glColor3f(1.0f,0.0f,0.0f);
        myInit(255.0, 0.0);
        if (ch > 0 && ch < 6)
                glutDisplayFunc(Func);
        glutMainLoop();
}

int main(int argc,char * argv[])
{
        graphicMain(argc, argv);
}
