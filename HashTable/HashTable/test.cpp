#include "HashTable.h"

void test1()
{
	closehash::HashTable<int, int> ht;
	int arr[] = { 18,8,7,27,57,3,38 };

	for (auto e : arr)
	{
		ht.Insert(make_pair(e, e));
	}

	ht.Insert(make_pair(17, 17));
	ht.Insert(make_pair(5, 5));

	cout << ht.Find(7) << endl;
	cout << ht.Find(8) << endl;

	ht.Erase(7);
	cout << ht.Find(7) << endl;
	cout << ht.Find(8) << endl;
}

void test2()
{
	string arr[] = { "∆ªπ˚", "Œ˜πœ", "œ„Ω∂", "≤››Æ", "∆ªπ˚", "Œ˜πœ", "∆ªπ˚", "∆ªπ˚", "Œ˜πœ", "∆ªπ˚", "œ„Ω∂", "∆ªπ˚", "œ„Ω∂" };
	closehash::HashTable<string, int> countHT;

	for (auto& str : arr)
	{
		closehash::HashData<string, int>* ret = countHT.Find(str);

		if (ret)
		{
			ret->_kv.second++;
		}
		else
		{
			countHT.Insert(make_pair(str, 1));
		}
	}
}

// ≤‚ ‘Insert()£¨Find()£¨Erase()
void test3()
{
	buckethash::HashTable<int, int> ht;

	int arr[] = { 18, 8, 7, 27, 57, 3, 38, 18,17,88,38,28 };
	for (auto e : arr)
	{
		ht.Insert(make_pair(e, e));
	}

	ht.Insert(make_pair(5, 5));

	ht.Erase(88);
	ht.Erase(28);
}

int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}