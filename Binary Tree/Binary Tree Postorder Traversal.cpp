/*
    Company Tags                :
    Leetcode Link               : https://leetcode.com/problems/binary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-25
*/

/********************************************** C++ **********************************************/
//Approach (Post order traversal)
//T.C : O(nlogn)

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
