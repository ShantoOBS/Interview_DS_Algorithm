// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    
    public:
    
    int val;
    Node *next;
    
    Node(int val){
        this->val=val;
        this->next=next;
    }
};

void delete_at_head(Node*& head){
    
    Node *  temp=head;
    head=head->next;
    delete(temp);
    
}


void delete_at_tail(Node*& head,Node*& tail){
    
    Node *  temp=head;
    
    while(temp->next->next){
        temp=temp->next;
    }
    
    temp->next=NULL;
    
    tail=temp;
     
    
}

void delete_at_any_place(Node*& head,Node*& tail,int p){
    
    if(p==1){
        delete_at_head(head);
    }
    
    int ct=0;
    
    Node * temp=head;
     
    while(ct<p && temp){
        ct++;
        temp=temp->next;
    }
    
    if(temp==NULL){
        delete_at_tail(head,tail);
    }
    
    Node * t=head;
    
    ct=1;
    
    while(ct!=p-1){
        ct++;
        t=t->next;
    }
    
    t->next=t->next->next;
    
}


void insert_at_head(Node *& head,int data){
    
    Node * temp=new Node(data);
    
    temp->next=head;
    
    head=temp;
}

void insert_at_tail(Node *& tail,int data){
     
     Node * temp=new Node(data);
     
     tail->next=temp;
     
     tail=temp;
    
}

void insert_at_any_position(Node *&head, Node *& tail, int p,int data){
    
    if(p==1){
        insert_at_head(head,data);
        return ;
    }
    
    int count=0;
    
    Node * temp=head;
    
    while(count<p && temp){
        count++;
        temp=temp->next;
    }
    
    if(temp==NULL){
        insert_at_tail(tail,data);
        return ;
    }
    
    Node * pre=NULL;
    Node * curr=head;
    
    count=1;
    
    while(count!=p-1){
       
        curr=curr->next;
        count++;
    }
    
    
    Node * t=new Node(data);
    
    t->next=curr->next;
    
    curr->next=t;
    
    
    
}


void print(Node *&head){
    
    Node * temp=head;
    
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    
    cout<<endl;
}

int main() {
    
    Node * temp=new Node(10);
    Node * head=temp;
    Node * tail=temp;
    
    
    insert_at_head(head,5);
    insert_at_tail(tail,20);
    
    
    insert_at_any_position(head,tail,1,2);
    
    insert_at_any_position(head,tail,4,30);
    
    insert_at_any_position(head,tail,5,100);
    
    insert_at_any_position(head,tail,3,600);
    
    delete_at_head(head);
    
    delete_at_tail(head,tail);
    
    print(head);
   delete_at_any_place(head,tail,2);
    
    
    print(head);
    
    cout<<tail->val<<" "<<head->val<<endl;
   
   
}
