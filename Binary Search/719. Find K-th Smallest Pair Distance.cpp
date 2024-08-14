/*
    Company Tags                : Will soon update
    Leetcode Link               : https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
*/


/*************************************************************** C++ *************************************************/
//Approach (Binary Seraching)
//T.C : O(nlong(n))
//S.C : O(1)

  class Solution {
public:
    
    bool check(vector<int>nums,int mid,int k){

       int count=0, left=0;
        for(int right=1;right<nums.size();right++)
        {
            while(nums[right]-nums[left]>mid) left++;
            count+=right-left;
        }
        return (count>=k);

    }
    int smallestDistancePair(vector<int>& nums, int k) {
        
         sort(nums.begin(),nums.end());
         int l=0;

         int r=nums[nums.size()-1]-nums[0];

         while(l<r){

            int mid=(l+r)/2;

            if(check(nums,mid,k)){
               r=mid;
            }
            else{
              l=mid+1;
            }
         }

         return l;
        
    }
};
