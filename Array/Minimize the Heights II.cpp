/*
    Company Tags                  : Microsoft, Adobe
    GFG Link                      : https://www.geeksforgeeks.org/problems/minimize-the-heights-i/1
*/
/**************************************************************** C++ ****************************************************************/
//Approach-1 
//T.C : O(n)
//S.C : O(1) 

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        
        sort(arr.begin(),arr.end());
        
        int n=arr.size();
        
        int ans=arr[n-1]-arr[0];
        
        
        for(int i=0;i<=n-2;i++){
            
           int maxi=max(arr[n-1]-k,arr[i]+k);
           int mini=min(arr[0]+k,arr[i+1]-k);
           if(mini<0)continue;
           ans=min(ans,abs(maxi-mini));
        
        }
        
        return ans;
    }
};
