#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int part2(int tab[], int pocz, int kon)
{
    int i=pocz, j=kon, tmp=tab[(pocz+kon)/2];
    while(i<=j)
    {
        while(tab[i]<tmp)
        i++;
        while(tab[j]>tmp)
        j--;
        if(i<=j)
        {
            int a=tab[i];
            tab[i]=tab[j];
            tab[j]=a;
            i++;j--;
        }
    }
    return i;
}

void qSort(int arr[], int p, int k)
{
    int q=part2(arr,p,k);
    if (p < q-1) 
            qSort(arr, p,q-1); 
      if (q < k) 
            qSort(arr, q, k); 
}















int partition(int arr[], int left, int right) 
{ 
      int i = left, j = right; 
      int tmp; 
      int pivot = arr[(left + right) / 2]; 
      
      while (i <= j) { 
            while (arr[i] < pivot) 
                  i++; 
            while (arr[j] > pivot) 
                  j--; 
            if (i <= j) { 
                  tmp = arr[i]; 
                  arr[i] = arr[j]; 
                  arr[j] = tmp; 
                  i++; 
                  j--; 
            } 
      }; 
      
      return i; 
} 
 
void quickSort(int arr[], int left, int right) { 
      int index = partition(arr, left, right); 
      if (left < index - 1) 
            quickSort(arr, left, index - 1); 
      if (index < right) 
            quickSort(arr, index, right); 
}

int main()
{srand( time( NULL ) );
    int arr[100];
      for(int i=0;i<100;i++)
    arr[i]=rand()%100;
    cout<<endl<<endl;
    qSort(arr,0,99);
    for(int i=0;i<100;i++)
    cout<<arr[i]<<" ";
}