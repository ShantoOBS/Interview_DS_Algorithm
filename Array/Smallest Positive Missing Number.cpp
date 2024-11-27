/*
    Company Tags                : Accolite, Amazon, Samsung, Snapdeal
    GfG Link                    : https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
*/

//Approach-1 
//T.C :O(n)
//S.C :O(n)

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        
       sort(arr.begin(),arr.end());
       
       for(int i=1;i<=arr[n-1];i++){
           
           if(mp.find(i)==mp.end()){
               return i;
           }
       }
       
       if(arr[n-1]<0)return 1;
       
       return arr[n-1]+1;
    }
};
