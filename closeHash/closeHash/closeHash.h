#pragma once

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

namespace closeHash
{
	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return static_cast<size_t>(key);  // 将能强转为整型的都强转成整型
		}
	};

	// 使用模板特化对string转为整型进行特殊处理
	template<>
	struct HashFunc<string>
	{
		size_t operator()(const string& key)
		{
			// 将string中各元素的ascii码相加作为返回值
			size_t ret = 0;
			for (const auto& e : key)
			{
				ret *= 131;  // BKDRHash算法，为解决“abc”，“cba”，“aad”这种情况的哈希冲突
				ret += e;
			}

			return ret;
		}
	};

	enum State
	{
		EXIST,
		DELETE,
		EMPTY
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;  // 哈希表中每个元素的初识状态都设置为EMPTY
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		using Data = HashData<K, V>;

	public:
		HashTable()
			:_n(0)
		{
			_table.resize(__stl_next_prime(0));
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))  // 哈希表中已存在相同key值的元素，插入失败，返回false
			{
				return false;
			}

			// 闭散列的哈希表要将负载因子保持在0.7，一旦>=0.7就执行扩容操作
			if (_n * 10 / _table.size() >= 7)
			{
				HashTable<K, V> newHT;
				newHT._table.resize(__stl_next_prime(_table.size()));  // 扩容

				// 遍历旧哈希表，将旧表中的元素插入新表中
				for (const auto& e : _table)
				{
					if (e._state == EXIST)
					{
						newHT.Insert(e._kv);  // 通过复用Insert()，将旧哈希表的table中的数据重新映射到新哈希表的table中
					}
				}

				// 将新哈希表的table换给旧哈希表
				_table.swap(newHT._table);
			}

			size_t hashi = _hf(kv.first) % _table.size();  // 除留余数法，将元素映射到哈希表中

			// 线性探测
			while (_table[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _table.size();
			}

			// 找到一个空位置，将元素放入表中
			_table[hashi]._kv = kv;
			_table[hashi]._state = EXIST;
			++_n;

			return true;
		}

		Data* Find(const K& key)
		{
			size_t hashi = _hf(key) % _table.size();
			
			while (_table[hashi]._state != EMPTY)
			{
				if (_table[hashi]._state == EXIST && _table[hashi]._kv.first == key)
				{
					return &_table[hashi];
				}

				++hashi;
				hashi %= _table.size();
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			Data* del = Find(key);

			if (del)
			{
				del->_state = DELETE;
				--_n;

				return true;
			}
			else
			{
				return false;
			}
		}

		size_t Size() const
		{
			return _n;
		}

		bool IsEmpty()
		{
			return _n == 0;
		}

		void Swap(HashTable<K, V>& ht)
		{
			_table.swap(ht._table);
			swap(_n, ht._n);
		}

	private:
		inline unsigned long __stl_next_prime(unsigned long n)
		{
			static const int __stl_num_primes = 28;
			static const unsigned long __stl_prime_list[__stl_num_primes] =
			{
			  53,         97,         193,       389,       769,
			  1543,       3079,       6151,      12289,     24593,
			  49157,      98317,      196613,    393241,    786433,
			  1572869,    3145739,    6291469,   12582917,  25165843,
			  50331653,   100663319,  201326611, 402653189, 805306457,
			  1610612741, 3221225473, 4294967291
			};

			for (int i = 0; i < __stl_num_primes; ++i)
			{
				if (__stl_prime_list[i] > n)
				{
					return __stl_prime_list[i];
				}
			}

			return __stl_prime_list[__stl_num_primes - 1];
		}

	private:
		vector<Data> _table;  // 哈希表
		size_t _n;  // 标识哈希表中的有效元素个数

		Hash _hf;  // 哈希函数实例对象，解决key无法%的问题
	};
}