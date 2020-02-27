//============================================================================
// Name        : assign6.cpp
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
	string key,value;
	int p;
	Node()
	{
		p=-1;
		key="";
		value="";
	}
};

class Hash{
public:
	Node arr[97];

	void acceptEntry()
	{
		string k,v;
		cout<<"Enter the key"<<endl;
		cin>>k;
		cout<<"Enter the value"<<endl;
		cin>>v;

		int sum=0;
		int i=0;
		while(k[i] != '\0')
		{
			sum+=(int)k[i];
			i++;
		}
		int pos=sum%97;
		while(arr[pos].key != "")
			pos++;

		arr[pos].p=pos;
		arr[pos].key =k;
		arr[pos].value=v;
		cout<<"Key Inserted Successfully"<<endl;
		//cout<<sum<<"\t"<<i<<endl;

	}

	void insertWith()
		{
			string k,v;
			string temp="";
			string val="";
			cout<<"Enter the key"<<endl;
			cin>>k;
			cout<<"Enter the value"<<endl;
			cin>>v;
			int flag=0;
			int sum=0;

			int i=0;
			while(k[i] != '\0')
			{
				sum+=(int)k[i];
				i++;
			}
			int pos=sum%97;
			if(arr[pos].key == "")
			{
				arr[pos].p=pos;
				arr[pos].key=k;
				arr[pos].value=v;
				flag=1;

			}
			else
			{
				// key already exists at that position
				temp=arr[pos].key;
				val=arr[pos].value;
				arr[pos].key=k;
				arr[pos].value=v;
			}
			if(flag == 0)
			{
				while(arr[pos].key != "")
				pos++;

			arr[pos].p=pos;
			arr[pos].key =temp;
			arr[pos].value=val;
			}
			cout<<"Key Inserted Successfully"<<endl;
			//cout<<sum<<"\t"<<i<<endl;

		}
	/*
	void insertWith2()
			{
				string k,v;
				string temp="";
				string val="";
				cout<<"Enter the key"<<endl;
				cin>>k;
				cout<<"Enter the value"<<endl;
				cin>>v;
				int flag=0;
				int sum=0;

				int i=0;
				while(k[i] != '\0')
				{
					sum+=(int)k[i];
					i++;
				}
				int pos=sum%97;
				if(arr[pos].key == "")
				{
					arr[pos].p=pos;
					arr[pos].key=k;
					arr[pos].value=v;
					flag=1;
				}
				else
				{
					// key already exists at that position

					if(calculateKey(temp) == arr[pos].p)
						// at its correct position
					{
						flag=0;
					}
					else
					{
						temp=arr[pos].key;
						val=arr[pos].value;
						arr[pos].key=k;
						arr[pos].value=v;
					}

				}
				if(flag == 0)
				{
					while(arr[pos].key != "")
					pos++;

				arr[pos].p=pos;
				arr[pos].key =temp;
				arr[pos].value=val;
				}
				cout<<"Key Inserted Successfully"<<endl;
				//cout<<sum<<"\t"<<i<<endl;

			}

*/

	int calculateKey(string k)
	{
		int i=0;
		int sum=0;
		while(k[i] != '\0')
		{
			sum+=(int)k[i];
			i++;
		}
		int pos=sum%97;
		return pos;
	}
	void deleteEntry()
	{
		string k;
		cout<<"Enter the key to be deleted"<<endl;
		cin>>k;

		int sum=0;
		int i=0;
		while(k[i]!= '\0')
		{
			sum+=(int)k[i];
			i++;
		}
		sum=sum%97;
		int flag=0;
		i=sum;
		while(flag == 0 && i<97)
		{
			if(arr[i].p == i)
				{
				cout<<"Found at position "<<arr[i].p<<endl;
				arr[i].p=-1;
				arr[i].key="";
				arr[i].value="";
				flag=1;
				cout<<"Key deleted successfully"<<endl;
				break;
				}
			i++;
		}
		if(flag == 0)
			cout<<"Element not found"<<endl;


}

	void findEntry()
	{
		string k;
		cout<<"Enter the key to be searched"<<endl;
		cin>>k;

		int sum=0;
		int i=0;
		while(k[i]!= '\0')
		{
			sum+=(int)k[i];
			i++;
		}
		sum=sum%97;
		int flag=0;
		i=sum;
		while(flag == 0 && i<97)
		{
			if(arr[i].p == i)
				{
				cout<<"Found at position "<<arr[i].p<<endl;
				flag=1;
				break;
				}
			i++;
		}
		if(flag == 0)
			cout<<"Element not found"<<endl;
		//cout<<sum<<endl;

	}

	void printEntries()
	{
		int i=0;
		for(i=0;i<97;i++)
		{
			if(arr[i].p != (-1))
				cout<<arr[i].p<<"\t"<<arr[i].key<<"\t"<<arr[i].value<<endl;
		}

	}
};

int main()
{
	Hash H;
	int ch;
	do
	{
	cout<<"1.Insert \n2.Find \n3.Delete \n4.Print Entries \n5.Exit"<<endl;
	cin>>ch;
	switch(ch)
	{
	case 1:
			H.insertWith();
			break;

	case 2:
			H.findEntry();
			break;

	case 3:
			H.deleteEntry();
			break;

	case 4:
			cout<<"Index \tKey \tValue"<<endl;
			H.printEntries();
			break;

	case 5:	cout<<"Exit Successful !!"<<endl;
			break;

	default:
			cout<<"Wrong Choice !!"<<endl;
			break;
	}
	}while(ch != 5);

}
