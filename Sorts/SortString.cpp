#include<iostream>
#include<string>
using namespace std;
struct dane{
    string imie;
    int wiek;
};
void swap(dane &a, dane &b)
{
    dane tmp=a;
    a=b;
    b=tmp;
    
}
int main()
{
    dane A[3];
   A[0].imie="Ala";
   A[0].wiek=20;
   A[1].imie = "MAteusz";
   A[1].wiek = 19;
   A[2].imie = "magda";
   A[2].wiek = 5;

   swap(A[0],A[2]);
   cout << A[0].imie<<" "<<A[0].wiek;
   
}