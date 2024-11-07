/*
    Company Tags                : will soon update
    GFG Link                    : https://www.geeksforgeeks.org/problems/split-array-in-three-equal-sum-subarrays/1
*/

/******************************************************** C++ ********************************************************/
//Approach-1 ( array)
//T.C : O(n) ~= O(n)
//S.C :  O(1)

class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        
        int sum=0;
        
        for(auto i:arr)sum+=i;
        
        vector<int>v(2,-1);
        
        if(sum%3!=0){
            return v;
        }
        else{
            
            int target=sum/3;
            
            int first=-1;
            int second=-1;
            
            int curr=0;
            
            for(int i=0;i<arr.size();i++){
                
                curr+=arr[i];
                
                if(curr==target && first==-1){
                    first=i;
                }
                else if(curr== 2*target && first != -1){
                    v[0]=first;
                    v[1]=i;
                    return v;
                   
                }
            }
                       
        }
       
       return v;
        
    }
};
