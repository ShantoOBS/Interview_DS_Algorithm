/*
    Company Tags                  : Morgan Stanley, Amazon, Microsoft, OYO Rooms, D-E-Shaw, Google
    GFG Link                      : https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1
*/
/**************************************************************** C++ ****************************************************************/
//Approach - (suffix and preffix)
//T.C : O(n)
//S.C : O(1)

class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        
        int n=arr.size();
        
        int maxi=INT_MIN;
        
        int product=1;
        
        int pre=1;
        int suff=1;
        
        for(int i=0;i<n;i++){
            
            if(pre==0)pre=1;
            if(suff==0)suff=1;
            
            pre*=arr[i];
            suff*=arr[n-i-1];
            
            maxi=max(maxi,max(pre,suff));
        }
        
        return maxi;
    }
};
