/*
    Company Tags      : will be soon
    Leet-Code Link    : https://leetcode.com/problems/circular-sentence/description/?envType=daily-question&envId=2024-11-02
*/
************************************************************ C++ ************************************************************
// T.C : O(n)
// S.C : O(n)

class Solution {
public:
    bool isCircularSentence(string sentence) {

          
             vector<string>v;

             sentence+=' ';

             int n=sentence.size();

             string s="";
          
            for(int i=0;i<n;i++){

                if(sentence[i]==' '){
                    
                    if(v.empty()){
                        v.push_back(s);
                    }
                    else{

                        string temp=v.back();

                        int m=temp.size();

                        if(temp.back()==s[0]){
                            v.push_back(s);
                        }
                        else return false;
                    }

                    s="";
                }
                else{

                    s+=sentence[i];
                }
            }
            
            if(v[0][0]!=v.back().back())return false;

            return true;
        
    }
};
