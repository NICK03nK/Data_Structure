#include "BloomFilter.h"
#include <vector>

void Test1()
{
	string str[] = { "��˽�", "�����", "ɳ��", "������", "������1","1������","��1����","��11����","1������1" };
	BloomFilter<10> bf;
	for (auto& str : str)
	{
		bf.set(str);
	}

	for (auto& s : str)
	{
		cout << bf.test(s) << endl;
	}
	cout << endl;

	srand(time(0));
	for (const auto& s : str)
	{
		cout << bf.test(s + to_string(rand())) << endl;
	}
}

void Test2()
{
	srand(time(0));
	const size_t N = 10000;
	BloomFilter<N> bf;

	std::vector<std::string> v1;
	std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + std::to_string(i));
	}

	for (auto& str : v1)
	{
		bf.set(str);
	}

	// v2��v1�������ַ����������ǲ�һ��
	std::vector<std::string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
		url += std::to_string(999999 + i);
		v2.push_back(url);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.test(str))  // ���v2�е�Ԫ���ڲ�¡����������˵��������(v2�е��ַ�����v1�е��ַ������ƣ�������ͬ)
		{
			++n2;
		}
	}
	cout << "�����ַ���������:" << (double)n2 / (double)N << endl;

	// �������ַ�����
	std::vector<std::string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		string url = "zhihu.com";
		url += std::to_string(i + rand());
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.test(str))
		{
			++n3;
		}
	}
	cout << "�������ַ���������:" << (double)n3 / (double)N << endl;
}

int main()
{
	//Test1();
	Test2();

	return 0;
}