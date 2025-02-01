/*
    Company Tags                : Amazon, Microsoft, Intuit, Apple
    GFG Link                    : https://www.geeksforgeeks.org/problems/word-search/1
*/


/************************************************ C++ ************************************************/
The time complexity of this solution is O(N × M × 4^K), where:

N = number of rows in the matrix.
M = number of columns in the matrix.
K = length of the word.
Each cell acts as a starting point, leading to a recursive DFS.
The DFS explores 4 directions (up, down, left, right) at each step.
The worst case is when all K characters match, leading to 4^K recursive calls.

//S.C : O(N × M)

class Solution {
  public:
  
    bool solve(vector<vector<char>>& mat, string& word,int row,int col,vector<vector<bool>>&visited,int index){
        
        if(index==word.size())return true;
          
    if(row < 0 || row >= mat.size() || col < 0 || col >= mat[0].size() || visited[row][col] || mat[row][col] != word[index]) 
    return false;

        
        visited[row][col]=true;
        
        bool left=solve(mat,word,row-1,col,visited,index+1);
        bool right=solve(mat,word,row+1,col,visited,index+1);
        bool up=solve(mat,word,row,col-1,visited,index+1);
        bool down=solve(mat,word,row,col+1,visited,index+1);
        
        visited[row][col]=false;
        
        return (left || right || up || down);
        
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        
        int row=mat.size();
        int col=mat[0].size();
        
        for(int i=0;i<row;i++){
            
             vector<vector<bool>>visited(row,vector<bool>(col,false));
             
             for(int j=0;j<col;j++){
                     
                  
                   if(solve(mat,word,i,j,visited,0))return true;

                   
             }
        }
        
        return false;
    }
};
