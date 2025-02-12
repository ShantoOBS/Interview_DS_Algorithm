/*
    Company Tags                : Accolite, Amazon, Google
    GFG Link                    : https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
*/
/***************************************************************** C++ *****************************************************************/
// Navie Approach
T.C : O(n)+O(n long n)
S.C : O(n)
class Solution {
  public:
    void solve(Node * root,int k,vector<int>&v){
        
         if(root==NULL)return ;
         
         v.push_back(root->data);
         
         solve(root->left,k,v);
         solve(root->right,k,v);
    }
    int kthSmallest(Node *root, int k) {
        // add code here.
        
        vector<int>v;
        
        solve(root,k,v);
        
        sort(v.begin(),v.end());
        
        if(v.size()<k)return -1;
        
        return v[k-1];
    }
};

// Optimal Approach using inorder travesal in inorder is always sroted in BST 
T.C : O(n)
S.C : O(1)

class Solution {
  public:
    int cnt=0;
    void solve(Node * root,int k,int &ans){
        
         if(root==NULL)return ;
         
         solve(root->left,k,ans);
         cnt++;
         if(cnt==k)ans=root->data;;
         solve(root->right,k,ans);
    }
    int kthSmallest(Node *root, int k) {
        // add code here.
        
        int ans=-1;
        
        solve(root,k,ans);
        
        return ans;
        
    }
};
