/*
    Company Tags                : Morgan Stanley, Amazon, Microsoft, Payu, Adobe, Code Brew
    GfG Link                    : https://www.geeksforgeeks.org/problems/implement-atoi/1
*/

-------------------------------------------------------------Java---------------------------------------------------------
//Approach-1 
//T.C :O(n)
//S.C :O(1)

class Solution {
    public int myAtoi(String s) {
        // Your code here\
         int i =0;
        int n = s.length();
        int res =0;
        while(i<n && s.charAt(i)==' '){
            i++;
        }
        
        int sign =1;
        while(i<n && (s.charAt(i)=='+' || s.charAt(i)=='-')){
            sign = (s.charAt(i)=='-') ? -1:1;
            i++;
        }
        
        while(i<n && s.charAt(i)>='0' && s.charAt(i)<='9'){
            int digit = s.charAt(i)-'0';
            
            if(res >(Integer.MAX_VALUE-digit)/10){
                return (sign==1)?Integer.MAX_VALUE :Integer.MIN_VALUE;
            }
            res = res*10+digit;
            i++;
        }
        return res*sign;
    }
}
