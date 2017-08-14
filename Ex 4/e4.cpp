/*
 To run in terminal :
 1. g++ X.cpp -lX11 -lGL -lGLU -lglut -g -Wall -O2 -o X
 2. ./X
*/

//All the transformations are wrt the ORIGIN.

#include <iostream>
//#include <glut/glut.h>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include<stdlib.h>
#include<string.h>
#include<boost/lexical_cast.hpp>

#define NUMPOINTS 4
#define H 1
const float PI = 3.14;
float prepoints[NUMPOINTS][2];
float postpoints[NUMPOINTS][2];
float P[3][NUMPOINTS], P1[3][NUMPOINTS];

//Fixed point for rotation.
float xr,yr;

using namespace std;

//Function to convert a float to a string.
std::string Convert (float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}


//Added this function for plotting coordinates but then things got too complex, and I left it out.
void drawBitmapTextSmall(char *string, float x,float y){
	char *c;
	glRasterPos2f(x,y);
	for(c=string;*c!='\0';c++)
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
        for (i = 0; i < 3; i++){
                for (j=0; j<NUMPOINTS; j++)
                        cout <<  newP[i][j] << "\t" ;
                cout <<"\n"<<endl;
        }
}

void rotation(float P[3][NUMPOINTS], float newP[3][NUMPOINTS], float theta)
{

	//Rotation about a fixed point.

        float sinTheta = sin( (theta * PI) / 180);
        float cosTheta = cos( (theta * PI) / 180);

        float rotmatrix[3][3] = {
          {cosTheta ,-1*sinTheta  ,0},
          {sinTheta ,cosTheta     ,0},
          {0        ,0            ,1}
	};

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
                        matrixMul(refmatrix, P, newP);
                        break;
                }
        case 2:{
                        // Reflection along Y Axis
                        float refmatrix[3][3] = {
                          {-1,0,0},
                          { 0,1,0},
                          { 0,0,1}};
                        matrixMul(refmatrix, P, newP);
                        break;
                }
        default:
                cout<<"\nWrong choice";
                break;
        }
}


void shear(float P[3][NUMPOINTS], float newP[3][NUMPOINTS], int ch, float sh)
{
        switch(ch)
        {
        case 1: {
                        // Shearing along X axis
                        float refmatrix[3][3] = {
                          {1,sh,0},
                          {0, 1,0},
                          {0, 0,1}
			};

                        matrixMul(refmatrix, P, newP);
                        break;
                }
        case 2:
                {
                        // Shearing along Y axis
                        float refmatrix[3][3] = {
                          { 1, 0,0},
                          {sh, 1,0},
                          { 0, 0,1}
			};

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
        glClearColor(1.0, 1.0, 1.0, 0.0);
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

        cout<<"\nPlotting quads.\n";
        glBegin(GL_QUADS);

        for(int i=0; i<NUMPOINTS; i++)
                cout<<endl<<points[i][0]<<" "<<points[i][1]<<" ";
	cout<<endl<<endl;

	char s[1000],s1[1000];

        for(int i=0; i<NUMPOINTS; i++){
                glVertex2d( points[i][0], points[i][1]);
	}
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
                reflection(P,P1, ch2);
                break;

        case 5:{
                        cout<<"\nEnter Shearing plane\n1.X axis\n2.Y axis\nEnter choice : ";
                        cin>>ch2;
                        cout<<"\nEnter shear coeff : ";
                        float sh, yref;
			cin>>sh;
			shear(P,P1,ch2,sh);
                    break;
                        }

        default:cout<<"\nWrong choice";
                break;
        }
		cout<<"Points after transformation : "<<endl;
        for (int i=0;i<NUMPOINTS;i++){
                postpoints[i][0] = P1[0][i]/H;
                postpoints[i][1] = P1[1][i]/H;
                cout << postpoints[i][0] << " \t" << postpoints[i][1]<<endl;
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
        
        cout<<"\nEnter prepoints in clockwise order starting from topleft ";
        for(int i=0; i<4; i++){
                cout << "Point "<<i+1<<"\n";
                cout << "x :";
                cin>>prepoints[i][0];
                cout << "y :";
                cin>>prepoints[i][1];
        }
  /*
  prepoints[0][0]=0;
	prepoints[0][1]=0;
	prepoints[1][0]=0;
	prepoints[1][1]=50;
	prepoints[2][0]=50;
	prepoints[2][1]=50;
	prepoints[3][0]=50;
	prepoints[3][1]=0;
  */
        for (int i = 0; i < NUMPOINTS; i++) {
                P[0][i] = prepoints[i][0]*H;    //All the x-coordinates.
                P[1][i] = prepoints[i][1]*H;	//All the y-coordinates.
                P[2][i] = H;
        }

        cout << "\n1.Translation\n2.Rotation\n3.Scale\n4.Reflection\n5.Shearing\nChoice : ";
        cin>>ch;
	      ops(ch);
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(1000, 800);
        glutCreateWindow("T-R-S");
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
