// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    
    public :
     int data;
     Node *left;
     Node *right;
     
     Node(int data){
         this->data=data;
         this->left=NULL;
         this->right=NULL;
     }
};

Node* buildTree(Node * root){
    
    cout<<"Enter your data : "<<endl;
    int data;
    cin>> data;
    
    root=new Node(data);
    
    if(data==-1) return NULL;
    
    cout<<"Enter data for inserting left "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting right "<<data<<endl;
    root->right=buildTree(root->right);
    
    return root;
}

void LevelOrder(Node * root){
    
    queue<Node *>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        
        Node * temp=q.front(); q.pop();
        
        
        if(temp==NULL){
            
            cout<<endl;
            
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            
          cout<<temp->data<<" ";
            
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
            
        }
      
    }
}

int main() {
    
    Node * root=NULL;
    
    root=buildTree(root);
    
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
    LevelOrder(root);
    
    
}
