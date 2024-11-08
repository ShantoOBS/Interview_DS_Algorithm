/*
    Company Tags                : Google
    GFG Link                    : https://www.geeksforgeeks.org/problems/minimum-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it--170645/1
*/
/******************************************************** C++ ********************************************************/
//Approach - 1
//T.C : O(n)
//S.C : O(1)

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        
        int ans=1;
        
        string rep=s1;
        
        while(s1.size()<s2.size()){
            s1+=rep;
            ans++;
        }
        
        if(s1.find(s2)!=-1)return ans;
        
        s1+=rep;
        
        ans++;
        
        if(s1.find(s2)!=-1)return ans;
        
        return -1;
        
    }
    
};
