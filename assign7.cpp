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
	Node *link;
	Node()
	{
		key=type="";
		link=NULL;
	}
};

class SymbolTable
{
public:
	Node table[7];
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

		}
		cout<<"Key Inserted Successfully !!"<<endl;
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
		cout<<"Index \tKey \tType"<<endl;
		for(int i=0;i<7;i++)
			cout<<i<<" \t "<<table[i].key<<" \t "<<table[i].type<<endl;
	}

	int calculateKeyValue(string k)
	{
		int pos;
		pos=(int)k[0];
		pos=pos%7;
		return pos;
	}

	void searchKey()
	{
		string k;
		cout<<"Enter the key to be searched"<<endl;
		cin>>k;
		int val=calculateKeyValue(k);

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

	case 9:
			break;

	default:
			cout<<"Wrong Choice"<<endl;
			break;
	}
	}while(ch !=9);
	return 0;
}
