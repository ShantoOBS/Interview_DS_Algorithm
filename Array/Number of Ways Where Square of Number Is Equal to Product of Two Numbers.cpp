
// Leet-Code Link : https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/

// T.C : O(n)
// S.C : O(n)
//Approach-1 (Simple solution)
class Solution {
public:
    void twoProduct(long target, vector<int> & nums, int &count) {
        unordered_map<int, int> mp;
        mp[1] = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(target%nums[i] == 0) {
                int remain= target/nums[i];
                count += mp[remain];
            }
            mp[nums[i]]++;
        }
    }

    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int count = 0;
        for(int i = 0; i<n1; i++) {
            twoProduct((long)nums1[i]*nums1[i], nums2, count);
        }
        
        for(int i = 0; i<n2; i++) {
            twoProduct((long)nums2[i]*nums2[i], nums1, count);
        }
        
        return count;
    }
};
