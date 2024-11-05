/*
    Company Tags                : Paytm, Zoho, Morgan, Stanley, Amazon, Microsoft, Samsung, Snapdeal, D-E-Shaw
    GFG Link                    : https://www.geeksforgeeks.org/problems/rotate-by-90-degree0356/1
*/

/**************************************************************** C++ ****************************************************************/

//Approach-1 
//T.C : O(n^2)
//S.C : O(1)


void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    
     
     int n=mat.size();
     
     int m=mat[0].size();
     
    // transfrom matrix col to row
    
     for(int i=0;i<n-1;i++){
         
         for(int j=i+1;j<m;j++){
             
              swap(mat[i][j],mat[j][i]);
         }
     }
     
     
     // reverse matrix row
     
     for(int i=0;i<n;i++){
         
          int s=0;
          int e=m-1;
          
          while(s<e){
              
              swap(mat[i][s],mat[i][e]);
              s++;
              e--;
          }
     }
     
     
}
