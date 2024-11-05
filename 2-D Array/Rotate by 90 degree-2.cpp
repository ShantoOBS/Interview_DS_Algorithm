/*
    Company Tags                : Paytm, Zoho, Morgan, Stanley, Amazon, Microsoft, Samsung, Snapdeal, D-E-Shaw
    GFG Link                    : https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
*/
/**************************************************************** C++ ****************************************************************/
//Approach-1 
//T.C : O(n^2)
//S.C : O(1)

Approach -1 


class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix) {
        // code here
        
      int n=matrix.size();

 for(int i=0;i<n-1;i++){                           //transpose
   for(int j=i+1;j<n;j++){
       swap(matrix[i][j],matrix[j][i]);
    }
 }

 for (int j=0;j<n;j++)                 //reverse column 
 {
    int top=0,bottom=n-1;
    while(top<bottom) {
       swap(matrix[top++][j], matrix[bottom--][j]);
     }
  }  

      
    }
};


Approach-2

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix) {
        // code here
        
     int n=matrix.size();

for(int i=0;i<n;i++){   
        reverse(matrix[i].begin(),matrix[i].end());     //reverse rows
 }
 for(int i=0;i<n;i++){                         //transpose
     for(int j=i+1;j<n;j++){
         swap(matrix[i][j],matrix[j][i]);
      }
  }
      
    }
};
