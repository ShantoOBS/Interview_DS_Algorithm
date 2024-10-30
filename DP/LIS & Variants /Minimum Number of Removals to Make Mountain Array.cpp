/*
    Company Tags  : will be soon
    Leetcode Link : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/?envType=daily-question&envId=2024-10-30
*/
************************************************************ C++ ************************************************************
//Approach-1 (Button up) 
//T.C : O(n^2)


class Solution {
public:
    
    int minimumMountainRemovals(vector<int>& nums) {
          
        int n=nums.size();

        vector<int>LIS(n,1),LDS(n,1);

        for(int i=0;i<n;i++){

            for(int j=0;j<i;j++){
                
                if(nums[j]<nums[i]) LIS[i]=max(LIS[i],LIS[j]+1);
            }
        }


       for(int i=n-1;i>=0;i--){

            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[i])LDS[i]=max(LDS[i],LDS[j]+1);
            }
       } 


       int ans=n;

       for(int i=0;i<n;i++){

          if(LIS[i]>1 && LDS[i]>1)
          ans=min(ans,n-LIS[i]-LDS[i]+1);
           
       }
     
        return ans;
        
    }
};
