
/*
    Company Tags  : will be soon
    Leetcode Link : https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=daily-question&envId=2024-09-17
*/

//T.C : o(n)
//S.C : O(n)

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

         vector<string>ans;

         s1+=' ';

         s1+=s2;

         s1+=' ';

         cout<<s1<<endl;

        map<string,int>m;

        string temp="";

        
        for(int i=0;i<s1.length();i++){
          
             if(s1[i]==' '){
               m[temp]++;
               temp="";
             }
             else{
                temp+=s1[i];
             }

        }

        for(auto i:m)
        if(i.second==1)
          ans.push_back(i.first);
       
    

        return ans;
        
    }
};
