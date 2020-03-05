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

	Node()
	{
		key=type="";

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
			else
			{
				// if wrong position occupied by existing element
				// now store the existing element in a temporary variable
				string temp1= table[pos].key;
				string temp2= table[pos].type;
				//int temp3 = table[pos].chain;
				int tp;
				// now, find the chain value of the parent of this element
				// travese the list to find the position of the parent
				for(int i=0;i<26;i++)
				{
					if(table[i].chain == pos)
					{
						tp=i;
						break;
					}
				}
				table[pos].key = k;
				table[pos].type= t;
				int tp2=table[pos].chain;
				table[pos].chain=-1;
				int p=pos;
				while(table[p].key != "")
				{
					p++;
				}
				table[p].key=temp1;
				table[p].type=temp2;
				table[tp].chain=p;
				table[p].chain=tp2;

			}

			// now place the new element at its position
		}
	}

	void deleteKey()
	{
		string k;
		cout<<"Enter the key to be deleted"<<endl;
		//cin>>k;
		// this code is same as search
		int pos = searchKey();
		if(pos == -1)
			cout<<"Not found"<<endl;
		else
		{
			// first find the chain of the parent
			int tp;
			for(int i=0;i<26;i++)
			{
				if(table[i].chain == pos)
				{
					tp=i;
					break;
				}
			}
			int tc=table[pos].chain;		// chain of child

			table[pos].key="";
			table[pos].chain=-1;
			table[tp].chain=tc;
			//table[tc].chain=pos;
		}
	}

	int searchKey()
	{
		int COUNT=0;
		string k;
		cout<<"Enter the key to be searched"<<endl;
		cin>>k;
		int flag=0;
		int val=calculateKeyValue(k);
		if(table[val].key == k)
			cout<<"Key found at position "<<val<<endl;
		// case for  - if the position is empty
		else if(table[val].key == "")
			cout<<"Key not found "<<endl;
		else
		{
			// if the key is not found
			// check if chain is not -1
			int tf=0;  	// take a temporary flag for this special case
			while(flag == 0 || COUNT<25)
			{
				if(table[val].key != "")
				{
					if(table[val].key[0] != k[0])
					{
						val++;
						tf=1;
					}
				}
				else if(table[val].key == "")
					break;

					else if(table[val].chain == -1)
					{
						flag=0;
						val=-1;
						break;
					}
				 if(tf != 1)
					 val=table[val].chain;
				if(table[val].key == k)
				{
					flag=1;
					break;
				}
				COUNT++;
			}
			if(flag == 0)
				cout<<"Key not found"<<endl;
			else
				cout<<"Key found at position "<<val<<endl;
		}
		return val;
	}

	void printKey()
	{
		cout<<"Index \tKey \t \tChain"<<endl;
		for(int i=0;i<26;i++)
			cout<<i<<" \t "<<table[i].key<<" \t \t "<<table[i].chain<<endl;
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
	cout<<"1.Insert Key(without) \n2.Print Keys \n3.Insert With \n4.Search Key \n5.Delete Key \n9.EXIT"<<endl;
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

	case 4:
			T.searchKey();
			break;

	case 5:
			T.deleteKey();
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
