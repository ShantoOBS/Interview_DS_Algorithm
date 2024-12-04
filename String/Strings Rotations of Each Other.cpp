/*
    Company Tags                : Oracle, Adobe
    GFG Link                    : https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1
*/
/**************************************************************** C++ ****************************************************************/
//Approach 
//T.C : O(n)
//S.C : O(1)

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        return ((s1+s1).find(s2)!=string::npos);
    }
};
