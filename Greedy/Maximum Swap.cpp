/*
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/maximum-swap/?envType=daily-question&envId=2024-10-17
*/

// T.C : O(n)
// S.C : O(n)

class Solution {
public:
    int maximumSwap(int num) {

        unordered_map<char,int>mp;
        string nums=to_string(num);
        string nums2=nums;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }

       // for(auto i:mp)cout<<i.first<<" "<<i.second<<endl;

        sort(nums2.rbegin(),nums2.rend());
        int count=0;
        int i=0;

        while(i<nums.size()){
            if(nums2[i]==nums[i]) i++;
            else{
                swap(nums[mp[nums2[i]]],nums[i]);
                break;
            }
        }

        return stoi(nums) ;

    }
};
