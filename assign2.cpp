//============================================================================
// Name        : assign2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:

	string key;
	string mean[10];
	Node *left;
	Node *right;

	Node()
	{
		left=NULL;
		right=NULL;
		key="";
	}
};

class BST
{
public:
	Node *root,*p,*q;
	int cnt;
	stack <string> s;

	BST()
	{
		root=NULL;
		p=NULL;
		q=NULL;
		cnt=0;

	}
	void addNode()
	{
		string k;
		cout<<"Enter key"<<endl;
		cin>>k;

		p=new Node;
		q=new Node;
		p->key = k;
		if(root == NULL)
			root=p;
		else
		{
			int flag=0;
			q=root;
			do
			{
				if(q->key > k)
				{
					//go to left
					if(q->left == NULL)
					{
						q->left=p;
						flag=1;
					}
					else
						q=q->left;

				}
				else if(q->key < k)
				{
					//go to right
					if(q->right == NULL)
					{
						q->right =p;
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

	void printA()
	{
		inOrderR(root);
	}

	void orderT(Node *r)
	{
		if(r)
		{
			inOrderR(r -> left);
			//cout<<r->key<<"\t";
			s.push(r->key);
			inOrderR(r -> right);
		}
	}


	void printD()
	{
		orderT(root);
		while(!s.empty())
		{
			cout<<s.top()<<"\t";
			s.pop();
		}
	}


	Node * searchNode(string k)
	{
		p=NULL;
		q=root;
		p=new Node;
		int flag=0;
		cnt=0;
		if(q!=NULL)
			do
			{
				flag=0;
				if(q->key < k)
				{
							//goto right
					q=q->right;
					cnt++;
				}
				else if(q->key >k)
				{
				      //goto left
					q=q->left;
					cnt++;
				}
				else if(q->key == k)
				{
					// if found , delete the node
					flag=1;
					cnt++;
					break;
				}
			}while(flag==0 && q!=NULL);

		return q;
	}


//	void deleteNode(string k)
//	{
//		Node *temp;
//		Node *r; 	// NOde to be used for deleting a middle node
//		p=NULL;
//		q=root;
//		p=new Node;
//		int flag=0;
//		if(q!=NULL)
//			do
//			{
//				flag=0;
//				if(q->key < k)
//				{
//					p=q;		//goto right
//					q=q->right;
//				}
//				else if(q->key >k)
//				{
//					p=q;  //goto left
//					q=q->left;
//				}
//				else if(q->key == k)
//				{
//					// if found , delete the node
//					temp=new Node;
//					//case 1. for a tree with root node only
//					if(q == root && q->left!=NULL && q->right!=NULL)
//					{
//						temp=q;
//						delete temp;
//						cout<<"Deleted successfully"<<endl;
//					}
//					// case 2. for leaf nodes
//					/*
//					else if(q->left == NULL && q->right == NULL && p!=root)
//					{
//
//						temp = q;
//						delete temp;
//						cout<<"Deleted successfully"<<endl;
//					}
//					*/
//					// for node with 1 child
//					else if(q->left == NULL)
//					{
//						if(p->left == q)
//							p->left=q->right;
//						else if(p->right == q)
//							p->right = q->right;
//						temp = q;
//						delete temp;
//						cout<<"Deleted successfully"<<endl;
//					}
//					else if(q->right == NULL)
//					{
//						if(p->left == q)
//							p->left=q->left;
//						else if(p->right == q)
//							p->right = q->left;
//						temp = q;
//						delete temp;
//						cout<<"Deleted successfully"<<endl;
//					}
//					// case 3. for a middle node
//					else
//					{
//						Node *rp;
//						rp=new Node;
//						rp=NULL;
//						r=new Node;
//						r=q->right;
//						while(r->left != NULL)
//						{
//							rp=r;
//							r=r->left;
//						}
//						swap(r->key, q->key);
//
//						temp=r;
//						rp->left = r->left;
//						rp->right = r->right;
//
//						delete temp;
//					}
//					flag=1;
//					break;
//				}
//			}while(flag==0 && q!=NULL);
//		if(flag)
//			cout<<"found"<<endl;
//	}
//// end of the function

	void deleteNode(string k)
	{
		q=NULL;
		int flag=0;
		Node *temp;
		q= searchNode(k);
		if(q == NULL)
			cout<<"Element not found"<<endl;
		else
		{
			q=root;
			do
			{
			if(q->key > k)
			{
				p=q;
				q=q->left;
			}
			else if(q->key < k)
			{
				p=q;
				q=q->right;
			}
			else
			{
				if(q->left == NULL && q!=root)
				{

					if(p->left == q)
						p->left= q->right;
					else
						p->right =q->right;

					temp =q;
					q->right= NULL;
					delete temp;
					flag=1;
				}
				else if(q->right == NULL && q!=root)
				{
					if(p->left == q)
						p->left = q->left;
					else
						p->right = q->left;
					temp =q;
					q->left=NULL;
					delete temp;
					flag=1;
				}
				else if(q!=root)
				{
					Node *r,*s;
					s= q->right;
					if(s->left != NULL)
					{
						while(s->left != NULL)
						{
							r=s;
							s=s->left;
						}

						swap(q->key,s->key);
						r->left= s->right;
						s->right=NULL;
						temp=s;
						delete temp;
						flag=1;
					}
					else
					{
						// s ka left is null
						swap(q->key,s->key);
						q->right=s->right;
						s->right=NULL;
						temp = s;
						delete temp;
						flag=1;
					}

				}
				else
				{
					// special case where root has 1 child and root is to be deleted
					// root ka left = null
					if(q->left == NULL)
					{
						temp=q;
						root=root->right;
						delete temp;
						flag=1;
					}
					// root ka right =null
					else if(q->right == NULL)
					{
						temp=q;
						root=root->left;
						delete temp;
						flag=1;

					}
				}
			}
		}while(flag == 0);
		}

	}

	void callSearch(string k)
	{
		p=new Node;
		q=new Node;
		q= searchNode(k);
		if(q!=NULL)
			cout<<"Key Found.\nComparisons ="<<cnt<<endl;
		else
			cout<<"Key Not found.\nComparisons ="<<cnt<<endl;
	}


	void callInOrderR()
	{
		inOrderR(root);
	}
	void inOrderR(Node *r)
	{
		if(r)
		{
			inOrderR(r -> left);
			cout<<r->key<<"\t";
			inOrderR(r -> right);
		}
	}

	/*
	Node *copy()
	{
		Node *P;
		P=NULL;
		if(r)
		{
			p= new Node;
			P->key = r->key;
			P->left = operator=(r->left);
			P->right = operator=(r->right);

		}
		return P;
	}
	Node *operator=(Node *r)
	{

	}
*/
	/*
	Node *operator=(Node *r)
	{
		Node *Q;
		Q=NULL;
		if(r)
		{
			Q= new Node;
			Q->key = r->key;
			Q->left = operator=(r->left);
			Q->right = operator=(r->right);

		}
		return Q;
	}
	*/
	Node *copyN(Node *r)
	{
		Node *Q;
		Q=NULL;
		if(r)
		{
			Q= new Node;
			Q->key = r->key;
			Q->left = copyN(r->left);
			Q->right = copyN(r->right);

		}
		return Q;
	}

	BST operator=(BST b)
	{
		BST P;
		//P = new BST;

		P.root= copyN(b.root);
		P.callInOrderR();
		//cout<<&P<<endl;
		return P;

	}
/*
	BST operator=(BST b)
	{
		//BST P;
		//P = new BST;

		root= copyN(b.root);
		//callInOrderR();
		return *this;

	}
	*/
};

int main()
{
	BST b1;
	BST b2;
	int ch;
	string k;
	char C='y';
	do
	{
		cout<<"1. Add Key \n2. Display inOrder \n3. Copy Tree \n4. Display in ascending \n5. Display in descending \n6. Search for a key \n7. Delete a key"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
					b1.addNode();
					break;

			case 2:
					b1.callInOrderR();
					break;

			case 3:
					b2=b1;
					cout<<"Tree copied successfully"<<endl;
					//cout<<b2.root->key<<endl;
					b2.callInOrderR();
					cout<<&b2<<endl;
					break;

			case 4:
					b1.printA();
					break;

			case 5:
					b1.printD();
					break;

			case 6:

					cout<<"Enter the key to be searched"<<endl;
					cin>>k;
					b1.callSearch(k);
					//cout<<"Key deleted successfully"<<endl;
					break;

			case 7:
					cout<<"Enter the key to be deleted"<<endl;
					cin>>k;
					b1.deleteNode(k);
					cout<<"Key deleted successfully"<<endl;
					break;


			default:
					cout<<"Wrong choice"<<endl;
					break;
		}
		cout<<"Continue (y/n)?"<<endl;
		cin>>C;
	} while(C == 'y');

/*
	string a="abcde";
	string b="abcd";

	if(a>b)
		cout<<a;
	else
		cout<<b;
*/
	cout<<"Program Terminated successfully"<<endl;
	return 0;
}
