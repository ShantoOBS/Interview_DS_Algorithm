/*
    Company Tags                : will update soon
    GFG Link                    : https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1
*/
/**************************************************************** C++ ****************************************************************/
//Approach (Simple traversal using two pointers)
//T.C : O(2*n)
//S.C : O(2*n)

class Solution {
  public:
  
   int solve(string s){
       
        int n=s.size();
        
        vector<int>lps(n);
        
        lps[0]=0;
        
        int i=1;
        int len=0;
        while(i<n){
            
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
                
            }
            else {
                
                 if(len>0){
                     len=lps[len-1];
                 }
                 else {
                     len=0;
                     lps[i]=0;
                     i++;
                 }
            }
              
        }
        
        
        
        
        return len;
   }
  
    int minChar(string& s) {
      
      string temp=s;
      
      reverse(temp.begin(),temp.end());
      
      string new_str=s+'$'+temp;
      int len=solve(new_str);
      
      return s.size()-len;
      
    }
};
