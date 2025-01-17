/*
    Company Tags                : Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft, D-E-Shaw, Intuit, Opera
    GFG Link                    : https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1
*/
/******************************************************** C++ ********************************************************/
//Approach-1 
//T.C : O(n)
//S.C : O(n)

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        
        long long p=1;
        
        int cnt=count(arr.begin(),arr.end(),0);
        
        vector<int>ans;
        
        
        if(cnt>1){
            
            for(auto u:arr)ans.push_back(0);
            
            return ans;
        }
        
        
        for(auto u:arr){
            
            if(u==0)continue;
            
            else p*=u;

        }
        
        
         if(cnt==1){
             
             for(auto u:arr){
                 
                  if(u==0)ans.push_back(p);
                  else ans.push_back(0);
             }
             
             return ans;
         }
        
        
        
        
        for(auto u:arr){
           ans.push_back(p/u);
        }
        
        return ans;
        
    }
};
