// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    
    node(int data){
        this ->data=data;
        this ->next=next;
        
    }
    
};

void insertAthead(node* &head,int d){
    node* n=new node(d);
    n->next=head;
    head=n;
}

void insertAttail(node* &tail,int d){
    node* n=new node(d);
    tail->next=n;
    tail=n;
}

void insertAtanyposition(node* &head,node* &tail,int position,int d){
    
   
    if(position ==1){
        insertAthead(head,d);
        return;
    }
    node* temp=head;
    int count=1;
   
    
    while(count!=position-1){
        count++;
        temp=temp->next;
    }
    
    if(temp->next==NULL){
        insertAttail(tail,d);
        return;
    }
    
    node* n=new node(d);
    n->next =temp->next;
    temp->next=n;
}

void deletenode(node* &head,node* &tail,int p){
    if(p==1){
        node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete (temp);
    }
    //middle and last position delete 
    else{
        
        node* curr=head;
        node* prev=NULL;
        int count=1;
         while (count<p){
            prev=curr;
            curr=curr->next;
            count++;
        }
        
        node* t=tail;  
        prev->next=curr->next;
        curr->next=NULL;
        delete(curr);
       
    }
}

void print(node* &head){
    node* temp=head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main() {
    node* node1=new node(10);
    node* head=node1;
    node* tail=node1;
    
    
    
    insertAttail(tail,30);
    print(head);
    
    insertAttail(tail,40);
    print(head);
    
    insertAttail(tail,50);
    print(head);
    
    insertAtanyposition(head,tail,4,45);
    print(head);
    
    insertAtanyposition(head,tail,1,5);
    print(head);
    
     insertAtanyposition(head,tail,7,5);
    print(head);
    
    deletenode(head,tail,1);
    print(head);
    
    deletenode(head,tail,6);
    print(head);
    
    cout <<head->data<<endl;
    cout <<tail->data;
    
}
