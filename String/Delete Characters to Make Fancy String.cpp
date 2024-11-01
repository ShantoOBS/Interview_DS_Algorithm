/*
    Company Tags      : will be soon
    Leet-Code Link    : https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2024-11-01
*/
************************************************************ C++ ************************************************************
// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    string makeFancyString(string s) {

        int n=s.size();

        int cnt=0;

        if(n<=2)return s;

        string ans="";

        ans+=s[0];
        ans+=s[1];


        for(int i=2;i<n;i++){
    
                int m=ans.size();

                if(ans[m-1]==s[i] && ans[m-2]==s[i]){
                     continue;
                }
                else{
                   ans+=s[i];

                }
           
        }


        return ans;


        
    }
};
