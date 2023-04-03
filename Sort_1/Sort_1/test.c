#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"
#include"Stack.h"

void Test_InsertSort()
{
	int arr[] = { 7,5,2,8,0,1,6,9,4,3 };

	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));

	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void Test_ShellSort()
{
	int arr[] = { 7,5,2,8,0,1,6,9,4,3 };

	ShellSort(arr, sizeof(arr) / sizeof(arr[0]));

	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void Test_HeapSort()
{
	int arr[] = { 7,5,2,8,0,1,6,9,4,3 };

	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));

	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void Test_SelectSort()
{
	int arr[] = { 7,5,2,8,0,1,6,9,4,3 };

	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));

	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void Test_BubbleSort()
{
	//int arr[] = { 1,5,2,8,0,3,6,9,4,7 };

	int arr[] = { 7,5,2,8,0,1,6,9,4,3 };

	BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));

	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void Test_QuickSort()
{
	int arr[] = { 7,5,2,8,0,1,6,9,4,3 };

	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);

	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void Test_QuickSortNonR()
{
	int arr[] = { 7,5,2,8,0,1,6,9,4,3 };

	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	QuickSortNonR(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);

	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void Test_MergeSort()
{
	int arr[] = { 7,5,2,8,0,1,6,9,4,3 };

	MergeSort(arr, sizeof(arr) / sizeof(arr[0]));

	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void Test_MergeSortNonR()
{
	int arr[] = { 7,5,2,8,0,1,6,9,4,3 };

	MergeSortNonR(arr, sizeof(arr) / sizeof(arr[0]));

	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void Test_CountSort()
{
	//int arr[] = { 7,5,2,8,0,1,6,9,4,3 };

	int arr[] = { 7,2,2,0,0,1,6,9,9,4,3,3,3,3,7,7 };

	CountSort(arr, sizeof(arr) / sizeof(arr[0]));

	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}

int main()
{
	//TestOP();

	Test_CountSort();

	return 0;
}