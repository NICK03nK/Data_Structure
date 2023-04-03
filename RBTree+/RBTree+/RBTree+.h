#pragma once

#include <iostream>
using namespace std;

enum Color
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreeNode
{
	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Color _col;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;

public:
	RBTree()
		:_root(nullptr)
	{}

	bool Insert(const pair<K, V>& kv)
	{
		// ��ǰ�����Ϊ������newһ�������Ϊ�����
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;  // ����������ʹ涨����������Ϊ��ɫ

			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else  // ������д�����ͬKey�Ľ�㣬����ʧ�ܣ�����false
			{
				return false;
			}
		}

		// newһ����㲢���뵽cur��ǰ����λ��
		cur = new Node(kv);

		if (kv.first < parent->_kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		// ��鲢����������ɫ
		while (parent && parent->_col == RED)  // ���������Ҹ����Ϊ��ɫ�ſ���Ҫ��������������ɫ
		{
			Node* grandParent = parent->_parent;

			// 1.parent��grandParent�����
			if (parent == grandParent->_left)
			{
				Node* uncle = grandParent->_right;

				// ���һ��curΪ��ɫ��parentΪ��ɫ��grandParentΪ��ɫ��uncle������Ϊ��ɫ
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandParent->_col = RED;

					cur = grandParent;
					parent = cur->_parent;
				}
				// ��������������curΪ��ɫ��parentΪ��ɫ��grandParentΪ��ɫ��uncle�����ڻ�uncle������Ϊ��ɫ
				else
				{
					// �������(cur��parent��grandParent��ֱ����)
					if (cur == parent->_left)
					{
						RotateR(grandParent);

						grandParent->_col = RED;
						parent->_col = BLACK;
					}
					// �������(cur��parent��grandParent��������)
					else
					{
						RotateL(parent);
						RotateR(grandParent);

						grandParent->_col = RED;
						cur->_col = BLACK;
					}

					// ��Ϊ������������������󣬶��ϡ����յ�grandParent�������Ϊ��ɫ��
					// ���������������parent�γ�����������ɫ����������Դ������break����
					break;
				}
			}
			// 2.parent��grandParent���ұ�
			else
			{
				Node* uncle = grandParent->_left;

				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandParent->_col = RED;

					cur = grandParent;
					parent = cur->_parent;
				}
				else
				{
					if (cur = parent->_right)
					{
						RotateL(grandParent);

						grandParent->_col = RED;
						parent->_col = BLACK;
					}
					else
					{
						RotateR(parent);
						RotateL(grandParent);

						grandParent->_col = RED;
						cur->_col = BLACK;
					}

					break;
				}
			}
		}

		_root->_col = BLACK;

		return true;
	}

	Node* Find(const pair<K, V>& kv)
	{
		// ��ǰ�����Ϊ�գ���ֱ�ӷ���false
		if (_root == nullptr)
		{
			return nullptr;
		}

		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				cur = cur->_right;
			}
			// �ҵ���
			else
			{
				return cur;
			}
		}

		// cur�ߵ��ն�û�ҵ���Ӧ��ֵ��˵���ú�����в����ڸ�ֵ������nullptr
		return nullptr;
	}

	Node* LeftMost()
	{
		if (_root == nullptr)
		{
			return nullptr;
		}

		Node* cur = _root;
		while (cur->_left)
		{
			cur = cur->_left;
		}

		return cur;
	}

	Node* RightMost()
	{
		if (_root == nullptr)
		{
			return nullptr;
		}

		Node* cur = _root;
		while (cur->_right)
		{
			cur = cur->_right;
		}

		return cur;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	bool IsValidRBTRee()
	{
		// ����Ҳ���Ǻ����
		if (_root == nullptr)
		{
			return true;
		}

		// ������ĸ����һ��Ҫ�Ǻ�ɫ��������㲻Ϊ��ɫ���򷵻�false
		if (_root->_col != BLACK)
		{
			return false;
		}

		// �����������·���ĺ�ɫ���ĸ�����ͬ
		// ������·���к�ɫ���ĸ�����¼��������Ϊ�ο�ֵ����������·�����бȶ�
		int ref = 0;
		Node* left = _root;
		while (left)
		{
			if (left->_col == BLACK)
			{
				++ref;
			}

			left = left->_left;
		}

		return _IsValidRBTRee(_root, 0, ref);
	}

private:
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		Node* ppNode = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;

		if (ppNode == nullptr)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (parent == ppNode->_left)
			{
				ppNode->_left = subR;
			}
			else
			{
				ppNode->_right = subR;
			}
			subR->_parent = ppNode;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		Node* ppNode = parent->_parent;
		subL->_right = parent;
		parent->_parent = subL;

		if (ppNode == nullptr)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (parent == ppNode->_left)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	bool _IsValidRBTRee(Node* root, int blackCount, const int ref)
	{
		// �ݹ��ߵ��ս�㣬����·��������������·���ϵĺ�ɫ�������ο�ֵ���ȶԣ���ο�ֵ������򷵻�false
		if (root == nullptr)
		{
			// Υ�����������4
			if (blackCount != ref)
			{
				return false;
			}

			return true;
		}

		// �����ǰ���Ϊ��ɫ�Ҹ����Ϊ��ɫ���򷵻�false
		// Υ�����������3
		if (root->_col == RED && root->_parent->_col == RED)  // root->_col == RED ��ȷ����root������Ϊ����㣬��Ϊ�����һ��Ϊ��ɫ
		{
			return false;
		}

		if (root->_col == BLACK)
		{
			++blackCount;
		}

		return _IsValidRBTRee(root->_left, blackCount, ref) && _IsValidRBTRee(root->_right, blackCount, ref);
	}

private:
	Node* _root;
};