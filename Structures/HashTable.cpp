#include <iostream>
using namespace std;

const int N=100;

struct tablica{
    bool wel;
    bool isel;
    int key;
};



int hash1(int key)
{
    return key%N;
}

int hash2(int key, int i)
{
    return ((hash1(key)+i)%N);
}



void pushh(int key, tablica *&a)
{
    int tmp=hash1(key);
    for(int i=0;i<N && a[tmp].isel!=false;i++)
    {
        tmp=hash2(key,i);

    }
    if(a[tmp].isel==true)
    {cout<<"Nie mpzna dodac elementu, za mala tablica!";return ;}

    a[tmp].key = key;
    a[tmp].isel = true;
    a[tmp].wel = true;
}

void remove(int key, tablica *a)
{int deleted=0;
    int tmp = hash1(key);
    for (int i = 0; i < N && a[tmp].wel != false; i++)
    {
        tmp = hash2(key, i);
        if(a[tmp].key==key)
        {deleted++;
        a[tmp].key = -1;
        a[tmp].isel = false;
        }
}
if(deleted==0)cout<<"Nie bylo takiego elementu";
else cout<<"Usunalem "<< deleted << " elementow";
return;

}

void find(int key, tablica* a)
{
    
    int tmp = hash1(key);
    for (int i = 0; i < N && a[tmp].wel != false; i++)
    {
        tmp = hash2(key, i);
        if (a[tmp].key == key)
        {
            cout<<"Znalazlem element " << key <<endl;
            return ;
          
        }
    }
    cout<<"Nie ma elementu "<<key<<endl;
    return ;
  
    
}

bool findx(int key, tablica *a)
{

    int tmp = hash1(key);
    for (int i = 0; i < N && a[tmp].wel != false; i++)
    {
        tmp = hash2(key, i);
        if (a[tmp].key == key)
        {
            
            return true;
        }
    }
    
    return false;
}

void deleteelement(tablica *a, int tmp)
{
    a[tmp].key = -1;
    a[tmp].isel = false;
    a[tmp].wel = true;
}

void indexy(int tab[], int sum, int n)
{
    tablica *indeksy = new tablica[N];
    for (int tmp = 0; tmp < N; tmp++)
    {

        indeksy[tmp].key = -1;
        indeksy[tmp].isel = false;
        indeksy[tmp].wel = false;
    }

    for(int i=0;i<n;i++)
    {
        int tmp=sum-tab[i];
        if(findx(tmp, indeksy)){
            cout<<tmp<<" + "<<tab[i]<<" ";

        }
        pushh(tab[i], indeksy);
    }
    cout<<endl;
     for (int i = 0; i < N; i++)
        cout << i << " " << indeksy[i].key << endl;
}
int main()
{tablica *a =new tablica[N];





    for (int tmp = 0; tmp < N; tmp++){
       
        a[tmp].key= -1;
        a[tmp].isel = false;
         a[tmp].wel= false;
    }


const int n=10;
int tab[n]={1,4,243,143,2,55,11,709,4,10};
indexy(tab,147, n);
for (int i = 0; i < N; i++)
    delete a[i];
for (int i = 0; i < N; i++)
    cout << i << " " << a[i].key << endl;
}



