/*
    Company Tags                : Accolite, Amazon, Microsoft
    GFG Link                    : https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

*/
/*************************************************************************** C++ ***************************************************************************/
//Approach-1 (Sliding Window)
//T.C : O(n) 
//S.C : O(k)

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        
        vector<int>ans;
        
        int n=arr.size();
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<k;i++)mp[arr[i]]++;
        
        ans.push_back(mp.size());
        
        int i=0,j=k;
        
        while(i<n-k && j<n){
            
            mp[arr[j]]++;
     
              if(mp[arr[i]]>1){
                  mp[arr[i]]--;
              }
              else{
                  mp.erase(arr[i]);
              }
   
              ans.push_back(mp.size());
              
              i++;
              j++;
        }
        
        return ans;
    }
};
