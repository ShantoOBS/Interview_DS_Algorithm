/*
    Company Tags                : Flipkart, Amazon, Microsoft
    GFG Link                    : https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1
*/
T.C : O(n)
S.C : O(n)
  
class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        
        stack<int>st;
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++){
            
              while(!st.empty() and arr[st.top()]>arr[i]) {
                  
                  
                  int idex=st.top();
                  st.pop();
                  
                  if(st.empty()){
                      int range=i;
                      ans[range-1]=max(ans[range-1],arr[idex]);
                  }
                  else{
                      
                      int range=i-st.top()-1;
                      
                       ans[range-1]=max(ans[range-1],arr[idex]);
                      
                  }
              }
              
              st.push(i);
        }
        
          while( !st.empty() ) {
                  
                  
                  int idex=st.top();
                  st.pop();
                  
                  if(st.empty()){
                      int range=n;
                      ans[range-1]=max(ans[range-1],arr[idex]);
                  }
                  else{
                      
                      int range=n-st.top()-1;
                      
                       ans[range-1]=max(ans[range-1],arr[idex]);
                      
                  }
              }
                
              for(int i=n-2;i>=0;i--){
                  
                  ans[i]=max(ans[i],ans[i+1]);
              }
              
              return ans;
        
    }
};
