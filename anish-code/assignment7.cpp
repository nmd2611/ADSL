//============================================================================
// Name        : assignment7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Symbol {
public:
	string symbol="";
	string attribute="";
	int chain=-1;
};

class Operations {
public:
	void insertNoReplacement(Symbol table[],int n) {
		string sym,attr;
		char key;
		cout<< "Enter the symbol ";
		cin>>sym;
		cout<< "Enter the attribute ";
		cin>>attr;
		cout<< "Enter key ";
		cin>> key;
		int i= ((int)key) - 97;
		if(table[i].symbol!="") {
			while(table[i].chain!=-1) {
				i=table[i].chain;
			}
			int q=i;
			while(table[i].symbol!="") {
				i++;
				q++;
				q=q%n;
				i=i%n;
			}
			table[i].symbol=sym;
			table[i].attribute= attr;
			if(table[q].symbol[0]==table[i].symbol[0]) {
				table[q].chain=i;
			}
			else {
				table[q].chain=-1;
			}

		}
		else {
			table[i].symbol=sym;
			table[i].attribute= attr;
		}
	}
	void search(Symbol table[],int n) {
		string sym;
		cout<< "Enter the Symbol ";
		cin>>sym;
		int key = ((int)sym[0])-97;
		while(true) {
			if(table[key].symbol==sym) {
				cout<< "Symbol found at position "<<key<<endl;
				break;
			}
			else {
				while(table[key].chain!=-1) {
					if(table[key].symbol==sym) {
						cout<< "Symbol found at position "<<key<<endl;
						break;
					}
					key= table[key].chain;
				}
				cout<< "Symbol not found"<<endl;
				break;
			}
		}
	}
	void displayTable(Symbol table[],int n) {
		for(int i=0;i<n;i++) {
			cout<< table[i].symbol << " : "<< table[i].attribute<<" : "<<table[i].chain<<endl;
		}
	}
	void insertReplace(Symbol table[],int n) {
		string sym,attr;
			char key;
			cout<< "Enter the symbol ";
			cin>>sym;
			cout<< "Enter the attribute ";
			cin>>attr;
			cout<< "Enter key ";
			cin>> key;
			int i= ((int)key) - 97;
			if(table[i].symbol!="") {
			while(table[i].chain!=-1 || table[i].symbol!=sym) {
				i=table[i].chain;
			}
			int q=i;
			while(table[i].symbol!="") {
				i++;
				i=i%n;
			}
			table[i].symbol=table[q].symbol;
			table[i].attribute= table[q].attribute;
			table[q].chain=i;
			table[q].symbol=sym;
			table[q].attribute=attr;
		}
		else {
			table[i].symbol=sym;
			table[i].attribute= attr;
		}
	}
};

int main() {
	int maxSize;
	cout<< "Enter the number of symbols ";
	cin>> maxSize;
	Operations obj;
	Symbol table[maxSize];
	cout<< "Enter\n1) Insert Symbol\n2) Display Table\n3) Search a symbol\n4) Insert with Replacement\n5) Exit"<<endl;
	int choice;
	do {
		cout<< "Enter choice ";
		cin>>choice;
		switch(choice) {
		case 1:
			obj.insertNoReplacement(table,maxSize);
			break;
		case 2:
			obj.displayTable(table,maxSize);
			break;
		case 3:
			obj.search(table,maxSize);
			break;
		case 4:
			obj.insertReplace(table,maxSize);
			break;
		}
	} while(choice!=5);
	return 0;
}
