/*        Scroll below to see JAVA code also        */
/*
    Company Tags                : VMWare, Flipkart, Accolite, Amazon, Microsoft
    GFG Link                    : https://www.geeksforgeeks.org/problems/check-for-bst/1
*/
/***************************************************************** C++ *****************************************************************/
T.C : O(n)
S.C : O(1)
class Solution {
  public:
    bool solve(Node * root,int mini,int maxi){
        
        if(root==NULL)return true;
        
        if(root->data <= mini || root->data >= maxi)return false;
       
        return solve(root->left,mini,root->data) &&
        solve(root->right,root->data,maxi);
    }
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        return solve(root,INT_MIN,INT_MAX);
    }
};

/***************************************************************** JAVA *****************************************************************/
T.C : O(n)
S.C : O(1)
class Solution {    
     public boolean solve(Node root,long mini,long maxi){
        
        if(root==null)return true;
        
        if(root.data <= mini || root.data >= maxi)return false;
       
        return solve(root.left,mini,root.data) &&
        solve(root.right,root.data,maxi);
    }
    boolean isBST(Node root) {
        // code here.
        return solve(root,Long.MIN_VALUE,Long.MAX_VALUE);
    }
}
