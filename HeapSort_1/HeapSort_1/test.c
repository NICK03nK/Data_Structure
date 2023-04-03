#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//调大堆
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

void HeapSort(int* p, int sz)
{
	//先建堆
	int i = 0;
	for (i = (sz - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(p, sz, i);
	}

	//后排序
	for (i = 1; i < sz; i++)
	{
		Swap(&p[0], &p[sz - i]);
		AdjustDown(p, sz - i, 0);
	}
}

int main()
{
	int data[] = { 8,2,3,0,6,4,5,9,1,7 };
	HeapSort(data, sizeof(data) / sizeof(int));
	
	int i = 0;
	for (i = 0; i < sizeof(data) / sizeof(int); i++)
	{
		printf("%d ", data[i]);
	}
	return 0;
}