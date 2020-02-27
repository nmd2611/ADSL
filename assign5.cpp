//============================================================================
// Name        : assign5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class UGraph
{
public:
	int mat[10][10];
	int cnt;
	int cost;
	string office[10];

	UGraph()
	{
		cnt=0;
		cost=0;
		for(int i=0;i<=9;i++)
			for(int j=0;j<=9;j++)
				mat[i][j]=0;
	}

	void mapOffice()
	{
		//int x;
		cout<<"Enter the no. of offices"<<endl;
		cin>>cnt;
		cout<<"Enter the names"<<endl;
		for(int i=0;i<cnt;i++)
			cin>>office[i];
	}

	void acceptOffice()
	{
		string S,D;
		int s,d;
		int cost;
		cout<<"Enter the source office"<<endl;
		cin>>S;
		cout<<"Enter the destination office"<<endl;
		cin>>D;
		for(int i=0;i<cnt;i++)
		{
			if(office[i] == S)
				s=i;
			if(office[i] == D)
				d=i;
		}
		if(s == d)
			cout<<"Source and dest. cannot be the same"<<endl;
		else if(s>9 || d>9)
			cout<<"Index values out of range"<<endl;
		else
		{
			cout<<"Enter the cost"<<endl;
			cin>>cost;
			mat[s][d] = cost;
			mat[d][s] = cost;

		}
	}

	void Prims()
	{
		int i,j;
		int ans=0;
		int mst[cnt];
		int keyset[cnt];
		int flag[cnt];
		cout<<"count = "<<cnt<<endl;
		for(i=0;i<cnt;i++)
		{
			keyset[i]=999;
			flag[i]=0;
		}
//		keyset[0]=0;
//		flag[0]=1;
//		mst[0]=0;
		i=0;
		keyset[0]=0;
		int pos=0;
			// key set with non-zero values prepared
		while(i<cnt)
		{

			int min=999;

			for(j=0;j<cnt;j++)
				if(keyset[j]<min && !flag[j])
				{
					min=keyset[j];
					pos=j;
				}
			flag[pos]=1;
			mst[i]=pos;
			i++;
				ans=ans+min;
			for(j=0;j<cnt;j++)
			{
				if(mat[pos][j]!=0 && !flag[j])
					if(mat[pos][j] < keyset[j])
					{
					keyset[j]=mat[pos][j];
					cout<<keyset[j]<<"\t"<<j<<endl;
					}
			}
//			cout<<pos<<endl;
//			ans=ans+mat[i][pos];
//			cout<<ans<<"yes/no"<<endl;
//			mst[++i]=pos;
//			cout<<" i= "<<i<<"\t";
//			flag[pos]=1;

		}
		for(i=0;i<=9;i++)
			{
			for(j=0;j<=9;j++)
				cout<<mat[i][j]<<"\t";
			cout<<endl;
			}
		cout<<"Cost = "<<ans<<endl;
		for(j=0;j<cnt;j++)
		{
			cout<<office[mst[j]]<<"\t";
		}

		cout<<endl;

	}
};

int main()
{
	UGraph g;
	g.mapOffice();
	int ch;
	//int count;
	//cout<<"Enter the vertices count"<<endl;
	//cin>>count;
	//g.cnt=count;
	do{
	cout<<"1. Accept Office \n2. Prims algo \n3. Exit"<<endl;
	cin>>ch;
	switch(ch)
	{
	case 1:
			g.acceptOffice();
			break;
	case 2:
			g.Prims();
			break;
	case 3:
			break;

	default:
			cout<<"Wrong choice"<<endl;
	}
	}while(ch != 3);

	return 0;
}
