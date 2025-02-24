/*
    Company Tags                : Flipkart, Accolite, Amazon, Microsoft, Samsung, Adobe
    GFG Link                    : https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
*/
T.C : O(n)
S.C : O(n)

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {

     int n=arr.size();
      
      vector<int>ans(n,1);
      
      stack<int>st;
    
      for(int i=0;i<n;i++){
          
           while(!st.empty() and arr[i]>=arr[st.top()]){
               ans[i]+=ans[st.top()];
               st.pop();
           }
           st.push(i);
      }
      
      return ans;
     
    }
};
