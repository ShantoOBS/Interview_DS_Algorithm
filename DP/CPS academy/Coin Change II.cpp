/*

   Problem Link : https://leetcode.com/problems/coin-change-ii/

*/

class Solution {
public:
    int dp[305][5023];

    int solve(int i,int n,vector<int>&coins){

          if(i==coins.size() ||  n==0)return n==0;

          if(dp[i][n]!=-1)return dp[i][n];
         
          int ret=0;

          for(int j=0;j<=n;j++){

              if(n-(j*coins[i])>=0 )ret+=solve(i+1,n-(j*coins[i]),coins);
              else break;
          }

          return dp[i][n]=ret;
    }


    int change(int amount, vector<int>& coins) {
         
           memset(dp,-1,sizeof(dp));

           return solve(0,amount,coins);
    }
};
