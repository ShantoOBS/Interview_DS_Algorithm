/*
    Company Tags                  : Infosys, Flipkart, Amazon, Microsoft, FactSet, Hike, MakeMyTrip, Google, Qualcomm, Salesforce
    GFG Link                      : https://www.geeksforgeeks.org/problems/next-permutation5226/1
*/
/**************************************************************** C++ ****************************************************************/
//Approach-1 (STL)
//T.C : O(n)
//S.C : O(1)

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        next_permutation(arr.begin(),arr.end());
    }
};

//Approach-1 (optimal)
//T.C : O(n)
//S.C : O(1)

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        
        int index=-1;
        
        int n=arr.size();
        
        for(int i=n-2;i>=0;i--){
            
            if(arr[i]<arr[i+1]){
                index=i;
                break;
            }
        }
        
        if(index==-1){
            reverse(arr.begin(),arr.end());
        }
        else{
            
            for(int i=n-1;i>=index;i--){
                
                if(arr[index]<arr[i]){
                    swap(arr[index],arr[i]);
                    break;
                }
            }
            
            
           int i=index+1;
           int j=n-1;
           
           while(i<=j){
               
               swap(arr[i++],arr[j--]);
           }
            
            
        }
    }
};


