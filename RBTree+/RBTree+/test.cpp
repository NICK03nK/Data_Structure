#include "RBTree+.h"

void Test()
{
	int arr[] = { 8, 6, 11, 5, 7, 10, 13, 12, 15 };
	RBTree<int, int> t;

	for (auto e : arr)
	{
		t.Insert(make_pair(e, e));
	}

	t.InOrder();

	cout << t.IsValidRBTRee() << endl;

	cout << t.LeftMost()->_kv.first << ":" << t.LeftMost()->_kv.second << endl;
	cout << t.RightMost()->_kv.first << ":" << t.RightMost()->_kv.second << endl;

	cout << t.Find(make_pair(16, 16)) << endl;
	cout << t.Find(make_pair(10, 10)) << endl;
}

int main()
{
	Test();

	return 0;
}