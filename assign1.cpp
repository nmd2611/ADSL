//============================================================================
// Name        : assign1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stack>
using namespace std;

class Node
{
public:
	int info;
	Node *left;
	Node *right;

	Node()
	{
		left = NULL;
		right = NULL;
	}
};

class El
{
public:
	Node *data;
	El *next;
	El()
	{
		next = NULL;
	}
};

class Stack
{
public:
	El *first,*last, *newn;
	Stack()
	{
		first= NULL;
		last =NULL;
	}

	void push(Node *p)
	{
		newn = new El;
		newn -> data =p;
		newn -> next = NULL;
		if(first == NULL)
		{
			first=newn;
			last=newn;
		}
		else
		{
			newn -> next = first;
			first = newn;
		}


	}
	void pop()
	{
		El *temp;
		//temp= new El;
		temp=first;
		first = temp ->next;
		delete temp;
	}
	Node *top()
	{
		if(first != NULL)
			return (first->data);

	}
	int empty()
	{
		if(first == NULL)
			return 1;
		else
			return 0;

	}

};



class BTree
{
public:
	Node *root, *p, *q;


	BTree()
	{
		root=NULL;
		p=NULL;
		q=NULL;
	}
// function to add node in the tree
	void addNode(int x)
	{
		p= new Node;
		int flag=0;
		char ch;
		p->info= x;
	//	p ->left = NULL;
	//	p -> right = NULL;
		if(root == NULL)
		{
			root = p;
			cout<<" Root Inserted"<<endl;

		}
		else
		{
			q = root;
			flag=0;
			do{
			cout<<"Enter choice: L or R"<<endl;
			cin>>ch;
			if(ch == 'L' || ch == 'l')
			{
				if(q -> left == NULL)
				{
					q -> left = p;
					cout<<" Inserted"<<endl;
					flag=1;
				}
				else
					q = q->left;
			}

			else if(ch == 'R' || ch == 'r')
			{

				if(q -> right == NULL)
				{
					q -> right = p;
					cout<<" Inserted"<<endl;
					flag=1;
				}
				else
					q = q ->right;
			}
			else
			{
				cout<<"wrong choice"<<endl;

			}

		} while(flag == 0);
		}
	}
// in order recursive call
	void inOrderR(Node *r)
	{
		if(r)
		{
			inOrderR(r -> left);
			cout<<r -> info<<"\t";
			inOrderR(r -> right);
		}
	}
/*
	void inOrder(Node *r)
	{
		//stack<Node *> s;
		Stack s;
		Node *q;
		q =new Node;
		q = r;

		do{
		while(q -> left != NULL && q!= NULL)
		{
			s.push(q);
			q = q ->left;
		}
		if(q != NULL)
		{
			cout<<q->info<<"\t";
			q= q-> right;
			continue;
		}
		else
			while(s.top() != NULL)
			{
				q = s.top();
				cout<<q->info<<"\t";
				q = q->right;
			}
		}while(q != NULL || !s.empty());

	}
*/
	// Non recursive inOrder
	void inOrder(Node *r)
	{
		Stack s;
		//stack<Node *> s;
		q= r;
		int flag=0;

		while(flag== 0)
		{
			if(q!= NULL)
			{
				s.push(q);
				q= q->left;
			}
			else if(!s.empty())
			{
				q=s.top();
				s.pop();
				cout<< q->info<<"\t";
				q = q->right;
			}
			else
				flag=1;
		}

	}

	// non recursive preOrder
	void preOrder(Node *r)
	{
		Stack s;
		//stack<Node *> s;
		q= r;
		int flag=0;

		while(flag== 0)
		{
			if(q!= NULL)
			{
				cout<< q->info<<"\t";
				s.push(q);
				q= q->left;
			}
			else if(!s.empty())
			{
				q=s.top();
				s.pop();
				q = q->right;
			}
			else
				flag=1;
		}
	}

	/*
	void postOrder(Node *r)
	{
		Stack s;
		//stack<Node *> s;
		q= r;
		int flag=0;

		while(flag== 0)
		{
			if(q!= NULL)
			{
				s.push(q);
				q= q->left;
			}
			else if(!s.empty())
			{
				q = q->right;
				q=s.top();
				s.pop();
				cout<< q->info<<"\t";

			}
			else
				flag=1;
		}
	}
*/

	// pre order recursive
	void preOrderR(Node *r)
	{
		if(r)
		{
			cout<< r -> info<<"\t";
			preOrderR(r -> left);
			preOrderR(r -> right);
		}
	}
// post order recursive
	void postOrderR(Node *r)
		{
			if(r)
			{
				postOrderR(r -> left);
				postOrderR(r -> right);
				cout<< r -> info<<"\t";
			}
		}

	void printLeaf(Node *r)
	{
		if(r == NULL)
			return ;
		else if( r->left == NULL && r->right == NULL)
			cout<<r->info<<"\t";

		printLeaf(r->left);
		printLeaf(r->right);



	}

	void printInternal(Node *r)
	{
		if(r == NULL)
			return ;

		else if(r->left != NULL || r->right != NULL)
			{
			cout<<r->info<<"\t";
			printInternal(r->left);
			printInternal(r->right);
			}
	}

	void mirrorImage(Node *r)
	{
		if(r)
		{
			mirrorImage(r->left);
			mirrorImage(r->right);
			swap(r->left , r->right);
		}
	}

	void deleteTree(Node *r)
	{
		if(r)
		{
			deleteTree(r -> left);
			deleteTree(r -> right);

			// Deleting the node
			Node *temp = r;
			delete temp;

			if(root == r)
				root = NULL;
			//cout<< r -> info<<"\t";
		}
	}

	Node * operator=(Node *r)
	{
		Node *p;
		p=NULL;
		if(r)
		{
			p= new Node;
			p->info = r->info;
			p->left = operator=(r->left);
			p->right = operator=(r->right);

		}
		return p;
	}

	Node * returnR()
	{
		return root;
	}

};

	int check(Node *b1, Node *b2)
	{
		if(b1 == NULL && b2 == NULL)
			return 1;
		if(b1 != NULL && b2 != NULL)
		{
			if(b1->info == b2->info && check(b1->left,b2->left) && check(b1->right,b2->right))
				return 1;
		}
		return 0;
	}

	/*
	Node * Copy(Node *r)
	{
		Node *p;
		p=NULL;
		if(r)
		{
			p= new Node;
			p->info = r->info;
			p->left = Copy(r->left);
			p->right = Copy(r->right);

		}
		return p;
	}
	*/



/*

int main()
{
	Stack s;
	//BTree b;
	//b.root ->info = 100;
	cout<<s.empty()<<endl;

	Node *p;
	Node *q;
	p = new Node;
	q= new Node;
	p ->info = 100;
	s.push(p);
	cout<<s.top() ->info<<endl;

	cout<<s.empty()<<endl;

	q ->info = 200;
	s.push(q);
	cout<<s.top()->info<<endl;

	s.pop();
	//s.pop();
	cout<<s.top()->info<<endl;


	return 0;
}
*/

int main()
{
	BTree b;
	BTree b2;
	int n;
	cout<<"Enter the number of nodes"<<endl;
	cin>>n;
	int x;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter Element "<<endl;
		cin>>x;
		b.addNode(x);
	}
	char C='y';
do{
	cout<<"1. PreOrder \n2. InOrder \n3. PostOrder \n4. Print Internal and Leaf Nodes \n5. Mirror Image \n6. Delete Tree \n7. Check trees \n8. Copy tree"<<endl;
	int ch;
	cin>>ch;
	switch(ch)
	{
	case 1:
			cout<<"PreOrder Traversal (Non Recursive) is"<<endl;
			b.preOrder(b.root);
			cout<<"\nPreOrder Traversal (Recursive) is"<<endl;
			b.preOrderR(b.root);
			break;

	case 2:
			cout<<"\nInOrder Traversal (Non Recursive) is"<<endl;
			b.inOrder(b.root);
			cout<<"\nInOrder Traversal (Recursive) is"<<endl;
			b.inOrderR(b.root);
			break;

	case 3:
			cout<<"\nPostOrder Traversal (Recursive) is"<<endl;
			b.postOrderR(b.root);
			//	cout<<"\nPostOrder Traversal (Non Recursive) is"<<endl;
			//			b.postOrder(b.root);
			break;

	case 4:
			cout<<"Internal Nodes are-"<<endl;
			b.printInternal(b.root);

			cout<<"\nLeaf Nodes are-"<<endl;
			b.printLeaf(b.root);
			break;

	case 5:
			cout<<"\nMirror Image -"<<endl;
			b.mirrorImage(b.root);
			cout<<"Tree Mirrored Successfully"<<endl;
			break;

	case 6:
			cout<<"\nDeleting Tree...."<<endl;
			b.deleteTree(b.root);

			cout<<"Tree Deleted Successfully"<<endl;
			break;

	case 7:
			cout<<"Checking the trees"<<endl;
			cout<<check(b.root,b.root->left);
			break;

	case 8:
			cout<<"Copy b1 to b2"<<endl;
			b2.root = b.root;
			cout<<"Tree copied successfully"<<endl;
			b2.inOrderR(b2.root);
			break;

	default: cout<<"Wrong choice"<<endl;
			break;

	}
	cout<<"\nContinue(y/n)?"<<endl;
	cin>>C;
}	while(C == 'y');

	return 0;
}


