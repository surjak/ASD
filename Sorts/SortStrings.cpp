#include <bits/stdc++.h>
using namespace std;

int digit(string S, int dig)
{
    if ((int)S.length() <= dig)
        return 0;
    else
    {
        return (int)(S[dig] - 'a' + 1);
    }
}

void countSort(string A[], int n, int dig)
{

    int k = 27;
    int B[k];
    string C[n];

    for (int i = 0; i < k; i++)
        B[i] = 0;

    for (int i = 0; i < n; i++)
        B[digit(A[i], dig)]++;

    for (int i = 1; i < k; i++)
        B[i] += B[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        C[B[digit(A[i], dig)] - 1] = A[i];
        B[digit(A[i], dig)]--;
    }
    for (int i = 0; i < n; i++)
        A[i] = C[i];
}

void sortString(string A[], int n)
{

    int max_length = 0;
    for (int i = 0; i < n; i++)
        max_length = max(max_length, (int)A[i].length());

    for (int i = max_length - 1; i >= 0; i--)
        countSort(A, n, i);
}

int main()
{
    int n;
    cin >> n;
    string A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    sortString(A, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    cout << "\n";
    return 0;
}
