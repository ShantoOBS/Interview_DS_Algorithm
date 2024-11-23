/*
    Company Tags                  : Zoho, Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft, Samsung, Snapdeal24*7 Innovation Labs, CitrixD-E-Shaw, FactSet, Hike, Housing.com, MetLife, Ola Cabs, Oracle, Payu, Teradata, Visa, Walmart, Adobe, Google, Arcesium
    GFG Link                      : https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
*/
/**************************************************************** C++ ****************************************************************/

//Approach - (Brute Force Solution)
//T.C : O(n^3)
//S.C : O(1)

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        
        
        int n=arr.size();
        
        int maxi=INT_MIN;
        
        
        for(int i=0;i<n;i++){
              
              for(int j=i;j<n;j++){
                  
                  int sum=0;
                  
                  for(int k=i;k<=j;k++)sum+=arr[k];
                  
                  maxi=max(maxi,sum);
              }
              
        }
        
        return maxi;
    }
};


//Approach - (Better Solution)
//T.C : O(n^2)
//S.C : O(1)

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        
        
        int n=arr.size();
        
        int maxi=INT_MIN;
        
        
        for(int i=0;i<n;i++){
            
              int sum=0;
              
              for(int j=i;j<n;j++){
                sum+=arr[j];
                maxi=max(maxi,sum);  
              }
              
              
        }
        
        return maxi;
    }
};






//Approach Optimal (Kadane's Algorithm)
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        
        
        int n=arr.size();
        
        int maxi=INT_MIN;
        
        int sum=0;
        
        for(int i=0;i<n;i++){
              
              if(sum<0){
                  sum=0;
              }  
              sum+=arr[i];
              
              maxi=max(maxi,sum);
        }
        
        return maxi;
    }
};

