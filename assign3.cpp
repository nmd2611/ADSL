//============================================================================
// Name        : assign3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node
{
private:
	int info;
	Node *left;
	Node *right;
	int rflag;
	Node()
	{
		info=0;
		left=NULL;
		right=NULL;
		rflag=0;
	}
public:
	friend class TBST;
};
// threaded bst
class TBST
{
private:
	Node *root;
public:
	Node *p,*q;
	TBST()
	{
		root=NULL;
		p=NULL;
		q=NULL;
	}

	void addNode()
	{
	int k;
	cout<<"Enter info"<<endl;
	cin>>k;

	p=new Node;
	q=new Node;
	p->info = k;
	if(root == NULL)
		root=p;
	else
	{
		int flag=0;
		q=root;
		do
		{
			if(q->info > k)
			{
				//go to left
				if(q->left == NULL)
				{
					q->left=p;
					p->right=q;
					p->rflag=1;
					flag=1;
				}
				else
					q=q->left;

			}
			else if(q->info < k)
			{
				//go to right
				if(q->right == NULL)
				{
					q->right =p;
					flag=1;
				}
				else if(q->rflag == 1)
				{
					p->right=q->right;
					p->rflag=1;
					q->right=p;
					q->rflag=0;
					flag=1;
				}
				else
					q=q->right;
			}
			else
				break;
		}
		while(flag==0);
	}
}

	void callInOrder()
	{
		inOrder();
		cout<<endl;
	}
	void inOrder()
	{
		q=root;
		if(q == NULL)
			cout<<"Empty List";
		else
		do
		{
			while(q->left != NULL)
				q=q->left;

			cout<<q->info<<"\t";

			while(q->right!=NULL)
			{
			q=q->right;
			cout<<q->info<<"\t";
			}
		}while(q->right != NULL);

	}

	void callPreOrder()
	{
		preOrder();
		cout<<endl;
	}
	void preOrder()
	{
		q=root;
		if(q == NULL)
			cout<<"Empty List";
		else
		{
		cout<<q->info<<"\t";
		do
		{
		while(q->left != NULL)
		{
			q=q->left;
			cout<<q->info<<"\t";
		}

		while(q->right != NULL)
		{
			if(q->rflag == 1)
				q=q->right;
			else
			{
				q=q->right;
				cout<<q->info<<"\t";
			}
		}
	}while(q->right != NULL);
	}
	}
};
int main()
{
	TBST b1;
	cout<<"***** THREADED BINARY SEARCH TREE *****"<<endl;
	cout<<endl;
	int ch;
	char C;
	do
	{
	cout<<" 1.Add Node \n 2.InOrder Traversal \n 3.PreOrder traversal "<<endl;
	cin>>ch;
	switch(ch)
	{
	case 1:
			b1.addNode();
			break;

	case 2:
			b1.callInOrder();
			break;

	case 3:
			b1.callPreOrder();
			break;

	default:
			cout<<"Wrong Choice !"<<endl;
			break;
	}
	cout<<"Continue ? (y/n)"<<endl;
	cin>>C;
	} while(C == 'y');
	return 0;
}
