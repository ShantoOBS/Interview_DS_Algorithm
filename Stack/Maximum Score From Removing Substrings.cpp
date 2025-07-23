/*
    Company Tags                : Google, Meta, Amazon
    Leetcode Link               : https://leetcode.com/problems/maximum-score-from-removing-substrings
*/


/**************************************************************** C++ ********************************************************/
//Approach-1 (Using Stack)
//T.C : O(n)
//S.C : O(n)

class Solution {
public:

    int solve(string s,char ch1,char ch2,int val ,string &str){
         
         int ans=0;

         stack<int>st;

         for(auto ch:s){

                if(ch==ch2 && !st.empty() && st.top()==ch1) {
                  ans+= val;
                  st.pop();
                }
                else st.push(ch);
         }

         while(!st.empty()){
            str+=st.top();
            st.pop();
         }

         reverse(str.begin(),str.end());

         return ans;

    }
    int maximumGain(string s, int x, int y) {

          int ans=0;

          if(x<y){

               string str;
               int temp=solve(s,'b','a',y,str);
               string t;
               temp+=solve(str,'a','b',x,t);

               ans=temp;
          }
          else{
               
                string str;
                int temp=solve(s,'a','b',x,str);
                
               string t;
               temp+=solve(str,'b','a',y,t);
              
               ans=temp;

          }

          return ans;
        
    }
};
