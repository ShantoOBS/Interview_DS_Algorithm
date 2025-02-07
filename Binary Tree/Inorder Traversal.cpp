
/*
    Company Tags                : Amazon, Snapdeal, Adobe
    Leetcode Link               : https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

/********************************************** C++ **********************************************/

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
    vector<int> ans;

    void in_order(TreeNode * root){

        if(root== NULL)return ;

        in_order(root->left);
        ans.push_back(root->val);
        in_order(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {

        in_order(root);

        return ans;
        
    }
};

/**********************************************JAVA **********************************************/
//T.C : O(n)
//S.C : O(n)
class Solution {
    ArrayList<Integer>ans=new ArrayList<>();
    
    void solve(Node root) {
        
        if(root==null)return ;
        
        solve(root.left);
        ans.add(root.data);
        solve(root.right);
    }
     
    ArrayList<Integer> inOrder(Node root) {
        // Code
       
        
        solve(root);
        
        return ans;
    }
}
