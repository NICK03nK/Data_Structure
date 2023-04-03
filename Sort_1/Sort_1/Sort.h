#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef int SortDataType;

void PrintArr(SortDataType* p, int sz);

//直接插入排序
void InsertSort(SortDataType* p, int sz);

//希尔排序
void ShellSort(SortDataType* p, int sz);

//直接选择排序
void SelectSort(SortDataType* p, int sz);

//堆排序
void HeapSort(SortDataType* p, int sz);

//冒泡排序
void BubbleSort(SortDataType* p, int sz);

//快速排序
void QuickSort(SortDataType* p, int begin, int end);

//快速排序非递归
void QuickSortNonR(SortDataType* p, int begin, int end);

//归并排序
void MergeSort(SortDataType* p, int n);

//归并排序非递归
void MergeSortNonR(SortDataType* p, int n);

//计数排序
void CountSort(SortDataType* p, int n);

//对比各排序算法的速度
void TestOP();