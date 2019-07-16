//#include <iostream>
//#include <cstdlib>
#include <bits\stdc++.h>
using namespace std;
const int n = 11;
int partition(int arr[], int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    return i;
}

void quickSort(int arr[], int left, int right)
{
    int index = partition(arr, left, right);
    if (left < index - 1)
        quickSort(arr, left, index - 1);
    if (index < right)
        quickSort(arr, index, right);
}

int insertionSort(int arr[], int a, int b)
{
    if (b - a <= 2)
        return arr[a];
    if (b - a > 1)
    {
        int i, j, tmp;
        for (i = a; i < b; i++)
        {
            j = i;
            while (j > a && arr[j - 1] > arr[j])
            {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
                j--;
            }
        }
        if (b - a >= 4)
            return arr[a + 2];
        if (b - a == 3)
            return arr[a + 1];
    }
}
typedef long long ll;
typedef long double ld;

void Median(int arr[], int length)
{
    int a = length / 5 + 1;
    int *tab = new int[a];
    int j = 0;
    for (int i = 0; i < length; i += 5)
    {
        if (i + 5 <= length)
            tab[j] = insertionSort(arr, i, i + 5);
        else
            tab[j] = insertionSort(arr, i, length);
        j++;
    }

    if (a != 1)
        Median(tab, a);
    else
    {
        cout << tab[0];
        return;
    }

    delete[] tab;
}

void sort5(int *T, int l, int r)
{
    int i = l + 1;
    while (i <= r)
    {
        int j = i;
        while (j > l && T[j - 1] > T[j])
        {
            swap(T[j - 1], T[j]);
            j--;
        }
        i++;
    }
}

int select(int *T, int l, int r, int k)
{
    if ((r - l + 1) <= 5)
    {
        sort5(T, l, r);
        return T[k + l];
    }

    int *X = new int[((r - l + 1) + 4) / 5];
    int c = 0;

    for (int i = l; i <= r; i += 5)
    {
        int j = i + 4;
        if (j > r)
            j = r;
        X[c] = select(T, i, j, (j - i + 1) / 2);
        c++;
    }

    int M = select(X, 0, c - 1, c / 2);

    delete[] X;

    int *L1 = new int[(r - l + 1)];
    int *L2 = new int[(r - l + 1)];
    int *L3 = new int[(r - l + 1)];

    int i1 = -1, i2 = -1, i3 = -1;

    for (int i = l; i <= r; i++)
    {
        if (T[i] < M)
        {
            i1++;
            L1[i1] = T[i];
        }
        else if (T[i] > M)
        {
            i3++;
            L3[i3] = T[i];
        }
        else
        {
            i2++;
            L2[i2] = T[i];
        }
    }

    if (k <= i1)
    {
        int res = select(L1, 0, i1, k);
        delete[] L1;
        delete[] L2;
        delete[] L3;
        return res;
    }
    else if (k > (i1 + i2 + 1))
    {
        int res = select(L3, 0, i3, k - i1 - i2 - 2);
        delete[] L1;
        delete[] L2;
        delete[] L3;
        return res;
    }
    else
    {
        delete[] L1;
        delete[] L2;
        delete[] L3;
        return M;
    }
}

int main()
{
    int arr[n] = {1, 1, 42, 1, 15, 1, 21, 11, 13, 11, 1};

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << endl;
    int m = select(arr, 0, n - 1, (n) / 2);
    cout << m << endl;
    cout << endl
         << endl;
    //quickSort(arr,0,n-1);
    int counter = 0;
    for (int i = 0; i < n; i++)
        (arr[i] == m) ? counter++ : NULL;
    cout << counter << endl;
    cout << (bool)(counter > n / 2);

    return 0;
}