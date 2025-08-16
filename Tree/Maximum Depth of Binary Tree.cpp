/*
    Company Tags                     : Amazon, Microsoft, Intuit, Apple
    LeetCode Link                    : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=problem-list-v2&envId=depth-first-search
*/
/************************************************ C++ ************************************************/
//T.C : O(N)
//S.C : O(N)

class Solution {
public:
    int dfs(TreeNode * root){    
         if(root==NULL)return 0;
         int left=dfs(root->left)+1;
         int right=dfs(root->right)+1;
         return max(left,right);
    }
    int maxDepth(TreeNode* root) {
       return dfs(root);
    }
};


/************************************************ JAVA ************************************************/
//T.C : O(N)
//S.C : O(N)
