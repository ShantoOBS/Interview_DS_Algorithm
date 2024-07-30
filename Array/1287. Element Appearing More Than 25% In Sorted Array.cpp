/*
    
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/
*/


/************************************************ C++ ************************************************/



class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
         return a.second>b.second;
     }
    int c(vector<int>arr,int n,int s){

        int co=0;

        for(int i=0;i<n;i++){
            if(arr[i]==s){
                co++;
            }
        }
        return co;
    }
    int findSpecialInteger(vector<int>& arr) {
        vector<pair<int,int>>ans;
        int maxi=0;
           int temp=0;
       int n=arr.size();
        for(int i=0;i<n;i++){
            
           ans.emplace_back(arr[i],c(arr,n,arr[i]));
        }

        sort(ans.begin(),ans.end(),cmp);
        int t=ans[0].first;
        return t;
    }
};
