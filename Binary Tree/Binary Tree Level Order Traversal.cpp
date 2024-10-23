/*
    Company Tags                : will be soon
    Leetcode Link               : https://leetcode.com/problems/binary-tree-level-order-traversal/description/
*/

/********************************************** C++ **********************************************/
//Approach (Level order traversal)
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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>>ans;

        if(root==NULL)return ans;

        

        queue<TreeNode*>q;

        q.push(NULL);

        q.push(root);

        vector<int>v;

        while(!q.empty()){

            TreeNode * temp=q.front(); q.pop();

            if(temp==NULL){

                if(!v.empty()) ans.push_back(v);

                v.clear();

                if(!q.empty()){
                    q.push(NULL);
                }
            }

            else{

                v.push_back(temp->val);

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }

            
        }

        return ans;
        
    }
};


