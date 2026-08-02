/*
    Company Tags                : Google, Adobe, Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/stone-game/
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recur+Memo) O(n^2) - Standard Optimal Game Strategy Concept
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int dp[600][600];
    int solve(vector<int>piles,int i,int j){

          if(i==j)return piles[i];

          if(dp[i][j]!=-1)return dp[i][j];


          int max_f=piles[i]+solve( piles,i+1,j );
          int max_l=piles[j]+solve( piles,i,j-1 );


          return dp[i][j]=max(max_f,max_l);
    }
    bool stoneGame(vector<int>& piles) {
         
        memset(dp,-1,sizeof(dp)) ;
        
        int sum=accumulate(piles.begin(),piles.end(),0);
         
         int t=solve(piles,0,piles.size()-1);

        return (sum-t)<=t;
        
    }
};

