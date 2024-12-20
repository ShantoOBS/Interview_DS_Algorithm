/*
    
    Company Tags                 : Paytm, Zoho, Morgan Stanley, Accolite, Amazon, Microsoft, Snapdeal, 
                                   D-E-Shaw, MakeMyTrip, Oracle, MAQ Software, nearbuy, Nagarro, BrowserStack
     GfG Link                    : https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
*/

//T.C : O(n*m)
//S.C : O(n*m)

class Solution {
  public:
    vector<int>ans;
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        
        int row=mat.size();
        
        int col=mat[0].size();
        
        int top=0, right=col-1;
        int bottom=row-1,left=0;
        
        while(top<=bottom && left<=right){
            
        
        // for right
        for(int i=left;i<=right;i++){
            ans.push_back(mat[top][i]);
        }
        
        top++;
        
        // for bottom 
        
        for(int i=top;i<=bottom;i++){
            ans.push_back(mat[i][right]);
        }
        
        right--;
        
        if(top<=bottom){
        // for left
        
        for(int i=right;i>=left;i--){
            ans.push_back(mat[bottom][i]);
        }
        
        bottom--;
        
        }
        
        if(left<=right){
        // for top
        
        for(int i=bottom;i>=top;i--){
            ans.push_back(mat[i][left]);
        }
         left++;
        
        }
        
       }
        
        
    
        return ans;
    }
};
