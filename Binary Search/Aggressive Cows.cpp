/*
    Company Tags                : will be soon
    GFG Link                    : https://www.geeksforgeeks.org/problems/aggressive-cows/1
*/
/************************************************************ C++ ************************************************************/
//Approach-1 (Binary Search)
//T.C : O(n log(n))
//S.C : O(1)

class Solution {
  public:
     bool check(int mid,int k,vector<int>stalls){
         
         int cnt=1;
         
         int n=stalls.size();
         
         int last_position=stalls[0];
         
         for(int i=1;i<n;i++){
             
             if(stalls[i]-last_position>=mid){
                 cnt++;
                 
                 if(cnt>=k)return true;
                 
                 last_position=stalls[i];
             }
         }
         
        return false;
     }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        
        sort(stalls.begin(),stalls.end());
        
        int n=stalls.size();
        
        int start=0;
        int maxi=0,mini=INT_MAX;
        
        for(auto u:stalls){
            maxi=max(maxi,u);
            mini=min(mini,u);
        }
        
        int ans=-1;
        
        int end=maxi-mini;
        
        while(start<=end){
            
            int mid=start+(end-start)/2;
            
            if(check(mid,k,stalls)){
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
            
        }
        
        return ans;
    }
};
