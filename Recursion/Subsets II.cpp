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
    vector<vector<int>>ans;
    void solve(int index,vector<int>&sub,vector<int>&nums){
       
        ans.push_back(sub);

        for(int i=index;i<nums.size();i++){

              if(index!=i && nums[i-1]==nums[i])continue;
              sub.push_back(nums[i]);
              solve(i+1,sub,nums);
              sub.pop_back();
        }
        
    }
     
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int>sub;
        sort(nums.begin(),nums.end());
        solve(0,sub,nums);

        return ans;
    }
};
