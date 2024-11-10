/*
    Youtube Video               : https://www.youtube.com/watch?v=w4W6yya1PIc 
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/maximum-subarray/description/
*/
/******************************************************** C++ ********************************************************/

//Approach - Brute Force (TLE)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {


        int n=nums.size();


        int maxi=INT_MIN;
      

        for(int i=0;i<n;i++){
           

             for(int j=i;j<n;j++){
                    
                    int sum=0;

                    for(int k=i;k<=j;k++)sum+=nums[k];

                    maxi=max(maxi,sum); 
                  
             }
            
              

        }

        return maxi;
        
    }
};


//Approach - Kadane's Algo 
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {


        int n=nums.size();
        int sum=0;
        int maxi=nums[0];
      
        for(int i=0;i<n;i++){
           
           sum+=nums[i]; 

           maxi=max(maxi,sum);

           if(sum<0)sum=0;
        }

        return maxi;
        
    }
};
