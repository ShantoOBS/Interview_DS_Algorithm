/*
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/matrix-diagonal-sum/description/
*/
   
/******************************************************** C++ **********************************************/
//T.C : O(m*n)
//S.C : O(1)
class Solution {

public:
    int diagonalSum(vector<vector<int>>& mat) {

         int row=0;

    auto lamda= [&](int sum,vector<int>v){

           sum+=v[row];
           if(row!=v.size()-row-1){
             sum+=v[v.size()-row-1];
           }
           row++;

           return sum;
    };

      int ans=accumulate(begin(mat),end(mat),0,lamda);
      return ans;


        
    }
};
