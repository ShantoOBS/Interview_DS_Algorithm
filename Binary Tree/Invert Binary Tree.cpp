/*
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/invert-binary-tree/description/
*/
/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recarsion Swaping)
//T.C : O(n)
//S.C : O(1) 


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
    void swap(TreeNode * root){

        if(root==NULL) return;

        swap(root->left);
        swap(root->right);

        TreeNode * temp=root->left;
        root->left=root->right;
        root->right=temp;

    }
    TreeNode* invertTree(TreeNode* root) {

        if(root==NULL)return NULL;

        swap(root);

        return root;
    }
};
