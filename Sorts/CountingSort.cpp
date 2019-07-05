#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N=10;

void CountingSort(int A[], int k)
{int B[N];
    int C[k];
    for(int i=0;i<k;i++)
    C[i]=0;
    for(int j=0;j<N;j++)
    C[A[j]]++;
    for(int i=1;i<k;i++)
    C[i]=C[i]+C[i-1];
    for(int j=N-1;j>=0;j--)
    {   
        C[A[j]]--;
        B[C[A[j]]]=A[j];
    }

    for(int i=0;i<N;i++)
    cout<<B[i]<<" ";
}

void InsertionSort(int tab[], int n)
{
for(int i=1;i<n;i++)
{
    int val=tab[i];
    int j=i;
    while(j>0 && tab[j-1]>val)
    {
        tab[j]=tab[j-1];
        j--;
        for (int i = 0; i < N; i++)
            cout << tab[i] << " ";
            cout<<endl;
    }
    tab[j]=val;
}

}



void SelectionSort(int tab[], int n)
{
    
    for(int j=0;j<n-1;j++)
    {int min=j;
    for(int i=j+1;i<n;i++)
    {
        if(tab[i]<tab[min])
        {
           min=i;
        }
        
    }
    int x=tab[j];
        tab[j]=tab[min];
        tab[min]=x;
    }
}

int main()
{ 
    int k=(N*N);
    srand( time( NULL ) );
    int A[N];
    int B[N];
  for(int i=0;i<N;i++)
   A[i]=rand()%k;
  for (int i = 0; i < N; i++)
      cout << A[i] << " ";
  cout << endl
       << endl;

  InsertionSort(A, N);
  for (int i = 0; i < N; i++)
      cout << A[i] << " ";
      cout<<endl;

  CountingSort(A,k);
}