#include <iostream>
using namespace std;
const int K=4, N=9;
int tab[4][9]={
2,1,6,0,0,0,0,0,0,
3,0,2,4,0,0,0,0,0,
2,1,7,0,0,0,0,0,0,
1,5,0,0,0,0,0,0,0

};

void PrintArray(int *array, int n) {
  for (int i = 0; i < n; ++i)
cout << array[i] << " " ;
cout <<endl;
}

void merge( int tab[K][N], int w1, int w2, int k1)
{int *temp = new int[tab[w1][0]+tab[w2][0]];
int size=tab[w1][0]+tab[w2][0];
int i=1; int j=1;int wk=0;
while(tab[w1][0]!=0 && tab[w2][0]!=0)
{
    if(tab[w1][i]<=tab[w2][j])
    {temp[wk]=tab[w1][i];
    i++;tab[w1][0]--;}
    else
    {temp[wk]=tab[w2][j];j++; tab[w2][0]--;}
    wk++;
}
while(tab[w1][0]!=0)
{
    temp[wk]=tab[w1][i];
    i++;tab[w1][0]--;
    wk++;
}
while(tab[w2][0]!=0)
{
    temp[wk]=tab[w2][j];
    i++;tab[w2][0]--;
    wk++;
}
tab[k1][0]=size;
for(int i=1; i<=size; i++)
tab[k1][i]=temp[i-1];  

delete []temp;

}
 
 void tablice( int tab[K][N],int &kol)
 {bool flag=false;
     if(tab[0][0]==N-1)
     {for(int i=1;i<=N-1;i++)
     cout<<tab[0][i];
     return;}

     if(kol%2==1)
     {flag=true;
         kol=kol/2;
     }
     int k=0;
for(int i=0; i<=kol; i=i+2)
{
    merge(tab,i,i+1,k);
    k++;
}
if(flag==true)
{for(int i=0;i<=tab[2*kol+1][0]; i++)
tab[kol+1][i]=tab[2*kol+1][i];
}
tablice(tab,kol);
 }

 
int main() {int kol=K;
 //merge(tab,0,1,0);
 tablice(tab,kol);
for(int j=0;j<K;j++)
 {cout<<endl;
   for(int i=0;i<N;i++)   
 cout<<tab[j][i]<<" ";}
  return (0);
}