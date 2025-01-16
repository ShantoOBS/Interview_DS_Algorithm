/*
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/minimize-xor
*/
/******************************************************** C++ ********************************************************/
//Approach-1 (Starting from num1 and then forming result)
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        
        int n=arr.size();
        
        int ans=0;
        
        map<int,int>mp;
        
        int sum=0;
        
        for(int i=0;i<n;i++){
            
             sum+=arr[i];
             
             if(sum==k){
                   ans=max(ans,i+1);
             }
             
             if(mp.find(sum-k)!=mp.end()){
                 
                   ans=max(ans,i-(mp[sum-k]));
             }
             
             if(mp.find(sum)==mp.end())mp[sum]=i;
        }
        
        
        
        return ans;
    }
};
