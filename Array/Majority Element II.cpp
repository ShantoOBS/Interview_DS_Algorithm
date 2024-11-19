/*
    Company Tags                 : Will update soon
    GFG Link                     : https://www.geeksforgeeks.org/problems/majority-vote/1
*/
/**************************************************************** C++ ****************************************************************/
//Approach 
//T.C : O(n)
//S.C : O(n)

class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        
        int n=arr.size();
        
        int val=n/3;
        
        map<int,int>mp;
        
        for(auto i:arr)mp[i]++;
        
        vector<int>ans;
        
        for(auto i:mp){
            
            if(i.second>val)ans.push_back(i.first);
        }
        
        return ans;
    }
};
