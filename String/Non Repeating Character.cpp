/*
    Company Tags                : Flipkart, Amazon, Microsoft, D-E-Shaw, MakeMy Trip, Ola Cabs, Payu, Teradata, Goldman Sachs, MAQ Software, InfoEdge, OATS Systems, Tejas Network
    GfG Link                    : https://www.geeksforgeeks.org/problems/non-repeating-character-1587115620/1
*/
------------------------------------------------------------- C++ ---------------------------------------------------------
//Approach-1 
//T.C :O(n)
//S.C :O(n)

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        
        unordered_map<char,int>mp;
        
        for(auto ch:s)mp[ch]++;
        
        
        for(auto u:s){
            
            if(mp[u]==1)return u;
        }
        
        return '$';
    }
};
