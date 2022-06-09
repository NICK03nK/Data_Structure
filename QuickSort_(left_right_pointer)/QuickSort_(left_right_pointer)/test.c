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

int GetMid(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[right] > a[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int begin = left;
	int end = right;
	int key = begin;

	while (begin < end)
	{
		while (begin < end && a[end] >= a[key])
		{
			end--;
		}
		while (begin < end && a[begin] <= a[key])
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[key]);

	QuickSort(a, left, begin - 1);
	QuickSort(a, begin + 1, right);
}

int main()
{
	int arr[] = { 7,4,3,2,1,5,7,88,9,76,5 };
	QuickSort(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
	ArrPrint(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}