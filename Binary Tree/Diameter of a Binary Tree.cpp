/*
    Company Tags                : Amazon, Microsoft
    GFG Link                    : https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
*/
/*********************************************************** C++ **************************************************/
T.C : O(N)
S.C : O(N)
class Solution {
  public:
    int ans=0;
    
    int maxi(Node *root){
         
          if(root==NULL) return 0;
          
          int left=maxi(root->left);
          int right=maxi(root->right);
          
          ans=max(ans,left+right);
          
          return 1+max(left,right);
    }
    
  
    int diameter(Node* root) {
        

       maxi(root);
       
       return  ans;
        // Your code here
    }
};
