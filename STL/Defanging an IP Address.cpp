
// Leet-Code Link : https://leetcode.com/problems/defanging-an-ip-address/

class Solution {
public:
    string defangIPaddr(string s) 
    {
          auto rgx = regex("\\.");
          string ans=  regex_replace(s, rgx, "[.]");
           return ans;
    }        
};
