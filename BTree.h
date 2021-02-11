#pragma once
#include <iostream>
using namespace std;
template<typename T>
class BTree
{
public:
	BTree() = default;
	void add(const T& num);
	void print()const;
	void clear();

	const T& min()const;
	const T& max()const;
	bool find(const T& num)const;
	bool isEmpty()const;
	const size_t getSize()const;
	void printBigger(const T& num)const;
	~BTree();
private:
	struct Node {
		T num;
		Node* right, * left, * parent;
		Node(const T& num = T(), Node* right = nullptr, Node* left = nullptr, Node* parent = nullptr)
			:num(num), right(right), left(left), parent(parent)
		{}
	};
	Node* root = nullptr;
	size_t size = 0;
	void printHelper(Node* node)const; // recursive func
	void clear(Node* node);
};

template<typename T>
inline void BTree<T>::add(const T& num)
{
	Node* addNode = new Node(num);
	if (isEmpty())
	{
		root = addNode;
		return;
	}
	bool found = false;
	Node* tmp = root;
	while (!found)
	{
		if (num > tmp->num)
		{
			if (tmp->right == nullptr)
			{
				tmp->right = addNode;
				addNode->parent = tmp;
				found = true;
			}
			else {
				tmp = tmp->right;
			}
		}
		else {
			if (tmp->left == nullptr)
			{
				tmp->left = addNode;
				addNode->parent = tmp;
				found = true;
			}
			else {
				tmp = tmp->left;
			}
		}
	}
	++size;
}

template<typename T>
inline void BTree<T>::print() const
{
	cout << "TREE " << endl;
	printHelper(root);
}

template<typename T>
inline void BTree<T>::clear()
{
	if (isEmpty())
	{
		return;
	}
	clear(root);
}

template<typename T>
inline const T& BTree<T>::min() const
{
	if (isEmpty())
	{
		cout << "Empty" << endl;
		return T();
	}
	Node* res = root;
	while (res->left != nullptr)
	{
		res = res->left;
	}
	return res->num;
}

template<typename T>
inline const T& BTree<T>::max() const
{
	if (isEmpty())
	{
		cout << "Empty" << endl;
		return T();
	}
	Node* res = root;
	while (res->right != nullptr)
	{
		res = res->right;
	}
	return res->num;
}

template<typename T>
inline bool BTree<T>::find(const T& num)const
{
	if (isEmpty())
	{
		return false;
	}
	Node* tmp = root;
	while (tmp != nullptr)
	{
		if (num == tmp->num)
		{
			return true;
		}
		else if (tmp->num < num)
		{
			tmp = tmp->right;
		}
		else if (tmp->num > num)
		{
			tmp = tmp->left;
		}

	}
	return false;
}

template<typename T>
inline bool BTree<T>::isEmpty() const
{
	return root == nullptr;
}

template<typename T>
inline const size_t BTree<T>::getSize() const
{
	return size;
}

template<typename T>
inline void BTree<T>::printBigger(const T& num) const
{
	if (isEmpty())
	{
		return;
	}
	Node* temp = root;
	while (temp != nullptr)
	{
		if (temp->num > num)
		{
			cout << temp->num << endl;
		}
		temp = temp->left;
	}
	while (temp != nullptr)
	{
		if (temp->num > num)
		{
			cout << temp->num << endl;
		}
		temp = temp->right;
	}

}

template<typename T>
inline BTree<T>::~BTree()
{
	clear();
}

template<typename T>
inline void BTree<T>::printHelper(BTree<T>::Node* node)const
{
	if (node != nullptr)
	{
		printHelper(node->left);
		cout << node->num << "\t";
		printHelper(node->right);
	}
}

template<typename T>
inline void BTree<T>::clear(Node* node)
{
	if (node != nullptr)
	{
		clear(node->left);
		clear(node->right);
		cout << "~~~~ Deleted " << node->num << endl;
		delete node;
	}
}