/*
    Company Tags                : VMWare, Flipkart, Amazon, Microsoft, OYO Rooms, Snapdeal
    GFG Link                    : https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1
*/
/************************************************************ C++ *****************************************************/
//Approach-1 (Brute Force)
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    unordered_map<int,int>mp;
    vector<int>temp;
    void solve(Node * root){
        
         if(root==NULL)return ;
         solve(root->left);
         temp.push_back(root->data);
         solve(root->right);
    }
    bool findTarget(Node *root, int target) {
        // your code here.
        
        solve(root);
        
        for(auto u:temp){
            
             int need=target-u;
             
             if(mp.count(need))return true;
             
             mp[u]++;
        }
        return false;
    }
};

//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    unordered_map<int,int>mp;
    void solve(Node * root,int target,bool &ans){
        
         if(root==NULL)return ;
         solve(root->left,target,ans);
         int need=target-root->data;
         if(mp.count(need))ans=true;
         mp[root->data]++;
         solve(root->right,target,ans);
    }
    bool findTarget(Node *root, int target) {
        // your code here.
        bool ans=false;
        solve(root,target,ans);
        return ans;
    }
};
