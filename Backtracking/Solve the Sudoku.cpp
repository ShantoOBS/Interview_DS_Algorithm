/*
    	Company Tags  : Zoho, Flipkart, Amazon, Microsoft, MakeMy Trip, Ola Cabs, Oracle, MAQ Software, Directi, PayPal, Samsung
    	GFG Link      : https://www.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
*/
/*************************************************************** C++ *************************************************************************/
T.C : O(9^81)
S.C : O(1)

class Solution {
  public:
  
    bool solve(vector<vector<int>>&mat){
        
         for(int i=0;i<mat.size();i++){
             
                for(int j=0;j<mat[0].size();j++){
                    
                     if(mat[i][j]==0){
                         
                           for(int k=1;k<=9;k++){
                               
                                if(isvalid(mat,i,j,k)){
                                    mat[i][j]=k;
                                    if(solve(mat)==true)return true;
                                    else mat[i][j]=0;
                                }
                           }
                           
                           return false;
                     }
                }
         }
         
         return true;
    }
    
    bool isvalid(vector<vector<int>>&mat,int row,int col,int val){
        
        for(int i=0;i<9;i++){
            
            if(mat[row][i]==val)return false;
            
            if(mat[i][col]==val)return false;
            
            if( mat[ (3*(row/3)) + (i/3) ] [ (3*(col/3)) + (i%3) ]==val )return false;
        }
        return  true;
    }
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
        
    }
};
