/*
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/rotate-image/
*/

/**************************************************************** C++ ****************************************************************/

//Approach-1 
//T.C : O(n^2)
//S.C : O(1)


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int col=matrix.size();

        int row=matrix[0].size();


        for(int i=0;i<col-1;i++){

            for(int j=i+1;j<row;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }


        for(int i=0;i<col;i++){

            int start=0;
            int end=row-1;

            while(start<end){

                swap(matrix[i][start++],matrix[i][end--]);
            }
        }
        
    }
};
