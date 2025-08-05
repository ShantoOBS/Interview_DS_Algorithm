/*
    Company Tags                : will be soon
    Leetcode Link               : https://leetcode.com/problems/fruits-into-baskets-ii/description/?envType=daily-question&envId=2025-08-05
*/

/*************************************************** C++ ********************************************************/

// T.C : O(n^2)
// S.C : O(1)

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int ans=0;

        int n=fruits.size();

        for(int i=0;i<n;i++){

              
                for(int j=0;j<n;j++){

                     if(baskets[j]>=fruits[i] && baskets[j]!=-1){
                        baskets[j]=-1;
                        break;
                     }
                }
        }

        for(auto u:baskets){

             if(u!=-1)ans++;
        }

        return ans;
    }
};
