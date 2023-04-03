#pragma once

#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

template <class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);

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
			else  // 元素已存在，返回false
			{
				return false;
			}
		}

		cur = new Node(kv);
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

		// 更新父结点的平衡因子
		while (parent)
		{
			// 新插入的结点在父结点的左边则父结点的平衡因子--
			// 新插入的结点在父结点的右边则父结点的平衡因子++
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			// 若父结点的平衡因子为0，则不会往上影响到上面的祖先结点
			// 若父结点的平衡因子为1/-1，则会影响到上面的祖先结点
			// 1.父结点在爷爷结点的左边，则爷爷结点的平衡因子--
			// 2.父结点在爷爷结点的右边，则爷爷结点的平衡因子++
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == -1 || parent->_bf == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == -2 || parent->_bf == 2)
			{
				// AVL树出错，用旋转解决

				// 1.新结点插入在较高右子树的右侧--右右：左单旋
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				// 2.新结点插入在较高左子树的左侧--左左：右单旋
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				// 3.新结点插入在较高左子树的右侧--左右：先左单旋，再右单旋
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				// 3.新结点插入在较高右子树的左侧--右左：先右单旋，再左单旋
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else
				{
					assert(false);
				}

				break;
			}
			else
			{
				assert(false);
			}
		}

		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
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

		parent->_bf = subR->_bf = 0;
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

		parent->_bf = subL->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		int bf = subLR->_bf;

		RotateL(subL);
		RotateR(parent);

		// 更新结点的平衡因子
		if (bf == -1)  // 新结点插入在subLR的左侧
		{
			subL->_bf = 0;
			parent->_bf = 1;
			subLR->_bf = 0;
		}
		else if (bf == 1)  // 新结点插入在subLR的右侧
		{
			subL->_bf = -1;
			parent->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 0) // 新结点就是subLR
		{
			subL->_bf = 0;
			parent->_bf = 0;
			subLR->_bf = 0;
		}
		else  // 出错
		{
			assert(false);
		}
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		int bf = subRL->_bf;

		RotateR(subR);
		RotateL(parent);

		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			subR->_bf = 1;
			parent->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			subR->_bf = 0;
			parent->_bf = 0;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
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

	int getHeight(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int lh = getHeight(root->_left);
		int rh = getHeight(root->_right);

		return lh > rh ? lh + 1 : rh + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		int leftH = getHeight(root->_left);
		int rightH = getHeight(root->_right);

		return abs(rightH - leftH) < 2 && _IsBalance(root->_left) && _IsBalance(root->_right);
	}

private:
	Node* _root = nullptr;
};
