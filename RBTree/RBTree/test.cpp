#include "RBTree.h"
#include <ctime>

int main()
{
	int data[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	//int data[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int data[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RBTree<int, int> t;

	for (auto e : data)
	{
		t.Insert(make_pair(e, e));
	}

	t.InOrder();

	cout << t.IsRBTree() << endl;

	/*srand(time(0));
	const size_t N = 1000;
	RBTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand();
		t.Insert(make_pair(x, x));
	}

	cout << t.IsRBTree() << endl;*/

	return 0;
}