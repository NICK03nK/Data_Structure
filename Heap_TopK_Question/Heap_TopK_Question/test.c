#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Swap(int* p1,int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(int* p, int sz, int parent)
{
	int Child = parent * 2 + 1;

	while (Child < sz)
	{
		if (Child + 1 < sz && p[Child + 1] < p[Child])
		{
			Child++;
		}

		if (p[Child] < p[parent])
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

int main()
{
	int data[] = { 2,6,4,8,1,0,7,9,3,5 };
	int k = 4;

	//将前data的前k个数建一个小堆
	int i = 0;
	for (i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(data, k, i);
	}

	//将后n-k个数依次与堆顶数据比较，比堆顶大的与之交换，再继续向下调整
	for (i = k; i < sizeof(data) / sizeof(int); i++)
	{
		if (data[i] > data[0])
		{
			Swap(&data[i], &data[0]);

			AdjustDown(data, k, 0);
		}
	}

	for (i = 0; i < k; i++)
	{
		printf("%d ", data[i]);
	}
	return 0;
}