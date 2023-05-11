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
			return static_cast<size_t>(key);  // ����ǿתΪ���͵Ķ�ǿת������
		}
	};

	// ʹ��ģ���ػ���stringתΪ���ͽ������⴦��
	template<>
	struct HashFunc<string>
	{
		size_t operator()(const string& key)
		{
			// ��string�и�Ԫ�ص�ascii�������Ϊ����ֵ
			size_t ret = 0;
			for (const auto& e : key)
			{
				ret *= 131;  // BKDRHash�㷨��Ϊ�����abc������cba������aad����������Ĺ�ϣ��ͻ
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
		State _state = EMPTY;  // ��ϣ����ÿ��Ԫ�صĳ�ʶ״̬������ΪEMPTY
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
			if (Find(kv.first))  // ��ϣ�����Ѵ�����ͬkeyֵ��Ԫ�أ�����ʧ�ܣ�����false
			{
				return false;
			}

			// ��ɢ�еĹ�ϣ��Ҫ���������ӱ�����0.7��һ��>=0.7��ִ�����ݲ���
			if (_n * 10 / _table.size() >= 7)
			{
				HashTable<K, V> newHT;
				newHT._table.resize(__stl_next_prime(_table.size()));  // ����

				// �����ɹ�ϣ�����ɱ��е�Ԫ�ز����±���
				for (const auto& e : _table)
				{
					if (e._state == EXIST)
					{
						newHT.Insert(e._kv);  // ͨ������Insert()�����ɹ�ϣ���table�е���������ӳ�䵽�¹�ϣ���table��
					}
				}

				// ���¹�ϣ���table�����ɹ�ϣ��
				_table.swap(newHT._table);
			}

			size_t hashi = _hf(kv.first) % _table.size();  // ��������������Ԫ��ӳ�䵽��ϣ����

			// ����̽��
			while (_table[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _table.size();
			}

			// �ҵ�һ����λ�ã���Ԫ�ط������
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
		vector<Data> _table;  // ��ϣ��
		size_t _n;  // ��ʶ��ϣ���е���ЧԪ�ظ���

		Hash _hf;  // ��ϣ����ʵ�����󣬽��key�޷�%������
	};
}