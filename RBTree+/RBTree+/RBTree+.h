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
		// 当前红黑树为空树，new一个结点作为根结点
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;  // 红黑树的性质规定，根结点必须为黑色

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
			else  // 红黑树中纯在相同Key的结点，插入失败，返回false
			{
				return false;
			}
		}

		// new一个结点并插入到cur当前所在位置
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

		// 检查并调整结点的颜色
		while (parent && parent->_col == RED)  // 父结点存在且父结点为红色才可能要继续调整结点的颜色
		{
			Node* grandParent = parent->_parent;

			// 1.parent在grandParent的左边
			if (parent == grandParent->_left)
			{
				Node* uncle = grandParent->_right;

				// 情况一：cur为红色，parent为红色，grandParent为黑色，uncle存在且为红色
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandParent->_col = RED;

					cur = grandParent;
					parent = cur->_parent;
				}
				// 情况二和情况三：cur为红色，parent为红色，grandParent为黑色，uncle不存在或uncle存在且为黑色
				else
				{
					// 情况二：(cur，parent，grandParent在直线上)
					if (cur == parent->_left)
					{
						RotateR(grandParent);

						grandParent->_col = RED;
						parent->_col = BLACK;
					}
					// 情况三：(cur，parent，grandParent在折线上)
					else
					{
						RotateL(parent);
						RotateR(grandParent);

						grandParent->_col = RED;
						cur->_col = BLACK;
					}

					// 因为情况二和情况三处理完后，顶上“最终的grandParent”都会改为黑色，
					// 即不会与其上面的parent形成连续两个红色的情况，所以处理完后break即可
					break;
				}
			}
			// 2.parent在grandParent的右边
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
					if (cur == parent->_right)
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
		// 当前红黑树为空，则直接返回false
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
			// 找到了
			else
			{
				return cur;
			}
		}

		// cur走到空都没找到对应的值，说明该红黑树中不存在该值，返回nullptr
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
		// 空树也算是红黑树
		if (_root == nullptr)
		{
			return true;
		}

		// 红黑树的根结点一定要是黑色，若根结点不为黑色，则返回false
		if (_root->_col != BLACK)
		{
			return false;
		}

		// 红黑树的所有路径的黑色结点的个数相同
		// 将最左路径中黑色结点的个数记录下来，作为参考值，与其他的路径进行比对
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
		// 递归走到空结点，该条路径结束，将该条路径上的黑色结点树与参考值做比对，与参考值不相等则返回false
		if (root == nullptr)
		{
			// 违反红黑树性质4
			if (blackCount != ref)
			{
				return false;
			}

			return true;
		}

		// 如果当前结点为红色且父结点为红色，则返回false
		// 违反红黑树性质3
		if (root->_col == RED && root->_parent->_col == RED)  // root->_col == RED 就确保了root不可能为根结点，因为根结点一定为黑色
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
