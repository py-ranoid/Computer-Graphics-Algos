//
//  main.cpp
//  Ex 4
//
//  Created by Sundararaman on 24/07/17.
//  Copyright © 2017 Sundararaman. All rights reserved.
//

#include <iostream>
#include<glut/glut.h>
#include <math.h>
#define NUMPOINTS 4
#define H 1
const float PI = 3.14;

using namespace std;

void myInit(float c1 = 1.0 , float c2 = 1.0)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(c1, c2 , c2);
    glPointSize(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -400, 400);
}


void matrixMul(float feedMatrix[3][3] ,float P[3][1] ,float newP[3][1])
{
    int i,j;
    for (i = 0 ; i < 3 ; i++)
        newP[i][0] = 0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            newP[i][0] += feedMatrix[i][j]*P[j][0];
}

void rotation(float P[3][1] , float theta , float newP[3][1])
{
    float rotmatrix[3][3] = {{0,0,0} , {0,0,0} , {0,0,1}};
    float sinTheta = sin( theta * PI / 180);
    float cosTheta = sin( theta * PI / 180);
    rotmatrix[0][0] = cosTheta;
    rotmatrix[0][1] = -1 * sinTheta;
    rotmatrix[1][0] = sinTheta;
    rotmatrix[1][1] = cosTheta;
    matrixMul(rotmatrix , P , newP);
}

void translation(float P[3][1] , float tx , float ty , float newP[3][1])
{
    float transmatrix[3][3] = {{1,0,tx} , {0,1,ty} , {0,0,1}};
    matrixMul(transmatrix , P , newP);
}

void reflection(float P[3][1] , float newP[3][1] , int ch)
{
    float refmatrix[3][3] = {0,0,0,0,0,0,0,0,1};

    switch(ch)
    {
        case 1:
            refmatrix[0][0] = 1;
            refmatrix[1][1] = -1;
            matrixMul(refmatrix, P, newP);
            break;
        case 2:
            refmatrix[0][0] = -1;
            refmatrix[1][1] = 1;
            matrixMul(refmatrix, P, newP);
            break;
        default:
            cout<<"\nEnter valid choice";
            break;
    }
}


void shear(float P[3][1] , float newP[3][1] , int ch ,float sh, float yref)
{
    float refmatrix[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    
    switch(ch)
    {
        case 1:
            refmatrix[0][1] = sh;
            refmatrix[0][2] = -1*sh*yref;
            matrixMul(refmatrix, P, newP);
            break;
        case 2:
            refmatrix[1][0] = sh;
            refmatrix[1][2] = -1*sh*yref;
            matrixMul(refmatrix, P, newP);
            break;
        default:
            cout<<"\nEnter valid choice";
            break;
    }
}

void scaling(float P[3][1] , float sx , float sy , float newP[3][1])
{
    float scalematrix[3][3] = {{sx,0,0} , {0,sy,0} , {0,0,1}};
    matrixMul(scalematrix , P , newP);
}

void originFunc()
{
    glClear(GL_ACCUM_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2d(-500, 0);
    glVertex2d(500, 0);
    glVertex2d(0 , -400);
    glVertex2d(0 , 400);
    glEnd();
}

void displayFunc(float P[4][2])
{
    originFunc();
    cout<<"plotting quads";
    glBegin(GL_QUADS);
    
    for(int i=0;i<4;i++)
        cout<<endl<<P[i][0]<<" "<<P[i][1];
    
    for(int i=0;i<4;i++)
        glVertex2d( P[i][0], P[i][1]);

}



void Func()
{
    float prepoints[NUMPOINTS][2];
    float postpoints[NUMPOINTS][2];
    float P[3][1], P1[3][1];
    int ch;
    cout<<"\nEnter prepoints (x y): ";
    for(int i=0;i<4;i++)
        cin>>prepoints[i][0]>>prepoints[i][1];
    
    displayFunc(prepoints);
    glEnd();
    glFlush();
    
    cout << "\n1.Translation\n2.Rotation\n3.Scale\n4.Reflection\n5.Shearing\nChoice : ";
    cin>>ch;
    
    switch (ch) {
        case 1:
            float tx,ty;
            cout<<"\nEnter tx and ty";
            cin>>tx>>ty;
            for (int i = 0;i < NUMPOINTS;i++){
            P[0][0] = prepoints[i][0]*H;
            P[1][0] = prepoints[i][1]*H;
            P[2][0] = H;
            translation(P, tx, ty, P1);
            postpoints[i][0] = P1[0][0]/H;
            postpoints[i][1] = P1[1][0]/H;
        }
            break;
        case 2:
            float theta;
            cout<<"\nEnter theta value";
            cin>>theta;
            for (int i = 0;i < NUMPOINTS;i++){
            P[0][0] = prepoints[i][0]*H;
            P[1][0] = prepoints[i][1]*H;
            P[2][0] = H;
            rotation(P, theta, P1);
            postpoints[i][0] = P1[0][0]/H;
            postpoints[i][1] = P1[1][0]/H;
        }
            break;
        case 3:
            float sx , sy;
            cout<<"\nEnter sx and sy";
            cin>>sx>>sy;
            for (int i = 0;i < NUMPOINTS;i++){
            P[0][0] = prepoints[i][0]*H;
            P[1][0] = prepoints[i][1]*H;
            P[2][0] = H;
            
            scaling(P , sx , sy , P1);
            postpoints[i][0] = P1[0][0]/H;
            postpoints[i][1] = P1[1][0]/H;
        }
            break;
        case 4:
            cout<<"\nEnter reflection plane\n1.X axis\n2.Y axis\nEnter choice : ";
            int ch2;
            cin>>ch2;
            for (int i = 0;i < NUMPOINTS;i++){
                P[0][0] = prepoints[i][0]*H;
                P[1][0] = prepoints[i][1]*H;
                P[2][0] = H;
                reflection(P , P1 , ch2);
                postpoints[i][0] = P1[0][0]/H;
                postpoints[i][1] = P1[1][0]/H;
            }
            break;
            
        case 5:
            cout<<"\nEnter reflection plane\n1.X axis\n2.Y axis\nEnter choice : ";
            cin>>ch2;
            cout<<"\nEnter shear coeff and yreff : ";
            float sh , yref;
            cin>>sh>>yref;
            int mx1 =0 , mx2 = 0;
            int my1 =0 , my2 = 0;
            
            for(int j=1;j<4;j++)
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

            for (int i = 0;i < NUMPOINTS;i++)
            {
                P[0][0] = prepoints[i][0]*H;
                P[1][0] = prepoints[i][1]*H;
                P[2][0] = H;
                
                if(ch2 == 1)
                {
                    if(i == my1 || i == my2)
                    {
                        shear(P , P1 , ch2 , sh , yref);
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
                        shear(P , P1 , ch2 , sh , yref);
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

    if(ch > 0 && ch < 6)
    {
        myInit(255.0 , 0.0);
        displayFunc(postpoints);
        glEnd();
        glFlush();
    }
    
}


void graphicMain(int argc , char* argv[])
{
    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("T-R-S");
    glutDisplayFunc(Func);
    myInit();
    glutMainLoop();
}

int main(int argc,char * argv[])
{
    graphicMain(argc , argv);
}
