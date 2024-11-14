/*
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/?envType=daily-question&envId=2024-11-14
*/
/************************************************************ C++ ************************************************/
//Approach (simple binary search trick)
//T.C : O(nlogn)
//S.C : O(1)

class Solution {
public: 

    bool solve(int n,vector<int>& q,int mid){

        if(mid==0)return false;
       
        long long sum=0;

        for(auto i:q){

            if(i%mid==0)sum+=i/mid;
            else sum+=i/mid+1;
        }
 
        return sum<=n;
          
    }
    int minimizedMaximum(int n, vector<int>& q) {

        if(n==1)return q[0];
       
       sort(q.begin(),q.end());

       int m=q.size();

        if(n==q.size())return q[m-1];

       int l=0;
       int r=100000;

       int ans=0;

       while(l<=r){
         
           int mid=l+(r-l)/2;

           if(solve(n,q,mid)){
             ans=mid;
             r=mid-1;
             
           }
           else l=mid+1;;
            
       }

       return ans;
        
    }
};
