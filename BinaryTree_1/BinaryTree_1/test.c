#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"
#include"Queue.h"

//1.计算二叉树结点个数
void Test1()
{
	BTNode* root = CreateTree();

	int ret = BTSize(root);
	printf("%d\n", ret);

	DestroyTree(&root);
}

//2.计算二叉树叶子结点个数
void Test2()
{
	BTNode* root = CreateTree();

	int ret = BTLeavesSize(root);
	printf("%d\n", ret);

	DestroyTree(&root);
}

//3.计算二叉树第k层的结点数
void Test3()
{
	BTNode* root = CreateTree();

	BTDataType k = 2;
	int ret = BTLevelKSize(root, k);
	printf("%d\n", ret);

	DestroyTree(&root);
}

//4.计算二叉树的高度
void Test4()
{
	BTNode* root = CreateTree();

	int hight = BTHight(root);
	printf("%d\n", hight);
}

//5.查找二叉树中的数据，返回结点地址
void Test5()
{
	BTNode* root = CreateTree();

	BTNode* ret = BTFind(root, 3);
	printf("%p\n", ret);

	DestroyTree(&root);
}

//6.二叉树前序遍历
void Test6()
{
	BTNode* root = CreateTree();

	BTPrevOrder(root);

	DestroyTree(&root);
}

//7.二叉树中序遍历
void Test7()
{
	BTNode* root = CreateTree();

	BTInOrder(root);

	DestroyTree(&root);
}

//8.二叉树后序遍历
void Test8()
{
	BTNode* root = CreateTree();

	BTPostOrder(root);

	DestroyTree(&root);
}

//9.二叉树层序遍历
void Test9()
{
	BTNode* root = CreateTree();

	BTLevelOrder(root);

	DestroyTree(&root);
}

//10.判断是否为完全二叉树
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