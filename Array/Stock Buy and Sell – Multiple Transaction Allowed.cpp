/*     Scroll below to see JAVA code also    */
/*
    Company Tags                  : Paytm, Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft, Samsung, D-E-Shaw, Hike, MakeMyTrip, Ola Cabs, Oracle, Walmart, Goldman Sachs, Directi, Intuit, SAP Labs, Quikr, Facebook, Salesforce,Pubmatic, Sapient, Swiggy
    GFG Link                      : https://www.geeksforgeeks.org/problems/stock-buy-and-sell2615/1
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
        
        int sum=0;
        
        for(int i=1;i<n;i++){
            
            int j=i;
            
            int mini=arr[j-1];
            
            while( j< n && arr[j-1]<=arr[j]){
               j++;
            }
            
            sum+=(arr[j-1]-mini);
            i=j;
        }
        
        
        return sum;
        
        
    }
};

/**************************************************************** JAVA ****************************************************************/
//Approach-1 
//T.C : O(n)
//S.C : O(1) 

class Solution {
    public int maximumProfit(int arr[]) {
        // code here
        int n=arr.length;
        
        int sum=0;
        
        for(int i=1;i<n;i++){
            
            int j=i;
            
            int mini=arr[j-1];
            
            while( j< n && arr[j-1]<=arr[j]){
               j++;
            }
            
            sum+=(arr[j-1]-mini);
            i=j;
        }
        
        
        return sum;
    }
}
