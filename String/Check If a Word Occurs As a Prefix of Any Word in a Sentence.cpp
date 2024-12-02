/*
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/?envType=daily-question&envId=2024-12-02
*/
/************************************************************ C++ ************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        int n=sentence.size();

        if(sentence.find(searchWord)== string::npos){
            return -1;
        }

      
       sentence.push_back(' ');

        vector<string>v;
        
        string temp="";

       for(int i=0;i<n+1;i++){
          
          if(sentence[i]==' '){
            v.push_back(temp);
            temp="";
          }
          else
          temp+=sentence[i];
       }

       //for(auto s:v)cout<<s<<endl;
       int cnt=0;
       for(auto s:v){
          cnt++;
         
          if(s.find(searchWord)!=string::npos && s.find(searchWord)==0 )
             return cnt; 
             
       }

       return -1;

    }
};
