
/*
    Company Tags                : Flipkart, Directi, Adobe, Google, Nagarro, Media.net
    GfG Link                    : https://www.geeksforgeeks.org/problems/anagram-1587115620/1
*/
------------------------------------------------------------- C++ ---------------------------------------------------------
//Approach-1 
//T.C :O(n)
//S.C :O(n)

class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        
          vector<int>v(26,0);
        
        vector<int>vec(26,0);
        
        for(auto ch:s1){
            
            int temp=ch-'a';
            v[temp]++;
        }
        
        for(auto ch:s2){
            int temp=ch-'a';
            vec[temp]++;
        }
        
        
        if(vec!=v){
            return false;
        }
        
        
        return true;
        
        
    }
};
