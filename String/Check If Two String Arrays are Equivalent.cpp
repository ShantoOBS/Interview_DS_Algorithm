/*
    Company Tags                : Goldman Sachs
    Leetcode Link               : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
*/

/************************************************************** C++ **************************************************************/

//T.C : O(n*k) - n and m = length of word1 and word2 respectively
//S.C : O(n+k)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "";
        string s2 = "";
        
        for(string s:word1)
            s1 += s;
        
        for(string s:word2)
            s2 += s;
        
        return s1==s2;
    }
};





/************************************************************** JAVA **************************************************************/

//T.C : O(n*k) - n and m = length of word1 and word2 respectively
//S.C : O(n+k)
public class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();

        for (String s : word1) {
            s1.append(s);
        }

        for (String s : word2) {
            s2.append(s);
        }

        return s1.toString().equals(s2.toString());
    }
}
