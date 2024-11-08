/*
    Company Tags                : Google
    GFG Link                    : https://www.geeksforgeeks.org/problems/minimum-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it--170645/1
*/
/******************************************************** C++ ********************************************************/
//Approach - 1
//T.C : O(n)
//S.C : O(1)

class Solution {
  public:
    int minRepeats(string& A, string& B) {
        // code here
        
       string rep = A;
        int cnt=1;
        while(A.size()<B.size()){
            A+=rep;
            cnt++;
        }
       
        if(A.find(B)!=-1) return cnt;
         A+=rep;
         cnt++;
        if(A.find(B)!=-1) return cnt;
        return -1;
    }
};
