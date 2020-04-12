#include <iostream>

using namespace std;
class node{

    public:
        int data;
        node* next;
        node(){
            next = NULL;
        }
        friend class SET;
};

class Iter{
    public:
      node* myNode;
      operator++() { myNode = myNode->next; }
      operator*()  { return myNode->data;   }
};

class SET{
        node *head;
    public:
        SET(){
            head = NULL;
        }
        void create(){
            int n;
            cout<<"ENTER HOW MANY ELEMENTS YOU WANT TO INSERT : ";
            cin>>n;
            for(int i=0;i<n;i++){
                int x;
                cout<<"ENTER THE ELEMENT VALUE : ";
                cin>>x;
                insertSET(x);
            }
            cout<<"Set Created successfully\n";
        }
        void insertSET(int x){
            int flag = 0;
            node* q = head;
            node* p = new node;
            p->data = x;
            if(head == NULL){
                head = p;
            }
            else{
                while(q->next!=NULL){
                    if(q->data == p->data){
                        flag = 1;
                        break;
                    }
                    q = q->next;
                }
                if(q->data == p->data || flag==1){
                    cout<<"ELEMENT ALREADY EXISTS\n";
                }
                else{
                    q->next = p;
                }
            }
        }
        void displaySET(){
            cout<<"THE SET CONTAINS THE FOLLOWING ELEMENTS :";
            node* p = head;
            while(p != NULL){
                cout<<p->data<<" ";
                p = p->next;
            }
            cout<<endl;
        }
        void removeElement(){
            int x;
            cout<<"ENTER THE ELEMENT YOU WANT TO DELETE :";
            cin>>x;
            node* p = head;
            node* q;
            while(p!=NULL){
                if(head->data == x){
                    head = head->next;
                    break;
                }
                else if(p->data == x){
                    q->next = p->next;
                    break;
                }
                q = p;
                p = p->next;
            }
            cout<<"Element deleted\n";
        }
        void contains(){
            int x;
            cout<<"ENTER THE ELEMENTS YOU WANT TO CHECK IF IT CONTAINS :";
            cin>>x;
            node *p = head;
            while(p!=NULL){
                if(p->data == x){
                    cout<<"Element is present\n";
                    return;
                }
                p = p->next;
            }
            cout<<"Element is not present\n";
            return;

        }
        int sizeSET(){
            int count = 0;
            node* p = head;
            while(p!=NULL){
                p = p->next;
                count++;
            }
            return count;
        }
        void Union(SET s1,SET s2){
            node* p = s1.head;
            node* q = s2.head;
            while(p!=NULL){
                insertSET(p->data);
                p = p->next;
            }
            while(q!=NULL){
                int flag = 0;
                node* p = s1.head;
                while(p!=NULL){
                    if(q->data == p->data){
                        flag = 1;
                    }
                    p = p->next;
                }
                if(flag == 0){
                    insertSET(q->data);
                }
                flag = 0;
                q = q->next;
            }
        }
        void Intersection(SET s1,SET s2){
            node* p = s1.head;
            while(p != NULL){
                int flag = 0;
                node* q = s2.head;
                while(q!=NULL){
                    if(q->data == p->data){
                        flag = 1;
                        break;
                    }
                    q = q->next;
                }
                if(flag == 1){
                    insertSET(p->data);
                }
                p = p->next;
            }
        }
        void Difference(SET s1,SET s2){
            node* p =s1.head;
            while(p!=NULL){
                int flag = 0;
                node* q = s2.head;
                while(q!=NULL){
                    if(q->data == p->data){
                        flag = 1;break;
                    }
                    q = q->next;
                }
                if(flag == 0){
                    insertSET(p->data);
                }
                p = p->next;
            }
        }
        node* iter(){
            return head;
        }
        void subset(SET s1){
            SET s3;
            s3.Intersection(*this,s1);
            if(s3.sizeSET() == s1.sizeSET()){
                cout<<"It is a subset"<<endl;
            }
            else{
               cout<<"It is not a subset"<<endl;
            }
        }
};

int main()
{
    char ch = 'Y';
    int choice;
    SET s1;
    while(ch == 'Y' || ch == 'y'){
    cout<<"---------------------------------\n";
    cout<<"             MENU\n";
    cout<<"---------------------------------\n";
    cout<<" 1. Create Set\n";
    cout<<" 2. Insert Into set\n";
    cout<<" 3. Display Set\n";
    cout<<" 4. Remove Element\n";
    cout<<" 5. Contains Element\n";
    cout<<" 6. Size of Set\n";
    cout<<" 7. Iterator\n";
    cout<<" 8. Union\n";
    cout<<" 9. Intersection\n";
    cout<<" 10. Difference\n";
    cout<<" 11. Subset\n";
    cout<<"---------------------------------\n";
    cout<<"Enter your choice :";
    cin>>choice;
    SET s2,s3;
    cout<<"---------------------------------\n";
    switch(choice){
        case 1 : s1.create();
                 break;
        case 2 : int x;
                 cout<<"ENTER THE ELEMENT VALUE : ";
                 cin>>x;
                 s1.insertSET(x);
                 cout<<"Element inserted successfully\n";
                 break;
        case 3 : s1.displaySET();
                 break;
        case 4 : s1.removeElement();
                 break;
        case 5 : s1.contains();
                 break;
        case 6 : cout<<"The set contains : "<<s1.sizeSET()<<endl;
                 break;
        case 7 : Iter t;
                 t.myNode = s1.iter();
                 cout<<"By Iterating through set :";
                 for(int i=0;i<s1.sizeSET();i++){
                    cout<<*t<<" ";
                    ++t;
                 }
                 cout<<endl;
                 break;
        case 8 : cout<<"Create another set\n";
                 s2.create();
                 cout<<"Content of SET 1 :-"<<endl;
                 s1.displaySET();
                 cout<<"Content of SET 2 :-"<<endl;
                 s2.displaySET();
                 s3.Union(s1,s2);
                 cout<<"Result of Union"<<endl;
                 s3.displaySET();
                 break;
        case 9 : cout<<"Create another set\n";
                 s2.create();
                 cout<<"Content of SET 1 :-"<<endl;
                 s1.displaySET();
                 cout<<"Content of SET 2 :-"<<endl;
                 s2.displaySET();
                 s3.Intersection(s1,s2);
                 cout<<"Result of Intersection"<<endl;
                 s3.displaySET();
                 break;
        case 10: cout<<"Create another set\n";
                 s2.create();
                 cout<<"Content of SET 1 :-"<<endl;
                 s1.displaySET();
                 cout<<"Content of SET 2 :-"<<endl;
                 s2.displaySET();
                 s3.Difference(s1,s2);
                 cout<<"Result of Difference S1-S2"<<endl;
                 s3.displaySET();
                 break;
        case 11: cout<<"Create another set for subset\n";
                 s2.create();
                 cout<<"Content of SET 1 :-"<<endl;
                 s1.displaySET();
                 cout<<"Content of SET 2 :-"<<endl;
                 s2.displaySET();
                 s1.subset(s2);
                 break;
    }
    cout<<"Do you want to continue ? ";
    cin>>ch;
    }
}
