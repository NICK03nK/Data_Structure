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

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int i = 0;
		int maxi = left;
		int mini = left;
		for (i = left; i <= right; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[mini], &a[left]);
		if (maxi == left)
		{
			maxi = mini;
		}
		Swap(&a[maxi], &a[right]);
		left++;
		right--;
	}
}

int main()
{
	int arr[] = { 88,7,4,3,2,1,5,7,88,9,76,5 };
	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	ArrPrint(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}