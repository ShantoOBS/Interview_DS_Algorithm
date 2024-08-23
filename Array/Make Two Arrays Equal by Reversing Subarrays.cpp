/*
  
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays
*/

class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& a) {


        sort(t.begin(),t.end());

        sort(a.begin(),a.end());

        if(a==t)return true;

        return false;
        
    }
};
