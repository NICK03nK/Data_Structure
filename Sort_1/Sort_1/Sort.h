#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef int SortDataType;

void PrintArr(SortDataType* p, int sz);

//ֱ�Ӳ�������
void InsertSort(SortDataType* p, int sz);

//ϣ������
void ShellSort(SortDataType* p, int sz);

//ֱ��ѡ������
void SelectSort(SortDataType* p, int sz);

//������
void HeapSort(SortDataType* p, int sz);

//ð������
void BubbleSort(SortDataType* p, int sz);

//��������
void QuickSort(SortDataType* p, int begin, int end);

//��������ǵݹ�
void QuickSortNonR(SortDataType* p, int begin, int end);

//�鲢����
void MergeSort(SortDataType* p, int n);

//�鲢����ǵݹ�
void MergeSortNonR(SortDataType* p, int n);

//��������
void CountSort(SortDataType* p, int n);

//�Աȸ������㷨���ٶ�
void TestOP();