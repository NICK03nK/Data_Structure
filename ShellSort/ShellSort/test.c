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

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;
		int i = 0;
		for (i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
	
}

int main()
{
	int arr[] = { 7,4,3,2,1,5,7,88,9,76,5 };
	ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	ArrPrint(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}