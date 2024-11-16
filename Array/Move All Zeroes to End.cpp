/*     Scroll below to see JAVA code also    */
/*
    Company Tags                : Paytm, Amazon, Microsoft, Samsung, SAP Labs, Linkedin, Bloomberg
    GFG Link                    : https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1
*/

/************************************************************ C++ ************************************************/
//Approach -1
//T.C : O(n) 
//S.C : O(1)

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        
        int j=0;
        
        for(int i=0;i<n;i++)
             if(arr[i]!=0)arr[j++]=arr[i];
            
            while(j<n)arr[j++]=0;
        
        
        
    }
};




/************************************************************ JAVA ************************************************/
//Approach -1
//T.C : O(n) 
//S.C : O(1)

class Solution {
    void pushZerosToEnd(int[] arr) {
        // code here
        int n=arr.length;
    
        
        int j=0;
        
        for(int i=0;i<n;i++)
             if(arr[i]!=0)arr[j++]=arr[i];
            
            while(j<n)arr[j++]=0;
        
        
        
    }
}
