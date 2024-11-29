/*
    Company Tags                : Amazon, Microsoft, Facebook 
    GfG Link                    : https://www.geeksforgeeks.org/problems/add-binary-strings3805/1
*/
------------------------------------------------------------- C++ ---------------------------------------------------------
//Approach-1 
//T.C :O(n)
//S.C :O(n)

class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
       
         int iz = 0 , jz = 0;
         
        int i = s1.size()-1, j = s2.size()-1 ,carry = 0;
        
        string res ="";
        
        while(s1[iz]=='0') iz++;
        while(s2[jz]=='0') jz++;
        
        while(i>=iz || j>=jz || carry){
            int n1 = 0 , n2 =0;
            if(i>=iz) n1 =s1[i] - '0';
            if(j>=jz) n2 =s2[j] - '0';
            int sum = n1 + n2 + carry;
            int digit = sum%2;
            carry = sum/2;
           res += ('0'+digit);
            i--;
            j--;
        }
        
        if(res.size()==0) return "0";
        
        reverse(res.begin(),res.end());
        
        return res;

    }
};
