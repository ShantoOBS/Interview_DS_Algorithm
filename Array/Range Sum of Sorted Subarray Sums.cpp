
/*
    
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/
*/


/************************************************ C++ ************************************************/



class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int l, int r) {
        
        vector<int>v;
         int t=0;

        for(int i=0;i<n;i++){
            t=0;
            for(int j=i;j<n;j++){
                t=nums[j]+t;
                v.push_back(t);
            }


        }


        sort(v.begin(),v.end());
           
        int ans=0;
        int MOD = 1000000007;
        for(int i=l-1;i<r;i++){
          ans=(v[i]+ans)%MOD;
        }   

        return ans;
        
            
    }
};
