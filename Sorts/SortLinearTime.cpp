#include <iostream>
using namespace std;

int countSort(int arr[], int n, int exp)
{

	int output[n];
	int i, count[n];
	for (int i = 0; i < n; i++)
		count[i] = 0;

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % n]++;

	for (i = 1; i < n; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % n] - 1] = arr[i];
		count[(arr[i] / exp) % n]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
void sort(int arr[], int n)
{
	countSort(arr, n, 1);
	cout << endl;
	printArr(arr, n);
	cout << endl;
	countSort(arr, n, n);
}

int main()
{
	int arr[] = {40, 12, 45, 34, 33, 1, 22};
	int n = 7;
	cout << n << endl;
	cout << "Given array is n ";
	printArr(arr, n);

	sort(arr, n);

	cout << "nSorted array is n ";
	printArr(arr, n);
	return 0;
}
