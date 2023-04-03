#pragma once

#include <iostream>
using namespace std;

enum Color
{
	RED,
	BLACK
};

template <class K, class V>
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


template <class K, class V>
struct RBTree
{
	typedef RBTreeNode<K, V> Node;

public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;

			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		cur->_col = RED;
		if (kv.first > parent->_kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 检查并调整结点颜色
		while (parent && parent->_col == RED)
		{
			Node* grandParent = parent->_parent;

			if (parent == grandParent->_left)  // parent在grandParent左边的情况
			{
				Node* uncle = grandParent->_right;

				// 情况一：uncle存在且为红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandParent->_col = RED;

					cur = grandParent;
					parent = cur->_parent;
				}
				// 情况二和情况三
				else
				{
					// 情况二：uncle不存在 或 uncle存在且为黑 (grandParent，parent，cur在直线上)
					if (cur == parent->_left)
					{
						RotateR(grandParent);

						grandParent->_col = RED;
						parent->_col = BLACK;
					}
					// 情况三：uncle不存在 或 uncle存在且为黑 (grandParent，parent，cur在折线上)
					else
					{
						RotateL(parent);
						RotateR(grandParent);

						grandParent->_col = RED;
						cur->_col = BLACK;
					}

					// 因为情况二和情况三处理完后，顶上最终的grandParent都会改为黑色，
					// 即不会与其上面的parent形成连续两个红色的情况，所以处理完后break即可。
					break;
				}
			}
			else  // parent在grandParent右边的情况
			{
				Node* uncle = grandParent->_left;

				// 情况一：uncle存在且为红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandParent->_col = RED;

					cur = grandParent;
					parent = cur->_parent;
				}
				// 情况二和情况三
				else
				{
					// 情况二：uncle不存在 或 uncle存在且为黑 (grandParent，parent，cur在直线上)
					if (cur == parent->_right)
					{
						RotateL(grandParent);

						grandParent->_col = RED;
						parent->_col = BLACK;
					}
					// 情况三：uncle不存在 或 uncle存在且为黑 (grandParent，parent，cur在折线上)
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

	void InOrder()
	{
		_InOrder(_root);
	}

	bool IsRBTree()
	{
		if (_root == nullptr)
		{
			return true;
		}

		if (_root->_col != BLACK)
		{
			return false;
		}

		// 将最左路径上的黑结点数量记录下来，作为参考值
		Node* left = _root;
		int ref = 0;
		while (left)
		{
			if (left->_col == BLACK)
			{
				++ref;
			}

			left = left->_left;
		}

		return Check(_root, 0, ref);
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

	bool Check(Node* root, int blackNum, const int ref)
	{
		if (root == nullptr)
		{
			// 违反红黑树性质4
			if (blackNum != ref)
			{
				return false;
			}

			return true;
		}

		// 违反红黑树性质3
		if (root->_col == RED && root->_parent->_col == RED)
		{
			return false;
		}

		if (root->_col == BLACK)
		{
			++blackNum;
		}

		return Check(root->_left, blackNum, ref) && Check(root->_right, blackNum, ref);
	}

private:
	Node* _root = nullptr;
};