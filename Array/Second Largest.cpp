/*     Scroll below to see JAVA code also    */
/*
    Company Tags                : SAP Labs, Rockstand
    GFG Link                    : https://www.geeksforgeeks.org/problems/second-largest3735/1
*/
/************************************************************ C++ ************************************************/
//Approach -1
//T.C : O(n)
//S.C : O(1)

class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        
        sort(arr.begin(),arr.end());
        
        int n=arr.size();
    
        for(int i=n-1;i>=1;i--){
            
            if(arr[i]>arr[i-1])return arr[i-1];
        }
        
        return -1;
    }
};

/************************************************************JAVA ************************************************/
//Approach -1
//T.C : O(n)
//S.C : O(1)

class Solution {
    public int getSecondLargest(int[] arr) {
        // Code Here
        
        Arrays.sort(arr);
        
        int n=arr.length;
    
        for(int i=n-1;i>=1;i--){
            
            if(arr[i]>arr[i-1])return arr[i-1];
        }
        
        return -1;
    }
}
