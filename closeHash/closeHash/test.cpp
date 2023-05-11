#include "closeHash.h"
#include <string>

using namespace closeHash;

// 测试Insert()和Find()
void Test_1()
{
	HashTable<string, int> ht;

	ht.Insert(make_pair("语文", 107));
	ht.Insert(make_pair("数学", 88));
	ht.Insert(make_pair("英语", 108));
	ht.Insert(make_pair("物理", 68));
	ht.Insert(make_pair("化学", 76));
	ht.Insert(make_pair("地", 88));
	ht.Insert(make_pair("理", 88));
	ht.Insert(make_pair("语", 107));
	ht.Insert(make_pair("文", 107));
}

// 测试Erase
void Test_2()
{
	HashTable<string, int> ht;

	ht.Insert(make_pair("语文", 107));
	ht.Insert(make_pair("数学", 88));
	ht.Insert(make_pair("英语", 108));
	ht.Insert(make_pair("物理", 68));
	ht.Insert(make_pair("化学", 76));
	ht.Insert(make_pair("地", 88));
	ht.Insert(make_pair("理", 88));
	ht.Insert(make_pair("语", 107));
	ht.Insert(make_pair("文", 107));

	ht.Erase("语文");
	ht.Erase("语");
}

// 测试Swap()
void Test_3()
{
	HashTable<string, int> ht1;

	ht1.Insert(make_pair("语文", 107));
	ht1.Insert(make_pair("数学", 88));
	ht1.Insert(make_pair("英语", 108));

	HashTable<string, int> ht2;
	ht2.Insert(make_pair("物理", 68));
	ht2.Insert(make_pair("化学", 76));
	ht2.Insert(make_pair("地理", 88));

	ht2.Swap(ht1);
}

int main()
{
	Test_3();

	return 0;
}