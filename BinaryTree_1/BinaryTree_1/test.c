#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"
#include"Queue.h"

//1.���������������
void Test1()
{
	BTNode* root = CreateTree();

	int ret = BTSize(root);
	printf("%d\n", ret);

	DestroyTree(&root);
}

//2.���������Ҷ�ӽ�����
void Test2()
{
	BTNode* root = CreateTree();

	int ret = BTLeavesSize(root);
	printf("%d\n", ret);

	DestroyTree(&root);
}

//3.�����������k��Ľ����
void Test3()
{
	BTNode* root = CreateTree();

	BTDataType k = 2;
	int ret = BTLevelKSize(root, k);
	printf("%d\n", ret);

	DestroyTree(&root);
}

//4.����������ĸ߶�
void Test4()
{
	BTNode* root = CreateTree();

	int hight = BTHight(root);
	printf("%d\n", hight);
}

//5.���Ҷ������е����ݣ����ؽ���ַ
void Test5()
{
	BTNode* root = CreateTree();

	BTNode* ret = BTFind(root, 3);
	printf("%p\n", ret);

	DestroyTree(&root);
}

//6.������ǰ�����
void Test6()
{
	BTNode* root = CreateTree();

	BTPrevOrder(root);

	DestroyTree(&root);
}

//7.�������������
void Test7()
{
	BTNode* root = CreateTree();

	BTInOrder(root);

	DestroyTree(&root);
}

//8.�������������
void Test8()
{
	BTNode* root = CreateTree();

	BTPostOrder(root);

	DestroyTree(&root);
}

//9.�������������
void Test9()
{
	BTNode* root = CreateTree();

	BTLevelOrder(root);

	DestroyTree(&root);
}

//10.�ж��Ƿ�Ϊ��ȫ������
void Test10()
{
	BTNode* root = CreateTree();

	if (IsBinaryTree(root))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

	DestroyTree(&root);
}

int main()
{
	Test10();
	return 0;
}