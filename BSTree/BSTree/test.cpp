#include "BSTree.h"

int main()
{
	int arr[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> bst;

	for (auto e : arr)
	{
		bst.Insert(e);
	}

	bst.InOrder();

	/*bst.Erase(3);
	bst.InOrder();

	bst.Erase(8);
	bst.InOrder();*/

	/*bst.EraseR(3);
	bst.InOrder();

	bst.EraseR(8);
	bst.InOrder();*/

	/*for (auto e : arr)
	{
		bst.EraseR(e);
		bst.InOrder();
	}*/

	BSTree<int> copyt(bst);
	copyt.InOrder();

	return 0;
}