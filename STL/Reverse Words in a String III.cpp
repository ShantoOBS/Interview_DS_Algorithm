
// Leet-Code Link : https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {

        int first=0;
        s+=' ';
        
        for(int i=0;i<s.length();i++){

            if(s[i]==' '){
               reverse(s.begin()+first,s.begin()+i);
               first=i+1;
            }
           
        }

        s.pop_back();

        return s;
    }
};
