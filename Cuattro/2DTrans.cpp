#include <iostream>
using namespace std;
#define NUMPOINTS 4
#define H 1
int* matmul(int a[3][3],int b[3][1],int c[3][1])  {
  int i, j;
  for (i = 0;i<3;i++)
      c[i][0]=0;
  for (i = 0;i<3;i++)
      for(j=0;j<3;j++)
          c[i][0]=a[i][j]*b[j][0];
}
int main()
{
    float prepoints[NUMPOINTS][2];
    float postpoints[NUMPOINTS][2];
    float P[3][1], P1[3][1];
    float T[3][3];
    int ch;
    cout << "1. Translation\n2.Rotation\n3.Scale\nChoice : ";
    cin>>ch;
    switch (ch) {
      case 1: for (int i = 0;i < NUMPOINTS;i++){
                  P[0][0] = prepoints[i][0]*H;
                  P[1][0] = prepoints[i][1]*H;
                  P[2][0] = H;
                  getMatrix(P,P1);
                  postpoints[i][0] = P1[0][0]/H;
                  postpoints[i][1] = P1[0][1]/H;
              }
              break;
      case 2: for (int i = 0;i < NUMPOINTS;i++){
                  P[0][0] = prepoints[i][0]*H;
                  P[1][0] = prepoints[i][1]*H;
                  P[2][0] = H;
                  getMatrix(P,P1);
                  postpoints[i][0] = P1[0][0]/H;
                  postpoints[i][1] = P1[0][1]/H;
              }
              break;
      case 3: for (int i = 0;i < NUMPOINTS;i++){
                  P[0][0] = prepoints[i][0]*H;
                  P[1][0] = prepoints[i][1]*H;
                  P[2][0] = H;
                  getMatrix(P,P1);
                  postpoints[i][0] = P1[0][0]/H;
                  postpoints[i][1] = P1[0][1]/H;
              }
              break;
      default:cout<<"Wrong choice";break;
    }
    return 0;
}
