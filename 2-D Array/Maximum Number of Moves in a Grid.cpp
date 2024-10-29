/*

    Company Tags                : Facebook, Amazon, Netflix, Apple, Google
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/?envType=daily-question&envId=2024-10-29
    
 */   
    
/******************************************************************** C++ *********************************************************************************/
//Approach-1 (Dp)
//T.C : O(n*m)
//S.C : O(n*m)

class Solution {
public:
 
    int solve(vector<vector<int>>& grid ,int i,int j,int pre,vector<vector<int>>&dp){


        if(j+1>=grid[0].size())return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int maxii=0;
        
        if(i-1>=0 && pre<grid[i-1][j+1])
         maxii=max(maxii, 1+solve(grid,i-1,j+1,grid[i-1][j+1],dp) );

        if(i+1<grid.size() && pre<grid[i+1][j+1])
         maxii=max(maxii, 1+solve(grid,i+1,j+1,grid[i+1][j+1],dp) );


        if( pre<grid[i][j+1])
         maxii=max(maxii, 1+solve(grid,i,j+1,grid[i][j+1],dp) ); 
        

        return dp[i][j]=maxii;


    }
    int maxMoves(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        int maxi=0;

        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i=0;i<n;i++){

         maxi=max(maxi,solve(grid,i,0,grid[i][0],dp));
            
        }


        return maxi;
        
    }
};

