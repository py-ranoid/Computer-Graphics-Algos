 #include "GL/freeglut.h"
 #include "GL/gl.h"
#define MIN 0
#define MAX 3
GLfloat light_diffuse[] = {0.0, 0.0, 1.0, 0.0};  /* Red diffuse light. */
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};  /* Infinite light location. */
GLfloat n[6][3] = {  /* Normals for the 6 faces of a cube. */
    {-1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0},
    {0.0, -1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, -1.0} };
GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
    {0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
    {4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3} };
float v[8][3];  /* Will be filled in with X,Y,Z vertexes. */
float vT[3][];  /* Will be filled in with X,Y,Z vertexes. */

void drawBox(void)
{
    int i;
    for (i = 0; i < 6; i++) {
        glBegin(GL_QUADS);
        glNormal3fv(&n[i][0]);
        glVertex3fv(&v[faces[i][0]][0]);
        glVertex3fv(&v[faces[i][1]][0]);
        glVertex3fv(&v[faces[i][2]][0]);
        glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
    }
}

void drawAxes()
{
        glBegin(GL_LINES);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(0.0,0.0,4.5);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(0.0,4.5,0.0);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(4.5,0.0,0.0);
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
void transpose(float newP[3][NUMPOINTS],float P[NUMPOINTS][3]){
        for(i=0; i<NUMPOINTS; i++)
	{
		for(j=0; j<3; j++)
		{
			newP[j][i]=P[i][j];
		}
	}
}
void display(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawAxes();
    //glPushMatrix();
    drawBox();
    //glPushMatrix();;
    //glTranslatef(-6.0, 0.0, 0.0);
    transpose()
    //glPopMatrix()
    //glPushMatrix();;
    glutSwapBuffers();
}

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
void translation(float P[3][NUMPOINTS], float newP[3][NUMPOINTS], float tx, float ty, float ty)
{
        float transmatrix[4][4] = {
          {1,0,0,tx},
          {0,1,1,ty},
          {0,0,1,tz},
          {0,0,0, 1}};
        matrixMul(transmatrix, P, newP);
}

void init(void)
{
    /* Setup cube vertex data. */
    // Setting X axis
    v[0][0] = v[1][0] = v[2][0] = v[3][0] = MIN;      // Left
    v[4][0] = v[5][0] = v[6][0] = v[7][0] = MAX;       // Right
    // Setting Y axis
    v[0][1] = v[1][1] = v[4][1] = v[5][1] = MIN;      // Bottom
    v[2][1] = v[3][1] = v[6][1] = v[7][1] = MAX;       // Top
    // Setting Z axis
    v[1][2] = v[2][2] = v[5][2] = v[6][2] = MIN;      // Back
    v[0][2] = v[3][2] = v[4][2] = v[7][2] = MAX;       // Front

    /* Enable a single OpenGL light. */
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);    // Assigning light diffuse property to GL_LIGHT0 (colour)
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);  // Specify position of GL_LIGHT0 at light_position
    glEnable(GL_LIGHT0);                                // Enable GL_LIGHT0
    glEnable(GL_LIGHTING);                              // Enable all lighting

    /* Use depth buffering for hidden surface elimination. */
    glEnable(GL_DEPTH_TEST);

    /* Setup the view of the cube. */
    glMatrixMode(GL_PROJECTION);
    gluPerspective( /* field of view in degree */ 80.0,
                   /* aspect ratio */ 1.0,
                   /* Z near */ 1.0, /* Z far */ 10.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(5.0, 5.0, 5.0,  /* eye is at (0,0,5) */
              1.0, 1.0, 1.0,      /* center is at (0,0,0) */
              0.0, 1.0, 0.);      /* up is in positive Y direction */

    /* Adjust cube position to be asthetic angle. */
    //glMatrixMode(GL_PROJECTION);
    //glRotatef(60, 1.0, 0.0, 0.0);
    //glRotatef(-20, 0.0, 0.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("red 3D lighted cube");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}
