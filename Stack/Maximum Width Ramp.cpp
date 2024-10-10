/*
    Leetcode Link : https://leetcode.com/problems/maximum-width-ramp/description/?envType=daily-question&envId=2024-10-10
*/

//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        
        // Step 1: Build a decreasing stack of indices
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }
        
        int maxWidth = 0;
        
        // Step 2: Traverse from the end and find maximum width ramp
        for (int j = n - 1; j >= 0; --j) {
            while (!s.empty() && nums[s.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - s.top());
                s.pop();
            }
        }
        
        return maxWidth;
    }
};
