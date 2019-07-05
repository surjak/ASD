#include <iostream>
using namespace std;
const int n =10;
void FindIndex(int arr[],int x)
{
    int i=0;int j=n-1;
    while(i<j)
    {
        if(arr[i]+ arr[j]<x)
        i++;
        else if (arr[i] + arr[j]>x)
        j--;
        else if (arr[i] + arr[j] == x)
        break;
    }
    if (arr[i] + arr[j] == x)
        cout << i << " " << j;
        else cout<<"Nie ma takich Indeksow";
}
int main()
{
    int arr[n]={1,2,4,5,6,7,8,44,46,55};
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
        cout<<endl;
        FindIndex(arr,0);
       
}