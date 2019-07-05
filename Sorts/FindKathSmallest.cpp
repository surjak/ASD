#include <stdio.h>
#include <iostream>
using namespace std;
#define SWAP(x, y)    \
    {                 \
        int temp = x; \
        x = y;        \
        y = temp;     \
    }
#define N (sizeof(A) / sizeof(A[0]))

int partition(int a[], int left, int right, int pivotIndex)
{

    int pivot = a[pivotIndex];

    SWAP(a[pivotIndex], a[right]);

    int pIndex = left;
    int i;
    for (i = left; i < right; i++)
    {
        if (a[i] <= pivot)
        {
            SWAP(a[i], a[pIndex]);
            pIndex++;
        }
    }

    SWAP(a[pIndex], a[right]);

    return pIndex;
}

int quickselect(int A[], int left, int right, int k)
{

    if (left == right)
        return A[left];

    int pivotIndex = left + rand() % (right - left + 1);

    pivotIndex = partition(A, left, right, pivotIndex);

    if (k == pivotIndex)
        return A[k];

    else if (k < pivotIndex)
        return quickselect(A, left, pivotIndex - 1, k);

    else
        return quickselect(A, pivotIndex + 1, right, k);
}

int main()
{
    int A[] = {7, 4, 6, 3, 9, 1};
    int k = 1;

    printf("K'th smallest element is %d", quickselect(A, 0, N - 1, k));

    return 0;
}