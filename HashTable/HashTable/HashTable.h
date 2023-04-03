#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class K>
class HashFunc
{
public:
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

// 模板特化处理string不能取模运算的问题
template<>
class HashFunc<string>
{
public:
	size_t operator()(const string& key)
	{
		//return key[0];

		// 将字符串的ascii码相加作为返回值，能够一定程度避免发生哈希冲突
		size_t ret = 0;
		for (auto e : key)
		{
			ret *= 131;  // BKDRHash算法，为解决“abc”，“cba”，“aad”这种情况的哈希冲突
			ret += e;
		}

		return ret;
	}
};

namespace closehash
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashData<K, V> Data;

	public:
		HashTable()
			:_n(0)
		{
			_tables.resize(10);
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))  // 表中已经存在相同数据
			{
				return false;
			}

			// 大于标定的负载因子，就扩容
			if (_n * 10 / _tables.size() > 7)  // 标定的负载因子定为0.7的效率比较高
			{
				// 创建一个新的表，复用Insert的代码
				HashTable<K, V, Hash> newHT;
				newHT._tables.resize(_tables.size() * 2);

				// 将旧表的数据插入到新表中
				for (auto& e : _tables)
				{
					if (e._state == EXIST)
					{
						newHT.Insert(e._kv);
					}
				}

				// 调用swap，将旧表和新表的_tables调换，顺便利用临时创建的新表的销毁来销毁旧的_tables
				_tables.swap(newHT._tables);
			}

			Hash hf;
			size_t hashi = hf(kv.first) % _tables.size();

			while (_tables[hashi]._state == EXIST)
			{
				++hashi;  // 线性探测
				hashi %= _tables.size();
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;

			return true;
		}

		Data* Find(const K& key)
		{
			Hash hf;
			size_t hashi = hf(key) % _tables.size();
			size_t starti = hashi;

			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state == EXIST && _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}

				++hashi;
				hashi %= _tables.size();

				// 极端场景下，经过不断地插入删除会出现没有EMPTY的情况，所以走完一圈后就要break，以免陷入死循环
				if (hashi == starti)
				{
					break;
				}
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			Data* ret = Find(key);

			if (ret)
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		vector<Data> _tables;
		size_t _n;  // 记录哈希表中存储的有效数据个数
	};
}

namespace buckethash
{
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			, _next(nullptr)
		{}
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;

	public:
		HashTable()
			:_n(0)
		{
			//_tables.resize(10);
			_tables.resize(__stl_next_prime(0));
		}

		~HashTable()
		{
			for (int i = 0; i < _tables.size(); ++i)
			{
				// 桶不为空，则遍历删除桶中的结点
				Node* cur = _tables[i];

				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}

				_tables[i] = nullptr;
			}
		}

		bool Insert(const pair<K, V>& kv)
		{
			Hash hf;

			// 插入的元素已存在
			if (Find(kv.first))
			{
				return false;
			}

			// 表达负载因子设置为1，超过就扩容
			if (_tables.size() == _n)
			{
				vector<Node*> newTables;
				//newTables.resize(_tables.size() * 2, nullptr);
				newTables.resize(__stl_next_prime(_tables.size()), nullptr);

				for (int i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];

					while (cur)
					{
						Node* next = cur->_next;

						// 找到数据在新表中的映射的桶的位置
						size_t hashi = hf(cur->_kv.first) % newTables.size();

						//将数据头插到新表中
						cur->_next = newTables[hashi];
						newTables[hashi] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				// 将新表换给旧表
				_tables.swap(newTables);
			}

			size_t hashi = hf(kv.first) % _tables.size();

			// 根据key的值映射到对应桶的位置，然后头插
			Node* newNode = new Node(kv);
			newNode->_next = _tables[hashi];
			_tables[hashi] = newNode;
			++_n;  // 表中有效个数++

			return true;
		}

		Node* Find(const K& key)
		{
			Hash hf;

			// 通过key先找到对应的桶
			size_t hashi = hf(key) % _tables.size();

			// 遍历对应的桶找key
			Node* cur = _tables[hashi];
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
			Hash hf;

			// 通过key先找到对应的桶
			size_t hashi = hf(key) % _tables.size();

			Node* cur = _tables[hashi];
			Node* prev = nullptr;

			// 遍历桶
			while (cur)
			{
				// 找到key并删除
				if (cur->_kv.first == key)
				{
					// 如果要删除的结点为桶的头结点，则直接删除即可
					if (cur == _tables[hashi])
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					delete cur;
					--_n;

					return true;
				}

				prev = cur;
				cur = cur->_next;
			}

			return false;
		}

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
		vector<Node*> _tables;
		size_t _n;  // 记录哈希表中存储的有效数据个数
	};
}