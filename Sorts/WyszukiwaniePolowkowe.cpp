#include<iostream>
using namespace std;
int swap(int &a, int &b)
{
    int tmp=a;
    a=b;
    b=tmp;
}
int partition(int tab[], int l, int r)
{
    int pivot=tab[r];
    int j=l;
    for(int i=l;i<r;i++)
    {
        if(tab[i]<=pivot)
        {
            swap(tab[i], tab[j]);
            j++;
        }
    }
    swap(tab[j], tab[r]);
    return j;
}

int Kath(int tab[], int l, int r, int el)
{if(l<=r){
   int a=partition(tab,l,r);
    if(a==el)
    return tab[a];

    if(a<el)
    return Kath(tab,a+1,r,el);
    else 
    return Kath(tab,l,a-1,el);
}
   


}

int main()
{int n=10;
    int arr[n] = {1,5,2,3,0,6,2,12,55,1};
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout<<Kath(arr,0,n-1,0);
}