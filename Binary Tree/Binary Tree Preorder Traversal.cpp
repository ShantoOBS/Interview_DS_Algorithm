/*
    Company Tags                : will soon
    Leetcode Link               : https://leetcode.com/problems/binary-tree-preorder-traversal/description/
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
    void preorder(TreeNode * root){
        
        if(root==NULL)return ;

        ans.push_back(root->val);

        preorder(root->left);
        preorder(root->right);

    }
    vector<int> preorderTraversal(TreeNode* root) {

        preorder(root);

        return ans;
        
    }
};

//Iterative Approach 
//T.C : O(n)
//S.C : O(n)

class Solution {
  public:

    // Function to return a list containing the preorder traversal of the tree.
    vector<int> preorder(Node* root) {
        // write code here
        stack<Node*>st;
        vector<int>ans;
        st.push(root);
        
        while(!st.empty()){
            
            Node * temp=st.top();
            st.pop();
            ans.push_back(temp->data);
            
            if(temp->right!=NULL)st.push(temp->right);
            if(temp->left!=NULL)st.push(temp->left);
            
        }
        
        return ans;
    }
};


