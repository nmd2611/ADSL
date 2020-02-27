//============================================================================
// Name        : assign4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<queue>
using namespace std;

class node
{
public:
	node *next;
	char info;
	node()
	{
		next=NULL;
		info='\0';
	}
};

class Queue
{
public:
	node *front,*rear;
	Queue()
	{
		front=NULL;
		rear=NULL;
	}
	node *p,*q;
	void push(char x)
	{
		p=new node;
		p->info=x;
		p->next=NULL;
		if(front == NULL)
		{
			front=p;
			rear=p;
		}
		else
		{
			rear->next=p;
			rear=p;
		}
	}

	int empty()
	{
		if(front)
			return 0;
		return 1;
	}

	void pop()
	{
		if(!empty())
		{
			node *temp= front;
			front = front->next;
			delete temp;
		}
	}

	char Front()
	{
		if(!empty())
			return front->info;
		return '\0';
	}
	char Rear()
	{
		if(!empty())
			return rear->info;
		return '\0';
	}
};
// my queue created

class Node
{
public:
	char info;
	Node * next,* down;
	int visit;
	Node()
	{
		info='\0';
		next=NULL;
		down=NULL;
		visit=0;
	}
};

class Graph
{
public:
	Node *head ;
	Node *p,*q, *r;
	char N[100];	// this stores the mapped array
	char visited[100];	// this is the visited array
	int cnt;		//this stores the count of elements
	// r is used for down traversal i.e. it keeps track of head of each level
	// p and q are used for traversal in each level

	Graph()
	{
		head=NULL;
		p=NULL;
		q=NULL;
		r=NULL;
		cnt=0;
	}

	void addNode()
	{
		char city,dest;
		char ch;
		cout<<"Enter the city"<<endl;
		cin>>city;
		N[cnt++]=city;

		//q=new Node;
		q=searchHead(city);
		if(q == NULL || head == NULL)
		{
		q=new Node;
		q->info = city;
		q->next =NULL;
		q->down=NULL;

		if(head == NULL)
		{
			head=q;
			r=q;
		}
		else
		{
			r->down =q;
			r=q;
		}
		do{
			cout<<"Enter the interconnecting city"<<endl;

			cin>>dest;
			p=new Node;
			p->info = dest;
			p->down = NULL;
			q->next= p;
			q=p;
			//p=p->next;
			cout<<"More interconnecting cities? (y/n)"<<endl;
			cin>>ch;
			} while(ch == 'y');
	}
		else
		cout<<"City Already Exists"<<endl;
	}

	void printNode()
	{
		Node *R= head;
		q=head;
		if(R)
			do
			{
				cout<<q->info<<" - ";
				if(q)
					while(q->next!=NULL)
					{
						q=q->next;
						cout<<q->info<<" - ";
					}
				R=R->down;
				q=R;
				cout<<endl;
				cout<<"|"<<endl;

			}while(R!= NULL);
	}

	Node* searchHead(char city)
	{
		Node *R = head;
		if(R)
		{
			do{
			if(R->info == city)
				return R;
			else
				R=R->down;
			}while(R!=NULL);
		}
		return NULL;


	}

	Node* searchLink(Node *R, char link)
	{
		q= R;
		if(R)
		{
			while(q->next!=NULL)
			{
			if(q->next->info == link)	// if found, return NULL
				return NULL;
			else
				q=q->next;
			}
		}
			return q;
	}

	void addLink(char city)
	{
		Node *R;
		R= searchHead(city);
		if(R ==NULL)
			cout<<"City Does Not Exists !!"<<endl;
		else
		{
			char link;
			cout<<"Enter the linking city to be added"<<endl;
			cin>>link;
			Node *S;
			S= searchLink(R, link);
			if(S == NULL)
				cout<<"Link already exists"<<endl;
			else
			{
				Node *n= new Node;
				n->info= link;
				n->next=NULL;
				S->next= n;
				cout<<"Link added Successfully !!"<<endl;
			}

		}
	}

	void deleteLink(char city)
	{
		Node *R;
		R= searchHead(city);
		if(R ==NULL)
			cout<<"City Does Not Exists !!"<<endl;
		else
		{
			char link;
			cout<<"Enter the linking city to be deleted"<<endl;
			cin>>link;
			Node *S;
			S= searchLink(R, link);
			if(S == NULL)
			{
				//i.e. link found, delete this link
				p=R;
				q=R->next;

					while(q->info !=link)
					{
						p=q;
						q=q->next;
					}
					Node *temp= q;
					p->next= q->next;
					q->next=NULL;
					delete temp;
					cout<<"Link deleted successfully"<<endl;
			}
			else
				cout<<"Linking city does not exists"<<endl;
		}
	}

	int outDegree(char city)
	{
		int ans=0;
		Node *R= searchHead(city);
		if(R == NULL)
		{
			cout<<"Node not found"<<endl;
			return -1;
		}
		else
		{
			while(R!=NULL)
			{
				ans++;
				R=R->next;
			}
		}
		return ans-1;
	}

	void mapNodes()
	{
		Node *R= head;
		cnt=0;
		while(R!= NULL)
		{
			N[cnt]= R->info;
			R=R->down;
			cnt++;
		}
		int i;
		for(i=0;i<cnt;i++)
		{
			cout<<N[i]<<"\t";
			visited[i]=0;
		}
		cout<<endl;

	}

	int visitN(Queue final,char city)
	{
		if(final.empty())
			return 0;
		else
		while(!final.empty())
		{
			if(final.Front() == city)
				return 1;
			else
				final.pop();
		}
		return 0;
	}

	int searchMap(char x)
	{
		for(int i=0;i<cnt;i++)
		{
			if(N[i] == x)
				return i;
		}
		return -1;
	}

	void changeVisit(Node *q)
	{
		Node *temp=head;
		Node *R;
		while(temp)
		{
			if(temp->info == q->info)
			{
				temp->visit=1;
			}
			else
			{
			R=searchLink(temp,q->info);
			if(R)
			if(R->info == q->info)
				R->visit=1;
			}
			temp=temp->down;
		}
	}

	void BFS()
	{
		Queue final,B;
		cnt+=2;
		for(int k=0;k<=cnt;k++)
		{
			visited[k]=0;
		}

		Node *R;
		R=head;
		p=R;
		q=R;
		B.push(R->info);
		R->visit=1;
	//	visited[searchMap(R->info)]=1;
		q=q->next;
		while(!B.empty())
		{
			char temp= B.Front();
			B.pop();
			final.push(temp);
			while(q!=NULL)
			{
				if(!q->visit)
				{
					q->visit=1;
					changeVisit(q);
					B.push(q->info);
				}
				q=q->next;
			}
			if(R)
			{q=R->down;
			R=R->down;}
		}
		while(!final.empty())
		{
			cout<<final.Front()<<"\t";
			final.pop();
		}

//		do {
//		if(R || !B.empty())
//		{
//			while(R!=NULL)
//			{
//				if(!visitN(final,r->info))
//					B.push(R->info);
//				R=R->next;
//			}
//			char temp = B.Front();
//			B.pop();
//			// if element is not visited
//			// push it into the final queue
//			// else continue with the next char
//			// in the queue
//
//			if(!visitN(final,temp))
//			{
//				final.push(temp);
//				// change the visit flag after push into final list
//			}
//
//			temp=B.Front();
//			B.pop();
//			R = searchHead(temp);
//
//			if(R == NULL)
//				continue;
//			R= R->next;
//		}
//	} while(!B.empty());
//
//		while(!final.empty())
//		{
//			cout<<final.Front()<<"\t";
//			final.pop();
//		}

	}
	void DFS()
	{

	}
};


int main()
{
	Graph g1;
	int ch;
	char city;
	int ans;
	char C;
	do {
	cout<<"1. Add Node\n2. Print Nodes \n3. Add Links to existing nodes\n4. Delete links\n5. Out Degree \n6. BFS \n7. DFS \n8. Map Nodes \n9. exit"<<endl;
	cin>>ch;
	switch(ch)
	{
	case 1:
			g1.addNode();
			break;

	case 2:
			g1.printNode();
			break;

	case 3:
			cout<<"Enter City for which link needs to be added"<<endl;
			cin>>city;
			g1.addLink(city);
			break;

	case 4:
			cout<<"Enter City for which link needs to be deleted"<<endl;
			cin>>city;
			g1.deleteLink(city);
			break;

	case 5:
			cout<<"Enter the Node for which out is to be calculated"<<endl;
			cin>>city;
			ans=g1.outDegree(city);
			if(ans >=0)
				cout<<"Out Degree : "<<ans<<endl;
			break;

	case 6:
			// bfs
			g1.BFS();
			break;

	case 7:
			// dfs
			break;

	case 8:
			g1.mapNodes();
			break;

	case 9:
			break;

	default:
			cout<<"Wrong Choice !"<<endl;
			break;
	}
	cout<<"Continue? (y/n)"<<endl;
	cin>>C;
	}while(C == 'y');
	return 0;
}
