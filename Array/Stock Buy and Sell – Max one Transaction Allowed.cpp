/*
    Company Tags                  : Paytm, Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft, Samsung, D-E-Shaw, Hike, MakeMyTrip, Ola Cabs, Oracle, Walmart, Goldman Sachs, Directi, Intuit, SAP Labs, Quikr, Facebook, Salesforce,Pubmatic, Sapient, Swiggy
    GFG Link                      : https://www.geeksforgeeks.org/problems/buy-stock-2/1
*/
/**************************************************************** C++ ****************************************************************/
//Approach-1 
//T.C : O(n)
//S.C : O(1) 

class Solution {
  public:
    int maximumProfit(vector<int> &arr) {
        // code here
        
        int n=arr.size();
        
        int ans=0;
        
        int s=0;
        
        for(int i=1;i<n;i++){
            
            if(arr[i]<arr[s]){
                s=i;
            }
            else ans=max(ans,arr[i]-arr[s]);
        }
         
        
        return ans;
    }
};

