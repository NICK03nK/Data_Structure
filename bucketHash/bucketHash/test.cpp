#include "bucketHash.h"

using namespace bucketHash;

// ²âÊÔInsert()ºÍFind()
void Test_1()
{
	HashTable<int, int> ht;

	ht.Insert(make_pair(1, 1));
	ht.Insert(make_pair(17, 1));
	ht.Insert(make_pair(11, 1));
	ht.Insert(make_pair(21, 1));
	ht.Insert(make_pair(27, 1));
	ht.Insert(make_pair(37, 1));
	ht.Insert(make_pair(127, 1));
	ht.Insert(make_pair(77, 1));
	ht.Insert(make_pair(24, 1));
}

// ²âÊÔErase()
void Test_2()
{
	HashTable<int, int> ht;

	ht.Insert(make_pair(1, 1));
	ht.Insert(make_pair(17, 1));
	ht.Insert(make_pair(11, 1));
	ht.Insert(make_pair(21, 1));
	ht.Insert(make_pair(27, 1));
	ht.Insert(make_pair(37, 1));
	ht.Insert(make_pair(127, 1));
	ht.Insert(make_pair(77, 1));
	ht.Insert(make_pair(24, 1));

	ht.Erase(24);
	ht.Erase(77);
}

// ²âÊÔClear()
void Test_3()
{
	HashTable<int, int> ht;

	ht.Insert(make_pair(1, 1));
	ht.Insert(make_pair(17, 1));
	ht.Insert(make_pair(11, 1));
	ht.Insert(make_pair(21, 1));
	ht.Insert(make_pair(27, 1));
	ht.Insert(make_pair(37, 1));
	ht.Insert(make_pair(127, 1));
	ht.Insert(make_pair(77, 1));
	ht.Insert(make_pair(24, 1));

	ht.Clear();
}

int main()
{
	Test_3();

	return 0;
}