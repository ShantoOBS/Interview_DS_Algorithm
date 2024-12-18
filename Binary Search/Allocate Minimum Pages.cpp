/*
    Company Tags                : Infosys, Amazon, Microsoft, Google, Codenation, Uber
    GFG Link                    : https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
*/


/************************************************************ C++ ************************************************************/
//Approach-1 (Binary Search)
//T.C : O(n log n)
//S.C : O(n)

class Solution {
  public:
  
    vector<int>pre;
  
    bool check(int k,int mid,vector<int>arr){
        
        if(k==arr.size() && *max_element(arr.begin(),arr.end())<=mid)return true;
        
        int cnt=0;
        
        int i=0;
        int n=arr.size();
        int sum=0;
        
        while(i<n){
             
             if(cnt>=k)return false;
             
             if(sum+arr[i]<=mid){
                 sum+=arr[i];
                 i++;
             }
             else{
                 sum=0;
                 cnt++;
             }
        }
        
        return true;
        
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        
        int n=arr.size();
        
        if(k>n)return -1;
        
        pre.push_back(arr[0]);
        
        for(int i=1;i<n;i++){
            pre.push_back(pre.back()+arr[i]);
        }
        
        
        int start=0;
        int end=pre[n-1];

        int ans=-1;
        
    
        while(start<=end){
            
             int mid=(end+start)/2;
             
             if(check(k,mid,arr)){
                 ans=mid;
                 end=mid-1;
             }
             else start=mid+1;
        }
     
     
        return ans;
        
        
        
    }
};
