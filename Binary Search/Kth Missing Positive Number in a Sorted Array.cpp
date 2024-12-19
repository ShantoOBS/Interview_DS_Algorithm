
/*
    Company Tags                : will be soon
    GFG Link                    : https://www.geeksforgeeks.org/problems/kth-missing-positive-number-in-a-sorted-array/1
*/
/************************************************************ C++ ************************************************************/
//Approach-1 (Brute force)
//T.C : O(n+k)
//S.C : O(1)

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        
        int n=arr.size();
        
        int cnt=0;
        
        unordered_set<int>st(arr.begin(),arr.end());
        
        int ans=-1;
        
        int last=arr[n-1];
        
        for(int i=1;i<=last;i++){
            
             if(st.find(i)==st.end()){
                 ans=i;
                 cnt++;
                 if(cnt==k)return ans;
             }
        }
        
        
        int first=last+1;
        
        while(cnt<k){
            
            ans=first++;
            cnt++;
            
            if(cnt==k)return ans;
        }
        
        return ans;
 
    }
};


//Approach-1 (Binary Search)
//T.C : O(n long(n))
//S.C : O(n)

class Solution {
  public:
    bool check(vector<int>arr,int mid,int k){
           
           unordered_set<int>st(arr.begin(),arr.end());
           
           int cnt=0;
           
           for(int i=1;i<=mid;i++){
               if(st.find(i)==st.end())cnt++;
           }
           
           
           return cnt>=k;
    }
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        
        int n=arr.size();
        
        int start=1;
        int end=arr[n-1]+k;
        
        int ans=-1;
        
        while(start<=end){
            
            int mid=start+(end-start)/2;
            
            if(check(arr,mid,k)){
               ans= mid;
               end=mid-1;
            }
            else start=mid+1;
        }
        
        return ans;  
    }
};


