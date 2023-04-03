#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"
#include"Queue.h"

BTNode* CreateTree()
{
	BTNode* node1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* node2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* node3 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* node4 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* node5 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* node6 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* node7 = (BTNode*)malloc(sizeof(BTNode));

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	node5->data = 5;
	node6->data = 6;
	node7->data = 7;

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	/*node3->left = node6;*/
	node3->left = NULL;
	node3->right = node7;
	node4->left = NULL;
	node4->right = NULL;
	node5->left = NULL;
	node5->right = NULL;
	node6->left = NULL;
	node6->right = NULL;
	node7->left = NULL;
	node7->right = NULL;

	return node1;
}

void DestroyTree(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}

	DestroyTree(&(*root)->left);
	DestroyTree(&(*root)->right);
	free(*root);
	*root = NULL;
}

int BTSize(BTNode* root)
{
	return root == NULL ? 0 : BTSize(root->left) + BTSize(root->right) + 1;
}

int BTLeavesSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return BTLeavesSize(root->left) + BTLeavesSize(root->right);
}

int BTLevelKSize(BTNode* root, BTDataType k)
{
	assert(k > 0);

	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return BTLevelKSize(root->left, k - 1) + BTLevelKSize(root->right, k - 1);
}

int BTHight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int lHight = BTHight(root->left);
	int rHight = BTHight(root->right);

	return lHight > rHight ? lHight + 1 : rHight + 1;
}

BTNode* BTFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}

	BTNode* pleft = BTFind(root->left, x);
	if (pleft)
	{
		return pleft;
	}

	BTNode* pright = BTFind(root->right, x);
	if (pright)
	{
		return pright;
	}

	return NULL;
}

void BTPrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%d ", root->data);
	BTPrevOrder(root->left);
	BTPrevOrder(root->right);
}

void BTInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	BTInOrder(root->left);
	printf("%d ", root->data);
	BTInOrder(root->right);
}

void BTPostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	BTPostOrder(root->left);
	BTPostOrder(root->right);
	printf("%d ", root->data);
}

void BTLevelOrder(BTNode* root)
{
	Queue q;
	InitQueue(&q);

	if (root)
	{
		QueuePush(&q, root);
	}

	while (!IsQueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->data);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");

	DestroyQueue(&q);
}

bool IsBinaryTree(BTNode* root)
{
	Queue q;
	InitQueue(&q);

	if (root)
	{
		QueuePush(&q, root);
	}

	while (!IsQueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
		{
			break;
		}

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!IsQueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front != NULL)
		{
			DestroyQueue(&q);
			return false;
		}
	}

	DestroyQueue(&q);
	return true;
}