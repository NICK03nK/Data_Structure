#include "BloomFilter.h"
#include <vector>

void Test1()
{
	string str[] = { "猪八戒", "孙悟空", "沙悟净", "唐三藏", "白龙马1","1白龙马","白1龙马","白11龙马","1白龙马1" };
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

	// v2跟v1是相似字符串集，但是不一样
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
		if (bf.test(str))  // 如果v2中的元素在布隆过滤器中则说明误判了(v2中的字符串和v1中的字符串相似，但不相同)
		{
			++n2;
		}
	}
	cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;

	// 不相似字符串集
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
	cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;
}

int main()
{
	//Test1();
	Test2();

	return 0;
}