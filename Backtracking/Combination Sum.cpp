/*
    Company Tags                : Adobe, Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/combination-sum-ii/
*/


/******************************************************** C++ ********************************************************/
//Khaandani Template Backtracking
//T.C : O(2^n * n)
//S.C : O(n)
class Solution {
public:
    vector<vector<int>>ans;
    void solve(int index,int terget,vector<int>& candidates,vector<int>&sub){

          if(index>=candidates.size()){
              
               if(terget==0)ans.push_back(sub);
               return ;
          }

          if(candidates[index]<=terget){
              sub.push_back(candidates[index]);
              solve(index,terget-candidates[index],candidates,sub);
              sub.pop_back();
          }

          solve(index+1,terget,candidates,sub);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<int>sub;
         solve(0,target,candidates,sub);

         return ans;
    }
};
