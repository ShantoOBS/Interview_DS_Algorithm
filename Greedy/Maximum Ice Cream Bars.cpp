/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Apply, Amazon, Meta, Microsoft
    Leetcode Link               : https://leetcode.com/problems/maximum-ice-cream-bars/
*/


/*********************************************************** C++ **************************************************/
//Approach-1 (Normal Sorting and greedily choosing)
//T.C : O(n log n)
//S.C : O(1) (ignoring the space taken for sorting internally)

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        int ans=0;

        sort(costs.begin(),costs.end());

        for(auto x:costs){

              if(coins>=x){
                ans++;
                coins-=x;
              }
              else{
                break;
              }
        }

        return ans;
        
    }
};

