/*
    Company Tags                :
    Leetcode Link               : https://leetcode.com/problems/binary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-25
*/

/********************************************** C++ **********************************************/
//Recarsive Approach 
//T.C : O(n)
//S.C : O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 

     vector<int>ans;
     void post_order(TreeNode *root){

        if( root==NULL) return;

        post_order(root->left);
        post_order(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {

        post_order(root);

        return ans;
        
    }
};
// Iterative Approach using two stack data structure
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        // Your code here
        stack<Node *>st1,st2;
        
        st1.push(root);
        
        while(!st1.empty()){
            Node * temp=st1.top();
            st1.pop();
            st2.push(temp);
            
            if(temp->left!=NULL)st1.push(temp->left);
            if(temp->right!=NULL)st1.push(temp->right);
            
        }
        
        vector<int>postorder;
        
        while(!st2.empty()){
            
              postorder.push_back(st2.top()->data);
              st2.pop();
        }
        
        return postorder;
    }
};


