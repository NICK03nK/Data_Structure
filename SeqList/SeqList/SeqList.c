#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void InitSeqList(SL* ps)
{
	ps->a = (DataType*)calloc(InitCap, sizeof(DataType));
	ps->sz = 0;
	ps->capacity = InitCap;
}

int FindData(SL* ps, int num)
{
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		if (ps->a[i] == num)
		{
			return i;
		}
	}
	return 0;
}

void SeqListCheakCapacity(SL* ps)
{
	if (ps->sz == ps->capacity)
	{
		DataType* tmp = (DataType*)realloc(ps->a, ps->capacity * 2 * sizeof(DataType));
		if (tmp == NULL)
		{
			printf("\n<内存申请失败>\n\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
		printf("\n<增容成功>\n\n");
	}
}

void SeqlistPushFront(SL* ps, DataType x)
{
	SeqListCheakCapacity(ps);
	int i = 0;
	for (i = ps->sz; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	printf("请输入数据>>");
	scanf("%d", &x);
	ps->a[0] = x;
	printf("\n<录入成功>\n\n");
	ps->sz++;
}

void SeqListPushBack(SL* ps, DataType x)
{
	SeqListCheakCapacity(ps);
	printf("请输入数据>>");
	scanf("%d", &x);
	ps->a[ps->sz] = x;
	printf("\n<录入成功>\n\n");
	ps->sz++;
}

void SeqListPopFront(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->sz - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->sz--;
	printf("\n<删除成功>\n\n");
}

void SeqListPopBack(SL* ps)
{
	assert(ps->sz > 0);
	ps->sz--;
	printf("\n<删除成功>\n\n");
}

void SeqListInsert(SL* ps, DataType x)
{
	SeqListCheakCapacity(ps);
	int pos = 0;
	printf("请输入下标>>");
	scanf("%d", &pos);
	int i = 0;
	for (i = ps->sz; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	printf("请输入数据>>");
	scanf("%d", &x);
	ps->a[pos] = x;
	printf("\n<录入成功>\n\n");
	ps->sz++;
}

void SeqListErase(SL* ps)
{
	assert(ps->sz > 0);
	int i = 0;
	int pos = 0;
	printf("请输入下标>>");
	scanf("%d", &pos);
	for (i = pos; i < ps->sz - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->sz--;
	printf("\n<删除成功>\n\n");
}

void SeqListSearch(const SL* ps)
{
	assert(ps->sz > 0);
	int num = 0;
	printf("请输入要查找的数据>>");
	scanf("%d", &num);
	int ret = FindData(ps, num);
	if (ret>=0)
	{
		printf("\n该数据下标为>>%d\n\n",ret);
	}
	else
	{
		printf("\n<该数据不存在>\n\n");
	}
}

void SeqListModify(SL* ps,DataType x)
{
	assert(ps->sz > 0);
	int pos = 0;
	printf("请输入要修改的数据的下标>>");
	scanf("%d", &pos);
	printf("请输入新数据>>");
	scanf("%d", &x);
	ps->a[pos] = x;
	printf("\n");
}

void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->sz = ps->capacity = 0;
}

void SeqListPrint(const SL* ps)
{
	printf("\n");
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		printf("%d\n", ps->a[i]);
	}
	printf("\n");
}