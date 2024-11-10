/*
    Youtube Video               : https://www.youtube.com/watch?v=w4W6yya1PIc 
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/maximum-subarray/description/
*/
/******************************************************** C++ ********************************************************/
//Approach - Kadane's Algo
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {


        int n=nums.size();
        int sum=0;
        int maxi=nums[0];
      
        for(int i=0;i<n;i++){
           
           sum+=nums[i]; 

           maxi=max(maxi,sum);

           if(sum<0)sum=0;
        }

        return maxi;
        
    }
};
