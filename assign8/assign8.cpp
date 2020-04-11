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
		left = NULL;
		right = NULL;
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

	void callAscending()
	{
		Ascending(root);
	}

	void Ascending(Node *t)
	{
		if (t != NULL)
		{
			Ascending(t->left);
			cout << t->key << "\t";
			Ascending(t->right);
		}
	}

	void callDescending()
	{
		Descending(root);
	}

	void Descending(Node *t)
	{
		if (t != NULL)
		{
			Descending(t->right);
			cout << t->key << "\t";
			Descending(t->left);
		}
	}

	// important functions

	Node *insert(Node *t, string x)
	{
		if (t == NULL) // if the tree is empty
		{
			Node *temp = new Node;
			temp->key = x;
			temp->left = NULL;
			temp->right = NULL;
			t = temp;
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
			}
			else if (x < t->key)
			{
				t->left = insert(t->left, x);
				if (BF(t) == 2)
					if (x > t->left->key)
						t = LR(t);
					else
						t = LL(t);
			}
		}
		t->ht = height(t);
		return t;
	}

	int BF(Node *t)
	{
		int lh, rh;
		if (t == NULL)
			return 0;

		lh = height(t->left);
		rh = height(t->right);
		return (lh - rh);
	}

	int height(Node *t)
	{
		int lh, rh;
		if (t == NULL)
			return 0;

		lh = height(t->left);
		rh = height(t->right);

		if (lh > rh)
			return (lh + 1);
		else
			return (rh + 1);
	}

	Node *rightrotate(Node *p)
	{
		Node *q;

		q = p->left;
		p->left = q->right;
		q->right = p;
		p->ht = height(p);
		q->ht = height(q);
		return q;
	}

	Node *leftrotate(Node *p)
	{
		Node *q;

		q = p->right;
		p->right = q->left;
		q->left = p;
		p->ht = height(p);
		q->ht = height(q);
		return q;
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

	void find(string t)
	{
		Node *r = root;
		int flag = 0;
		int comp = 1;

		do
		{
			if (r == NULL)
				cout << "Keyword Not Found" << endl;
			else
			{

				if (r->key == t)
				{
					cout << "Found!! \n Comparisons = " << comp << endl;
					flag = 1;
				}
				else if (root->key < t)
				{
					// go to right
					r = r->right;
				}
				else
				{
					// go to left
					r = r->left;
				}
				comp++;
			}

		} while (flag == 0);
	}
};

int main()
{
	AVL A;

	A.callInsert("JAN");
	A.callInsert("FEB");

	A.callInsert("MAR");
	A.callInsert("APR");

	A.callAscending();
	cout << endl;
	A.callDescending();

	string t;
	cout << "Enter the keyword to be searched" << endl;
	cin >> t;
	A.find(t);
	return 0;
}
