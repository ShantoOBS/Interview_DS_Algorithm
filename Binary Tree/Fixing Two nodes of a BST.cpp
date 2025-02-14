/*
    Company Tags                : Amazon, Microsoft, FactSet, Walmart, BankBazaar
    GFG Link                    : https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1
*/
/************************************************************ C++ *****************************************************/
//Approach-1 (Brute Force)
//T.C : O(n)
//S.C : O(n)

class Solution {
  public:
    vector<int>temp;
    
    int i=0;
    
    void inorder(Node * root){
        
         if(root==NULL)return ;
         
         inorder(root->left);
         temp.push_back(root->data);
         inorder(root->right);
    }
    
    
    void print(Node *root){
        if(root==NULL)return ;
        
        print(root->left);
        
        root->data=temp[i];
        i++;
        print(root->right);
    }
    void correctBST(Node* root) {
        // add code here.
       
        inorder(root);
        
        sort(temp.begin(),temp.end());
    
        print(root);
        

    }
};

//Approach-2 (Most optimal)
//T.C : O(n)
//S.C : O(1)


class Solution {
  public:
    Node * first=NULL;
    Node * pre=NULL;
    Node *mid=NULL;
    Node *last=NULL;
    
    void solve(Node *root){
        
        if(root==NULL)return ;
        
        solve(root->left);
        
        if(pre!=NULL && (root->data<pre->data) ){
            
            if(first==NULL){
                first=pre;
                mid=root;
            }
            else last=root;
        }
        
        pre=root;
        
        solve(root->right);
        
    }
    void correctBST(Node* root) {
        // add code here.
       
       solve(root);
       
       if(first && last)swap(first->data,last->data);
       else swap(first->data,mid->data);

    }
};
