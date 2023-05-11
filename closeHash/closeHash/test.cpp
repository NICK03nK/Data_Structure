#include "closeHash.h"
#include <string>

using namespace closeHash;

// ����Insert()��Find()
void Test_1()
{
	HashTable<string, int> ht;

	ht.Insert(make_pair("����", 107));
	ht.Insert(make_pair("��ѧ", 88));
	ht.Insert(make_pair("Ӣ��", 108));
	ht.Insert(make_pair("����", 68));
	ht.Insert(make_pair("��ѧ", 76));
	ht.Insert(make_pair("��", 88));
	ht.Insert(make_pair("��", 88));
	ht.Insert(make_pair("��", 107));
	ht.Insert(make_pair("��", 107));
}

// ����Erase
void Test_2()
{
	HashTable<string, int> ht;

	ht.Insert(make_pair("����", 107));
	ht.Insert(make_pair("��ѧ", 88));
	ht.Insert(make_pair("Ӣ��", 108));
	ht.Insert(make_pair("����", 68));
	ht.Insert(make_pair("��ѧ", 76));
	ht.Insert(make_pair("��", 88));
	ht.Insert(make_pair("��", 88));
	ht.Insert(make_pair("��", 107));
	ht.Insert(make_pair("��", 107));

	ht.Erase("����");
	ht.Erase("��");
}

// ����Swap()
void Test_3()
{
	HashTable<string, int> ht1;

	ht1.Insert(make_pair("����", 107));
	ht1.Insert(make_pair("��ѧ", 88));
	ht1.Insert(make_pair("Ӣ��", 108));

	HashTable<string, int> ht2;
	ht2.Insert(make_pair("����", 68));
	ht2.Insert(make_pair("��ѧ", 76));
	ht2.Insert(make_pair("����", 88));

	ht2.Swap(ht1);
}

int main()
{
	Test_3();

	return 0;
}