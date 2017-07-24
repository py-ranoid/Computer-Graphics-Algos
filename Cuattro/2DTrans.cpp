#include

int* matmul(int a[],int b[],int r1,int c1,int r2,int c2)  {
  int mult[10][10];
  int i, j, k;

  for(i = 0; i < r1; ++i)
      for(j = 0; j < c2; ++j)
          mult[i][j]=0;

  return(mult)
}
int main(w)
{

    // Displaying the multiplication of two matrix.
    cout << endl << "Output Matrix: " << endl;
    for(i = 0; i < r1; ++i)
    for(j = 0; j < c2; ++j)
    {
        cout << " " << mult[i][j];
        if(j == c2-1)
            cout << endl;
    }

    return 0;
}
