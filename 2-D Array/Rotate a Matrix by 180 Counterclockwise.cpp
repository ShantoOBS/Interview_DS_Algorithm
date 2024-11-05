/*
    Company Tags                : Samsung
    GFG Link                    : https://www.geeksforgeeks.org/problems/c-matrix-rotation-by-180-degree0745/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
*/
/**************************************************************** C++ ****************************************************************/

//Approach-1 
//T.C : O(n^2)
//S.C : O(1)


class Solution {
  public:
    void rotateMatrix(vector<vector<int> >& mat) {
        // Code here
        // Rotate the matrix in place
        
        int col=mat.size();
        int row=mat[0].size();
        
        int start=0;
        int end=row-1;
        
        while(start<end){
            
            for(int i=0;i<col;i++){
                
                swap(mat[start][i],mat[end][i]);
            }
            
            start++;
            end--;
        }
        
        
        for(int i=0;i<row;i++){
            
            int start=0;
            int end=col-1;
            
            while(start<end){
                
                swap(mat[i][start++],mat[i][end--]);
            }
        }
        
        
        
    }
};
