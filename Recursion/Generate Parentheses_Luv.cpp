/*
    Company Tags                : Samsung
    Leetcode Qn Link            : https://leetcode.com/problems/generate-parentheses/
*/

/************************************************************ C++ ************************************************************/
//Approach-1 (Simple Recursion)

class Solution {
public:
    vector<string>ans;

    void gen(string &s,int open,int close){

        if( open==0 && close==0){
            ans.push_back(s);
            return;
        }


        if(open>0){
             s.push_back('(');
             gen(s,open-1,close);
             s.pop_back();
        }

        if(close>0){

              if(open<close){
                s.push_back(')');
                gen(s,open,close-1);
                s.pop_back();
              }
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        gen(s,n,n);  
        return ans;
    } 
};
