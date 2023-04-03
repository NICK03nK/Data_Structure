#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"
#include"Stack.h"

void PrintArr(SortDataType* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}

void InsertSort(SortDataType* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int end = i;
		SortDataType tmp = p[end + 1];
		while (end >= 0)
		{
			if (p[end] > tmp)
			{
				p[end + 1] = p[end];
				end--;
			}
			else
			{
				break;
			}
		}
		p[end + 1] = tmp;
	}
}

void ShellSort(SortDataType* p, int sz)
{
	int gap = sz;

	while (gap > 1)
	{
		gap = gap / 3 + 1;

		int i = 0;
		for (i = 0; i < sz - gap; i++)
		{
			int end = i;
			SortDataType tmp = p[end + gap];
			while (end >= 0)
			{
				if (p[end] > tmp)
				{
					p[end + gap] = p[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			p[end + gap] = tmp;
		}
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(SortDataType* p, int sz)
{
	int begin = 0;
	int end = sz - 1;

	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;

		int i = 0;
		for (i = begin; i <= end; i++)
		{
			if (p[i] > p[maxi])
			{
				maxi = i;
			}

			if (p[i] < p[mini])
			{
				mini = i;
			}
		}

		Swap(&p[begin], &p[mini]);

		if (maxi == begin)
		{
			maxi = mini;
		}

		Swap(&p[end], &p[maxi]);

		begin++;
		end--;
	}
}

void AdjustDown(int* p, int sz, int parent)
{
	int Child = parent * 2 + 1;

	while (Child < sz)
	{
		if (Child + 1 < sz && p[Child + 1] > p[Child])
		{
			Child++;
		}

		if (p[Child] > p[parent])
		{
			Swap(&p[Child], &p[parent]);
			parent = Child;
			Child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(SortDataType* p, int sz)
{
	int i = 0;
	for (i = (sz - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(p, sz, i);
	}

	for (i = 1; i < sz; i++)
	{
		Swap(&p[0], &p[sz - i]);
		AdjustDown(p, sz - i, 0);
	}
}

void BubbleSort(SortDataType* p, int sz)
{
	int end = sz;
	while (end >= 2)
	{
		int flag = 1;

		int i = 0;
		for (i = 1; i < end; i++)
		{
			if (p[i - 1] > p[i])
			{
				flag = 0;
				Swap(&p[i - 1], &p[i]);
			}
		}

		if (flag)
		{
			break;
		}

		end--;
	}
}

int GetMidIndex(SortDataType* p, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (p[left] < p[mid])
	{
		if (p[mid] < p[right])
		{
			return mid;
		}
		else if (p[left] > p[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else //p[left] > p[mid] �� p[left] = p[mid]
	{
		if (p[mid] > p[right])
		{
			return mid;
		}
		else if (p[left] < p[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

void QuickSort(SortDataType* p, int begin, int end)
{	
	if (begin >= end)
	{
		return;
	}

	if (end - begin < 16)
	{
		InsertSort(p + begin, end - begin + 1);
	}
	else
	{
		int mid = GetMidIndex(p, begin, end);
		Swap(&p[begin], &p[mid]);

		//hoare�汾
		/*int keyi = begin;
		int left = begin;
		int right = end;

		while (left < right)
		{
			while (left < right && p[right] >= p[keyi])
			{
				right--;
			}

			while (left < right && p[left] <= p[keyi])
			{
				left++;
			}

			if (left < right)
			{
				Swap(&p[left], &p[right]);
			}
		}
		int meeti = left;
		Swap(&p[meeti], &p[keyi]);

		QuickSort(p, begin, meeti - 1);
		QuickSort(p, meeti + 1, end);*/


		//�ڿӰ汾
		int key = p[begin];
		int hole = begin;
		int left = begin;
		int right = end;

		while (left < right)
		{
			while (left < right && p[right] >= key)
			{
				right--;
			}
			p[hole] = p[right];
			hole = right;

			while (left < right && p[left] <= key)
			{
				left++;
			}
			p[hole] = p[left];
			hole = left;
		}
		p[hole] = key;

		QuickSort(p, begin, hole - 1);
		QuickSort(p, hole + 1, end);


		//ǰ��ָ��汾
		/*int keyi = begin;
		int prev = begin;
		int cur = begin + 1;

		while (cur <= end)
		{
			if (p[cur] < p[keyi] && ++prev != cur)
			{
				Swap(&p[prev], &p[cur]);
			}

			cur++;
		}
		Swap(&p[prev], &p[keyi]);

		QuickSort(p, begin, prev - 1);
		QuickSort(p, prev + 1, end);*/
	}
}

void QuickSortNonR(SortDataType* p, int begin, int end)
{
	ST st;
	InitST(&st);

	STPush(&st, begin);
	STPush(&st, end);

	while (!IsSTEmpty(&st))
	{
		int right = STTop(&st);
		STPop(&st);
		int left = STTop(&st);
		STPop(&st);

		if (left >= right)
		{
			continue;
		}

		//������[left,right]�еĵ�������
		int mid = GetMidIndex(p, left, right);//<--
		Swap(&p[left], &p[mid]);

		int key = p[left];
		int hole = left;
		int lefti = left;
		int righti = right;

		while (lefti < righti)
		{
			while (lefti < righti && p[righti] >= key)
			{
				righti--;
			}
			p[hole] = p[righti];
			hole = righti;

			while (lefti < righti && p[lefti] <= key)
			{
				lefti++;
			}
			p[hole] = p[lefti];
			hole = lefti;
		}
		p[hole] = key;//<--
		//һ��������ɺ� --> [left,hole-1] hole [hole+1,right]
		
		STPush(&st, hole + 1);
		STPush(&st, right);

		STPush(&st, left);
		STPush(&st, hole - 1);
	}

	DestroyST(&st);
}

void _MergeSort(SortDataType* p, int begin, int end, SortDataType* tmp)
{
	if (begin >= end)
	{
		return;
	}

	int mid = begin + (end - begin) / 2;
	//[begin,mid] [mid,end]

	_MergeSort(p, begin, mid, tmp);
	_MergeSort(p, mid + 1, end, tmp);

	//����ִ�е���[begin,mid] [mid,end]�����������򣬿ɽ��й鲢
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (p[begin1] <= p[begin2])
		{
			tmp[i++] = p[begin1++];
		}
		else
		{
			tmp[i++] = p[begin2++];
		}
	}

	//����whileѭ����������������ض���һ�����仹��Ԫ�أ���ʱ��ʣ�µ��Ǹ�����ȫ��ת����tmp��
	while (begin1 <= end1)
	{
		tmp[i++] = p[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = p[begin2++];
	}

	//�����ݹ鲢��tmp��Ҫ�����ݴ�tmp�п�����ԭ������
	memcpy(p + begin, tmp + begin, (end - begin + 1) * sizeof(SortDataType));
}

void MergeSort(SortDataType* p, int n)
{
	SortDataType* tmp = (SortDataType*)malloc(n * sizeof(SortDataType));
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	_MergeSort(p, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(SortDataType* p, int n)
{
	SortDataType* tmp = (SortDataType*)malloc(n * sizeof(SortDataType));
	if (tmp == NULL)
	{
		perror("malloc fail");
	}

	int gap = 1;
	while (gap < n)
	{
		//ÿ����������gap������
		int j = 0;
		for (j = 0; j < n; j += 2 * gap)
		{
			int begin1 = j;
			int end1 = j + gap - 1;
			int begin2 = j + gap;
			int end2 = j + 2 * gap - 1;

			//Ҫ�����������ȥ�鲢
			//1.��һ�����Խ��-->�ڶ���ȫԽ�磬�ڶ��鲻���ڣ�����Ҫ�鲢
			if (end1 >= n)
			{
				break;
			}

			//2.��һ����Խ�磬�ڶ���ȫԽ��-->�ڶ��鲻���ڣ�����Ҫ�鲢
			if (begin2 >= n)
			{
				break;
			}

			//3.��һ����Խ�磬�ڶ��鲿��Խ��-->�ڶ�����ڣ���Ҫ�����ڶ���ı߽����й鲢
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			int i = j;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (p[begin1] <= p[begin2])
				{
					tmp[i++] = p[begin1++];
				}
				else
				{
					tmp[i++] = p[begin2++];
				}
			}

			//����whileѭ����������������ض���һ�����仹��Ԫ�أ���ʱ��ʣ�µ��Ǹ�����ȫ��ת����tmp��
			while (begin1 <= end1)
			{
				tmp[i++] = p[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[i++] = p[begin2++];
			}

			//���ֿ���-->���鲢��tmp�е����ݿ�����ԭ������
			memcpy(p + j, tmp + j, (end2 - j + 1) * sizeof(SortDataType));
		}

		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}

void CountSort(SortDataType* p, int n)
{
	int max = p[0];
	int min = p[0];

	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (p[i] > max)
		{
			max = p[i];
		}
		
		if (p[i] < min)
		{
			min = p[i];
		}
	}

	int range = max - min + 1;

	SortDataType* count = (SortDataType*)calloc(range, sizeof(SortDataType));
	if (count == NULL)
	{
		perror("calloc fail");
		exit(-1);
	}

	for (i = 0; i < n; i++)
	{
		count[p[i] - min]++;
	}

	int j = 0;
	for (i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			p[j++] = i + min;
		}
	}

	free(count);
	count = NULL;
}

void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	//ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	//HeapSort(a4, N);
	int end4 = clock();

	int begin7 = clock();
	//BubbleSort(a7, N);
	int end7 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("BubbleSort:%d\n", end7 - begin7);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}