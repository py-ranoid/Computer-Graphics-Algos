#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include <math.h>
#define MIN 0
#define MAX 2
#define AXISLEN 5
#define H 1
#define NUMPOINTS 8
#define PI 3.14159265358979323846
using namespace std;
GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 0.0};  /* Red diffuse light. */
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};  /* Infinite light location. */
GLfloat n[6][3] = {  /* Normals for the 6 faces of a cube. */
        {-1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0},
        {0.0, -1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, -1.0}
};
GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
        {0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
        {4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3}
};
float v[8][3],v1[8][3];  /* Will be filled in with X,Y,Z vertexes. */
float P[4][NUMPOINTS], P1[4][NUMPOINTS];

void drawBox(int ch)
{
        float vertices[4][NUMPOINTS];
        if (ch == 0){
                glColor3f(0.0f, 1.f, 1.0f);
                for (int i = 0; i < 6; i++) {
                        glBegin(GL_QUADS);
                        glNormal3fv(&n[i][0]);
                        glVertex3fv(&v[faces[i][0]][0]);
                        glVertex3fv(&v[faces[i][1]][0]);
                        glVertex3fv(&v[faces[i][2]][0]);
                        glVertex3fv(&v[faces[i][3]][0]);
                        glEnd();
                }
        }
        else {
                glColor3f(1.0f, 0.5f, 0.0f);
                for (int i = 0; i < 6; i++) {
                        glBegin(GL_QUADS);
                        glNormal3fv(&n[i][0]);
                        glVertex3fv(&v1[faces[i][0]][0]);
                        glVertex3fv(&v1[faces[i][1]][0]);
                        glVertex3fv(&v1[faces[i][2]][0]);
                        glVertex3fv(&v1[faces[i][3]][0]);
                        glEnd();
                }
        }
}

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
void matrixMul(float feedMatrix[4][4],float P[4][NUMPOINTS],float newP[4][NUMPOINTS])
{
        int i,j,k;
        for (i = 0; i < 4; i++)
                for (j=0; j<NUMPOINTS; j++)
                        newP[i][j] = 0;

        cout << endl;
        cout << "P Matrix before multiplication : \n";

        for (i = 0; i < 4; i++) {
                for (j=0; j<NUMPOINTS; j++)
                        cout <<  P[i][j] << "\t";
                cout << endl;
        }

        cout << "Feed Matrix : \n";

        for (i = 0; i < 4; i++) {
                for (j=0; j<4; j++)
                        cout <<  feedMatrix[i][j] << "\t";
                cout << endl;
        }

        for (k=0; k<NUMPOINTS; k++)
                for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                                newP[i][k] += feedMatrix[i][j]*P[j][k];

        cout << "P Matrix after multiplication : \n";
        for (i = 0; i < 4; i++) {
                for (j=0; j<NUMPOINTS; j++)
                        cout <<  newP[i][j] << "\t";
                cout << endl;
        }
}
void translation(float P[3][NUMPOINTS], float newP[3][NUMPOINTS], float tx, float ty, float tz)
{
        float transmatrix[4][4] = {
                {1,0,0,tx},
                {0,1,0,ty},
                {0,0,1,tz},
                {0,0,0, 1}
        };
        matrixMul(transmatrix, P, newP);
}
void scale(float P[3][NUMPOINTS], float newP[3][NUMPOINTS], float sx, float sy, float sz)
{
        float scalematrix[4][4] = {
                {sx,0 ,0 ,0},
                {0 ,sy,0 ,0},
                {0 ,0 ,sz,0},
                {0 ,0 ,0 ,1}
        };
        matrixMul(scalematrix, P, newP);
}
void rotation(float P[3][NUMPOINTS], float newP[3][NUMPOINTS], float theta1, int choice){

        float a = cos(PI*theta1/180.0);
        float b = sin(PI*theta1/180.0);
        cout <<endl<<choice<<endl;
        if(choice == 0 ){
                cout<<"Choice : 0" ;
                float rotmatrix[4][4] = {
                        {a,b,0,0},
                        {-b,a,0,0},
                        {0,0,1,0},
                        {0,0,0,1}
                };
                matrixMul(rotmatrix, P, newP);
        }
        else if(choice == 1){
                cout<<"Choice : 1";
                float rotmatrix[4][4] = {
                        {a,0,b,0},
                        {0,1,0,0},
                        {-b,0,a,0},
                        {0,0,0,1}
                };
                matrixMul(rotmatrix, P, newP);
        }
        else{
                float rotmatrix[4][4] = {
                        {1,0,0,0},
                        {0,a,b,0},
                        {0,-b,a,0},
                        {0,0,0,1}
                };
                matrixMul(rotmatrix, P, newP);
        }
}
void display(void)
{
        glMatrixMode(GL_MODELVIEW);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        drawAxes();
        //glPushMatrix();
        drawBox(0);
        drawBox(1);
        //glPushMatrix();;
        //glTranslatef(-6.0, 0.0, 0.0);
        //glPopMatrix()
        //glPushMatrix();;
        glutSwapBuffers();
}


void init(void)
{
        /* Enable a single OpenGL light. */
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); // Assigning light diffuse property to GL_LIGHT0 (colour)
        glLightfv(GL_LIGHT0, GL_POSITION, light_position); // Specify position of GL_LIGHT0 at light_position
        glEnable(GL_LIGHT0);                            // Enable GL_LIGHT0
        glEnable(GL_LIGHTING);                          // Enable all lighting
        glEnable(GL_COLOR_MATERIAL);
        // Specify a white specular highlight
        const GLfloat white[4] = { 1.f, 1.f, 1.f, 1.f };
        glMaterialfv(GL_FRONT, GL_SPECULAR, white );
        glMaterialf(GL_FRONT, GL_SHININESS, 20.f );
        /* Use depth buffering for hidden surface elimination. */
        glEnable(GL_DEPTH_TEST);

        /* Setup the view of the cube. */
        glMatrixMode(GL_PROJECTION);
        gluPerspective( /* field of view in degree */ 60.0,
                                                      /* aspect ratio */ 1.0,
                                                      /* Z near */ 1.0, /* Z far */ 100.0);
        glMatrixMode(GL_MODELVIEW);
        gluLookAt(8.0, 10.0, 10.0, /* eye is at (0,0,5) */
                  0.0, 0.0, 0.0,  /* center is at (0,0,0) */
                  0.0, 1.0, 0.);  /* up is in positive Y direction */

        /* Adjust cube position to be asthetic angle. */
        //glMatrixMode(GL_PROJECTION);
        //glRotatef(60, 1.0, 0.0, 0.0);
        //glRotatef(-20, 0.0, 0.0, 1.0);
}

void ops(){
        /* Setup cube vertex data. */
        // Setting X axis
        int ch;
        v[0][0] = v[1][0] = v[2][0] = v[3][0] = MIN;      // Left
        v[4][0] = v[5][0] = v[6][0] = v[7][0] = MAX;       // Right
        // Setting Y axis
        v[0][1] = v[1][1] = v[4][1] = v[5][1] = MIN;      // Bottom
        v[2][1] = v[3][1] = v[6][1] = v[7][1] = MAX;       // Top
        // Setting Z axis
        v[1][2] = v[2][2] = v[5][2] = v[6][2] = MIN;      // Back
        v[0][2] = v[3][2] = v[4][2] = v[7][2] = MAX;       // Front
        for (int i =0; i<NUMPOINTS; i++) {
                P[0][i]=v[i][0]*H;
                P[1][i]=v[i][1]*H;
                P[2][i]=v[i][2]*H;
                P[3][i]=H;
        }
        cout << "1. Translation \n2.Scaling\n3.Rotation\nChoice : ";
        cin >> ch;
        switch (ch){
                case 1  : int tx,ty,tz;
                          cout << "\nTranslation along X : ";cin >>tx;
                          cout << "\nTranslation along Y : ";cin >>ty;
                          cout << "\nTranslation along Z : ";cin >>tz;
                          translation(P,P1,tx,ty,tz);
                          break;
                case 2 :  int sx,sy,sz;
                          cout << "\nScale along X : ";cin >>sx;
                          cout << "\nScale along Y : ";cin >>sy;
                          cout << "\nScale along Z : ";cin >>sz;
                          scale(P,P1,sx,sy,sz);
                          break;
                case 3:   float r;
                          int axis_ch;
                          axis_ch =0;
                          cout<<" \nEnter the axis of rotation (0/1/2): ";cin>>axis_ch;
                          cout<<" \nEnter Theta : ";cin>>r;
                          if (axis_ch >=0 && axis_ch<=3)
                                rotation(P,P1,r,axis_ch);
                          break;
                default : cout << "Wrong choice";
        }
        for (int i =0; i<NUMPOINTS; i++) {
                v1[i][0]=P1[0][i]/H;
                v1[i][1]=P1[1][i]/H;
                v1[i][2]=P1[2][i]/H;
        }

}
int main(int argc, char **argv)
{
        ops();
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(600, 600);
        glutCreateWindow("3D Transformation");
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glutDisplayFunc(display);
        init();
        glutMainLoop();
        return 0;         /* ANSI C requires main to return int. */
}
