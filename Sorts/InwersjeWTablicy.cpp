#include<iostream>
using namespace std; 
int main()
{
    int tab[8]={10,31111,71,31,81,29,1,15};
    int counter=0;
    for(int i=0;i<8;i++)
    for(int j=i+1;j<8;j++)
    {
        if(tab[i]>tab[j])
        counter++;
    }
    cout<<counter;

}