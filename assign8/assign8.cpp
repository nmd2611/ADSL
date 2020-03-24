//============================================================================
// Name        : assign8.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node
{
public:
	string key;
	Node *left;
	Node *right;
	int ht;

	Node()
	{
		key = "";
		left = right = NULL;
		ht = 0;
	}
};

class AVL
{
public:
	Node *root;
	AVL()
	{
		root = NULL;
	}
	//  trivial functions

	void callInsert(string x)
	{
		root = insert(root, x);
	}

	void callInorder()
	{
		inOrder(root);
	}

	void inOrder(Node *t)
	{
		if (t)
		{
			inOrder(t->left);
			cout << t->key << "\t" << BF(t) << endl;
			inOrder(t->right);
		}
	}

	// important functions

	Node *insert(Node *t, string x)
	{
		if (t == NULL) // if the tree is empty
		{
			t = new Node;
			t->key = x;
			t->left = NULL;
			t->right = NULL;
		}
		else
		{
			/* code */
			if (x > t->key)
			{
				t->right = insert(t->right, x);
				if (BF(t) == -2)
				{
					if (x > t->right->key)
					{
						t = RR(t);
					}
					else
					{
						t = RL(t);
					}
				}

				else if (x < t->key)
				{
					t->left = insert(t->left, x);
					if (BF(t) == 2)
						if (x < t->left->key)
							t = LL(t);
						else
							t = LR(t);
				}
			}

			t->ht = height(t);
			return t;
		}
	}

	int BF(Node *t)
	{
		int lh, rh;
		if (t == NULL)
			return 0;

		if (t->left == NULL)
			lh = 0;
		else
			lh = 1 + t->left->ht;

		if (t->right == NULL)
			rh = 0;
		else
			rh = 1 + t->right->ht;

		return (lh - rh);
	}

	int height(Node *t)
	{
		int lh, rh;
		if (t == NULL)
			return 0;

		if (t->left == NULL)
			lh = 0;
		else
			lh = 1 + t->left->ht;

		if (t->right == NULL)
			rh = 0;
		else
			rh = 1 + t->right->ht;

		if (lh > rh)
			return lh;
		else
			return rh;
	}

	Node *rightrotate(Node *p)
	{
		Node *q;
		if (p)
		{
			q = p->left;
			p->left = q->right;
			q->right = p;
			p->ht = height(p);
			q->ht = height(q);
			return q;
		}
		return NULL;
	}

	Node *leftrotate(Node *p)
	{
		Node *q;
		if (p)
		{
			q = p->right;
			p->right = q->left;
			q->left = p;
			p->ht = height(p);
			q->ht = height(q);
			return q;
		}
		return NULL;
	}

	Node *RR(Node *t)
	{
		t = leftrotate(t);
		return t;
	}

	Node *LL(Node *t)
	{
		t = rightrotate(t);
		return t;
	}

	Node *LR(Node *t)
	{
		t->left = leftrotate(t->left);
		t = rightrotate(t);
		return t;
	}

	Node *RL(Node *t)
	{
		t->right = rightrotate(t->right);
		t = leftrotate(t);
		return t;
	}
};

int main()
{
	AVL A;

	A.callInsert("JAN");
	A.callInsert("FEB");
	A.callInsert("MAR");
	A.callInsert("APR");
	A.callInorder();

	return 0;
}
