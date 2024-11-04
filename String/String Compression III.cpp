/*     Scroll below to see JAVA code also    */
/*
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/string-compression-iii
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Simple Simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string compressedString(string word) {
        string comp = "";

        int n = word.length();
        int i = 0;

        while(i < n) {
            int count = 0;
            char ch   = word[i];

            while(i < n && count < 9 && word[i] == ch) {
                count++;
                i++;
            }

            comp += to_string(count) + ch;
        }

        return comp;
    }
};

//Approach (Simple Simulation)
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    string compressedString(string word) {

      map<char,int>mp;

      word+=' ';

      int n=word.size();

      string s="";

      for(int i=0;i<n-1;i++){
  
        if(mp[word[i]]<=9){
            
            mp[word[i]]++;

            if(word[i]!=word[i+1]){
                s+=mp[word[i]]+'0';
                s+=word[i];
                mp[word[i]]=0;

            }else if(mp[word[i]]==9){
               s+=9 + '0';
               mp[word[i]]=0;
              s+=word[i];
            }
        }
        else{
            s+=9 + '0';
            mp[word[i]]=1;
            s+=word[i];
        }   
      }
      return s;
    }
};


/**************************************************************** JAVA ****************************************************************/
//Approach (Simple Simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public String compressedString(String word) {
        StringBuilder comp = new StringBuilder();
        int n = word.length();
        int i = 0;

        while (i < n) {
            int count = 0;
            char ch = word.charAt(i);

            while (i < n && count < 9 && word.charAt(i) == ch) {
                count++;
                i++;
            }

            comp.append(count).append(ch);
        }

        return comp.toString();
    }
}
