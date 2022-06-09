#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void ArrPrint(const int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

int main()
{
	int arr[] = { 7,4,3,2,1,5,7,88,9,76,5 };
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	ArrPrint(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}