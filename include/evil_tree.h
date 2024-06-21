#pragma once
//Так-то это AVL tree, просто Evil tree звучит интереснее
//Типо злое дерево >:(
//Как в The Witcher|||, только еще злее и еще дубовее

#include "iostream"
using namespace std;

template <typename TValue>
class evil_tree {
private:
	struct Node
	{
		string key;
		TValue val;
		Node* left;
		Node* right;
		int height;

		Node(const string& key, TValue& val) : key(key), val(val), left(nullptr), right(nullptr), height(1) {}
	};

	Node* root;

	int Height(Node* n)
	{
		if (n == nullptr) return 0;
		else return n->height;
	}

	int Node_Balance(Node* n)
	{
		if (n == nullptr) return 0;
		else return (Height(n->left) - Height(n->right));
	}

	Node* Left(Node* l)
	{
		Node* l1 = l->right;
		Node* tmp = l1->left;

		l1->left = l;
		l->right = tmp;

		l->height = max(Height(l->left), Height(l->right)) + 1;
		l1->height = max(Height(l1->left), Height(l1->right)) + 1;

		return l1;
	}

	Node* Right(Node* r)
	{
		Node* r1 = r->left;
		Node* tmp = r1->right;

		r1->right = r;
		r->left = tmp;

		r->height = max(Height(r->left), Height(r->right)) + 1;
		r1->height = max(Height(r1->left), Height(r1->right)) + 1;

		return r1;
	}

	Node* MinNode(Node* n)
	{
		Node* tmp = n;
		while (tmp->left != nullptr)
			tmp = tmp->left;

		return tmp;
	}

	Node* Find(Node* n, const string& key)
	{
		while ((n != nullptr) and (key != n->key))
			if (key < n->key) n = n->left;
			else n = n->right;

		return n;
	}

	Node* Insert(Node* n, const string& key, TValue val)
	{
		if (!n) return new Node(key, val);

		if (key < n->key)
			n->left = Insert(n->left, key, val);
		else if (key > n->key)
			n->right = Insert(n->right, key, val);
		else
			n->val = val;

		n->height = max(Height(n->left), Height(n->right)) + 1;
		int bal = Node_Balance(n);

		if ((bal > 1) and (key < (n->left)->key))
			return Right(n);

		if ((bal < -1) and (key > (n->right)->key))
			return Left(n);

		if ((bal > 1) and (key > (n->left)->key))
		{
			n->left = Left(n->left);
			return Right(n);
		}

		if ((bal < -1) and (key < (n->right)->key))
		{
			n->right = Right(n->right);
			return Left(n);
		}
		return n;
	}

	Node* Delete(Node* n, const string& key)
	{
		if (!n) return n;

		if (key < n->key)
			n->left = Delete(n->left, key);
		else if (key > n->key)
			n->right = Delete(n->right, key);
		else
		{
			if ((!n->left) or (!n->right))
			{
				Node* tmp = n->left ? n->left : n->right;
				if (!tmp)
				{
					tmp = n;
					n = nullptr;
				}
				else
					*n = *tmp;
				delete tmp;
			}
			else
			{
				Node* tmp = MinNode(n->right);
				n->key = tmp->key;
				n->val = tmp->val;
				n->right = Delete(n->right, tmp->key);
			}
		}

		if (!n) return n;

		n->height = max(Height(n->left), Height(n->right)) + 1;
		int bal = Node_Balance(n);

		if ((bal > 1) and (Node_Balance(n->left) >= 0))
			return Right(n);

		if ((bal < -1) and (Node_Balance(n->right) <= 0))
			return Left(n);

		if ((bal > 1) and (Node_Balance(n->left) >= 0))
		{
			n->left = Left(n->left);
			return Right(n);
		}

		if ((bal < -1) and (Node_Balance(n->right) > 0))
		{
			n->right = Right(n->right);
			return Left(n);
		}
		return n;
	}

	void Print_Tree(Node* n)
	{
		cout << "\n";
		if (n != nullptr)
		{
			Print_Tree(n->left);
			cout << "key:" << n->key << "\t||\t" << n->val;
			//n->val.Print();
			cout << "\n";
			Print_Tree(n->right);
		}
		//else cout << "not found\n";
	}

public:
	evil_tree() : root(nullptr) {}

	TValue* Find(const string& key)
	{
		if (root != nullptr)
		{
			Node* n = Find(root, key);
			if (n != nullptr)
				return &n->val;
			else
				return nullptr;
		}
		else return nullptr;
	}

	void Insert_Elem(const string key, TValue val)
	{
		root = Insert(root, key, val);
	}

	void Delete_Special_Node(Node* n)
	{
		if (n == nullptr || (!Find(root, n->key))) return;

		Delete(root, n->key);
	}

	void Delete_Node_With_Key(string key)
	{
		Node* n = Find(root, key);
		if (n == nullptr) return;

		Delete(root, key);

	}

	void print()
	{
		cout << "\n";
		Print_Tree(root);
	}
};