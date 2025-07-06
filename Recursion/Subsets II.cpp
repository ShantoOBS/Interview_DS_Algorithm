/*
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/subsets/
*/

//NOTE : 
//-------- This is basically we are doing backtracking using Recursion. (I told you, Recursion is the father of many topics)
//-------- If you want to solve it using Bit Magic - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Subsets.cpp


/************************************************************ C++ ************************************************************/
//Approach-1
//T.C : O(2^n)
//S.C :  O(2^n*length of each subset) to store each subset
class Solution {
public:
    set<vector<int>>st;
    void solve(int index,vector<int>&sub,vector<int>&nums){

          if(index>=nums.size()){
             st.insert(sub);
             return;
          }

          solve(index+1,sub,nums);
          sub.push_back(nums[index]);
          solve(index+1,sub,nums);
          sub.pop_back();
    }
     
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>sub;
        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());

        solve(0,sub,nums);
          for(auto v:st)ans.push_back(v);

        return ans;
    }
};
