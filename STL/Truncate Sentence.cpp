
// Leet-Code Link : https://leetcode.com/problems/truncate-sentence/description/

class Solution {
public:
    string truncateSentence(string s, int k) {


        int ct=0;
       
        string ans="";

        for(int i=0;i<s.length();i++){

            if(s[i]==' ')ct++;

            if(ct>=k){
                break;
            }
            ans+=s[i];

        }

        return ans;
        
    }
};
