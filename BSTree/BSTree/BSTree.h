#pragma once

#include <iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode(const K& key)
		:_key(key)
		, _left(nullptr)
		, _right(nullptr)
	{}

	BSTreeNode* _left;
	BSTreeNode* _right;
	K _key;
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> BSTNode;

public:
	BSTree()
		:_root(nullptr)
	{}

	BSTree(const BSTree<K>& t)
	{
		_root = Copy(t._root);
	}

	BSTree<K>& operator=(BSTree<K> t)
	{
		swap(_root, t._root);
		return *this;
	}

	~BSTree()
	{
		Destroy(_root);
		_root = nullptr;
	}

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new BSTNode(key);

			return true;
		}

		BSTNode* parent = nullptr;
		BSTNode* cur = _root;

		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		if (key > parent->_key)
		{
			parent->_right = new BSTNode(key);
		}
		else
		{
			parent->_left = new BSTNode(key);
		}

		return true;
	}

	bool Erase(const K& key)
	{
		if (_root == nullptr)
		{
			return false;
		}

		BSTNode* parent = nullptr;
		BSTNode* cur = _root;

		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else  // 找到结点，并删除
			{
				// 1.左为空
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}

					delete cur;
				}
				// 2.右为空
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}

					delete cur;
				}
				// 3.左右都不为空
				else
				{
					parent = cur;
					BSTNode* minRight = cur->_right;

					while (minRight->_left)
					{
						parent = minRight;
						minRight = minRight->_left;
					}

					cur->_key = minRight->_key;

					if (minRight == parent->_left)
					{
						parent->_left = minRight->_right;
					}
					else
					{
						parent->_right = minRight->_right;
					}

					delete minRight;
				}

				return true;
			}
		}

		return false;
	}

	bool Find(const K& key)
	{
		BSTNode* cur = _root;

		while (cur)
		{
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}

		return false;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	// 插入递归版本
	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}

	// 删除递归版本
	bool EraseR(const K& key)
	{
		return _EraseR(_root, key);
	}

	// 查找递归版本
	bool FindR(const K& key)
	{
		return _FindR(_root, key);
	}

private:
	void _InOrder(BSTNode* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	bool _InsertR(BSTNode*& root, const K& key)
	{
		if (root == nullptr)
		{
			root = new BSTNode(key);

			return true;
		}

		if (key > root->_key)
		{
			return _InsertR(root->_right, key);
		}
		else if (key < root->_key)
		{
			return _InsertR(root->_left, key);
		}
		else
		{
			return false;
		}
	}

	bool _EraseR(BSTNode*& root, const K& key)
	{
		if (root == nullptr)
		{
			return false;
		}

		if (key > root->_key)
		{
			return _EraseR(root->_right, key);
		}
		else if (key < root->_key)
		{
			return _EraseR(root->_left, key);
		}
		else
		{
			BSTNode* del = root;

			if (root->_left == nullptr)
			{
				root = root->_right;
			}
			else if (root->_right == nullptr)
			{
				root = root->_left;
			}
			else
			{
				BSTNode* minRight = root->_right;
				while (minRight->_left)
				{
					minRight = minRight->_left;
				}

				swap(root->_key, minRight->_key);

				return _EraseR(root->_right, key);
			}

			delete del;

			return true;
		}
	}

	bool _FindR(BSTNode* root, const K& key)
	{
		if (root == nullptr)
		{
			return false;
		}

		if (key > root->_key)
		{
			return _FindR(root->_right, key);
		}
		else if (key < root->_key)
		{
			return _FindR(root->_left, key);
		}
		else
		{
			return true;
		}
	}

	void Destroy(BSTNode* root)
	{
		if (root == nullptr)
		{
			return;
		}

		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
	}

	BSTNode* Copy(BSTNode* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		BSTNode* newTreeNode = new BSTNode(root->_key);
		newTreeNode->_left = Copy(root->_left);
		newTreeNode->_right = Copy(root->_right);

		return newTreeNode;
	}

private:
	BSTNode* _root = nullptr;
};
