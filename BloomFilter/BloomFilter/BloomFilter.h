#pragma once

#include <iostream>
#include <bitset>
#include <string>
using namespace std;

struct BKDRHash
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto ch : key)
		{
			hash *= 131;
			hash += ch;
		}
		return hash;
	}
};

struct APHash
{
	size_t operator()(const string& key)
	{
		unsigned int hash = 0;
		int i = 0;

		for (auto ch : key)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ (ch) ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ (ch) ^ (hash >> 5)));
			}

			++i;
		}

		return hash;
	}
};

struct DJBHash
{
	size_t operator()(const string& key)
	{
		unsigned int hash = 5381;

		for (auto ch : key)
		{
			hash += (hash << 5) + ch;
		}

		return hash;
	}
};

template<size_t N, class K = string, size_t X = 6, class HashFunc1 = BKDRHash, class HashFunc2 = APHash, class HashFunc3 = DJBHash>
class BloomFilter
{
public:
	void set(const K& key)
	{
		size_t hash1 = HashFunc1()(key) % (N * X);
		size_t hash2 = HashFunc2()(key) % (N * X);
		size_t hash3 = HashFunc3()(key) % (N * X);

		_bs.set(hash1);
		_bs.set(hash2);
		_bs.set(hash3);
	}

	bool test(const K& key)
	{
		size_t hash1 = HashFunc1()(key) % (N * X);
		if (!_bs.test(hash1))
		{
			return false;
		}

		size_t hash2 = HashFunc2()(key) % (N * X);
		if (!_bs.test(hash2))
		{
			return false;
		}

		size_t hash3 = HashFunc3()(key) % (N * X);
		if (!_bs.test(hash3))
		{
			return false;
		}

		// 前面返回不在都是准确的
		return true;  // 可能存在误判，映射的几个位置都存在冲突就会误判
	}

private:
	bitset<N * X> _bs;
};