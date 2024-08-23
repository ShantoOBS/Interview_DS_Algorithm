// LeetCode Link: https://leetcode.com/problems/number-complement/description/?envType=daily-question&envId=2024-08-22

//T.C: O(n)
//S.C: O(n)

class Solution {
public:
    string Decimal_to_Binary(int num){

        string temp="";

        while(num){
            temp+=(num%2)+'0';
            num/=2;
        }

        return temp;
    }

    int Binary_to_Decimal(string s){

        int ct=0;
        int ans=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                ans+=pow(2,ct);
            }
            ct++;
        }  

        return ans;



    }
    int findComplement(int num) {

        string s=Decimal_to_Binary(num); //Decimal to Binary Conversion

        for(int i=0;i<s.length();i++){ //1 to 0 and 0 to 1 Conversion

            if(s[i]=='0'){
                s[i]='1';
            }
            else{
                s[i]='0';
            }
        }

        int ans=Binary_to_Decimal(s); // Binary to Decimal Conversion


        return ans;
        
    }
};
