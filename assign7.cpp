//============================================================================
// Name        : assign7.cpp
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
	string type;
	//string size;
	int chain;
	Node *link;
	Node()
	{
		key=type="";
		link=NULL;
		chain=-1;

	}
};

/*
 		else
		{
			// first, check if the existing is atits correct position
			// if no, remove the existing element and push it
			// to the next empty position
			int ke = calculateKeyValue(table[pos].key) ; // calculate key of existing element
			if(ke == pos)
				// i.e. correct position of the existing element
			{
				// push the new element down
				int p=pos;
				while(table[p].key != "")
				{
					if(table[p].chain != -1)
						{
						p=table[p].chain;
						pos=p;
						}
					else
						p++;
						// goto that chain
				}
				table[p].key=k;
				table[p].type=t;
				table[pos].chain=p;
			}
			else
			{
				// place the new element at that position
				// and push the existing element down

				string temp1=table[pos].key;
				string temp2=table[pos].type;

				table[pos].key=k;
				table[pos].type=t;
				// new element has been placed

				// now push the existing element down
				int p=pos;
				while(table[p].key != "")
				{
					if(table[p].chain != -1)
						{
						p=table[p].chain;
						pos=p;
						}
					else
						p++;
						// goto that chain
				}
				table[p].key=temp1;
				table[p].type=temp2;

			}
 */

class SymbolTable
{
public:
	Node table[26];
	// this is without replacement
	// int this , the new element to be added is pushed down irrespective of
	// whether the element at its position is correct or not
	// eg.
	// the new element will always be pushed down if its position is occupied
	void insertKey()
	{
		string k;
		string t;
		cout<<"Enter the Key"<<endl;
		cin>>k;
		cout<<"Enter the type"<<endl;
		cin>>t;

		int pos= calculateKeyValue(k);
		if(table[pos].key == "")
		{
			table[pos].key=k;
			table[pos].type=t;
			table[pos].link=NULL;
		}
		else
		{
			int p=pos;
			while(table[p].key != "")
			{
				if(table[p].chain != -1 && table[p].key[0] == k[0])
					{
					p=table[p].chain;
					pos=p;
					}
				else
					p++;
					// goto that chain
			}
			table[p].key=k;
			table[p].type=t;
			if(table[pos].key[0] == k[0])
				table[pos].chain=p;
		}
		cout<<"Key Inserted Successfully !!"<<endl;
	}

	void insertWith()
	{
		string k;
		string t;
		cout<<"Enter the Key"<<endl;
		cin>>k;
		cout<<"Enter the type"<<endl;
		cin>>t;

		int pos= calculateKeyValue(k);
		// case 1: position is vacant
		// 			so elemnt is directly placed
		if(table[pos].key == "")
		{
			table[pos].key=k;
			table[pos].type=t;
			table[pos].link=NULL;
		}
		else
		{
			// case 2: both (existing and new elemnt) have their correct position
			// then push the new element down
			if(table[pos].key[0] == k[0])
			{
				// same code as without replacement
				int p=pos;
				while(table[p].key != "")
				{
					if(table[p].chain != -1 && table[p].key[0] == k[0])
						{
						p=table[p].chain;
						pos=p;
						}
					else
						{
						p++;
						}
						// goto that chain
				}
				table[p].key=k;
				table[p].type=t;
				if(table[pos].key[0] == k[0])
					table[pos].chain=p;
			}
			// if wrong position occupied by
			// now store the existing element in a temporary variable
			string temp1= table[pos].key;
			string temp2= table[pos].type;
			int temp3 = table[pos].chain;

			// now place the new element at its position
		}
	}
	void deleteKey()
	{

	}

	void searchKey()
	{
		string k;
		cout<<"Enter the key to be searched"<<endl;
		cin>>k;
		int val=calculateKeyValue(k);

	}

	void printKey()
	{
		cout<<"Index \tKey \tChain"<<endl;
		for(int i=0;i<26;i++)
			cout<<i<<" \t "<<table[i].key<<" \t "<<table[i].chain<<endl;
	}

	int calculateKeyValue(string k)
	{
		int pos;
		pos=(int)k[0];
		pos=pos%97;
		return pos;
	}

};



int main()
{
	SymbolTable T;
	int ch;
	do{
	cout<<"1.Insert Key \n2.Print Keys \n9.EXIT"<<endl;
	cin>>ch;
	switch(ch)
	{
	case 1:
			T.insertKey();
			break;

	case 2:
			T.printKey();
			break;

	case 3:
			T.insertWith();
			break;
	case 9:
			break;

	default:
			cout<<"Wrong Choice"<<endl;
			break;
	}
	}while(ch !=9);
	return 0;
}
