#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

namespace bucketHash
{
	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return static_cast<size_t>(key);
		}
	};

	template<>
	struct HashFunc<string>
	{
		size_t operator()(const string& key)
		{
			size_t ret = 0;
			for (const auto& e : key)
			{
				// BKDRHash
				ret *= 131;
				ret += e;
			}

			return ret;
		}
	};

	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode* _next;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			, _next(nullptr)
		{}
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		using Node = HashNode<K, V>;

	public:
		HashTable()
			:_n(0)
		{
			_table.resize(__stl_next_prime(0), nullptr);
		}

		~HashTable()
		{
			for (int i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];

				while (cur)
				{
					Node* next = cur->_next;

					delete cur;
					
					cur = next;
				}

				_table[i] = nullptr;
			}
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))  // 哈希表中已存在相同key值的元素，插入失败，返回false
			{
				return false;
			}

			// 开散列的哈希表的负载因子控制在1，超过就执行扩容操作
			if (_n == _table.size())
			{
				vector<Node*> newTable;
				newTable.resize(__stl_next_prime(_table.size()), nullptr);

				// 遍历旧哈希表中的元素
				for (int i = 0; i < _table.size(); ++i)
				{
					Node* cur = _table[i];

					// 遍历链表
					while (cur)
					{
						Node* next = cur->_next;

						// 找到元素在新哈希表中的映射位置
						size_t hashi = _hf(cur->_kv.first) % newTable.size();

						// 将元素从旧哈希表取下，插入新哈希表中
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;

						cur = next;
					}

					// 遍历完链表后，将链表头结点置为空，以免释放旧表时将结点也一起释放了
					_table[i] = nullptr;
				}

				// 将新表换给旧表
				_table.swap(newTable);
			}

			size_t hashi = _hf(kv.first) % _table.size();  // 除留余数法，将元素映射到哈希表中

			// 将元素头插到映射的链表中
			Node* newNode = new Node(kv);
			newNode->_next = _table[hashi];
			_table[hashi] = newNode;
			++_n;

			return true;
		}

		Node* Find(const K& key)
		{
			size_t hashi = _hf(key) % _table.size();

			Node* cur = _table[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}

				cur = cur->_next;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			size_t hashi = _hf(key) % _table.size();

			Node* cur = _table[hashi];
			Node* prev = nullptr;

			while (cur)
			{
				if (cur->_kv.first == key)  // 找到了要删除的元素
				{
					if (cur == _table[hashi])  // 要删除的元素为链表头结点
					{
						_table[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					delete cur;  // 删除元素
					--_n;

					return true;
				}

				prev = cur;
				cur = cur->_next;
			}

			return false;
		}

		size_t Size() const
		{
			return _n;
		}

		bool IsEmpty() const
		{
			return _n == 0;
		}

		void Clear()
		{
			for (int i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];

				while (cur)
				{
					Node* next = cur->_next;

					delete cur;

					cur = next;
				}

				_table[i] = nullptr;
			}
		}

		size_t BucketCount() const
		{
			return _table.size();
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
		vector<Node*> _table;  // 哈希表
		size_t _n;  // 标识哈希表中有效元素的个数

		Hash _hf;  // 哈希函数的实例，解决string不能%的情况
	};
}