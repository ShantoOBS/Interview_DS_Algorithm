/*
    
    Company Tags                : will be soon
    Leetcode Link               : https://leetcode.com/problems/number-of-subarrays-with-and-value-of-k/
*/


/************************************************ C++ ************************************************/




class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
           int size = nums.size();
        
        long long ans = 0;
        
        unordered_map<long long, long long> pre;
        for (int i = 0; i < size; ++i) {
            unordered_map<long long, long long> curr; 
            if (nums[i] == k) {
                ++ans;
            }
            curr[nums[i]] = 1;
            
            for (auto& [value, fre] : pre) {
                long long n= value & nums[i];
                if (n == k) {
                    ans+= fre;
                }
                curr[n] += fre;
            }
            
            pre = curr;
        }
        return ans;
        
    }
};
