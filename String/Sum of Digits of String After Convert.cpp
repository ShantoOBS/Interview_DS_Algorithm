
// Leet-Code Link : https://leetcode.com/problems/sum-of-digits-of-string-after-convert/?envType=daily-question&envId=2024-09-03

//T.C : O(k*n)
//S.C : O(n)

class Solution {
public:
    int getLucky(string s, int k) {

        map<char,int>m;

        for(int i=0;i<26;i++){
               m['a'+i]=i+1;
        }

        string temp="";

        for(int i=0;i<s.length();i++){
            temp+=to_string(m[s[i]]);
        }
        int sum=0;
        while(k--){
           
            sum=0;

           for(int i=0;i<temp.length();i++){
              sum+=temp[i]-'0';
           }

           temp=to_string(sum);

        }


      // cout<<temp<<endl;

        return sum;
        
    }
};
