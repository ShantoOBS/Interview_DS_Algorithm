/*

    Company Tags                : LinkedIn
    Leetcode Link               : https://leetcode.com/problems/find-smallest-letter-greater-than-target/
*/

//Approach (Using C++ STL upper_bound (binary search internally)) - TC : O(log(n))
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int idx = upper_bound(begin(letters), end(letters), target) - begin(letters);
        
        if(idx == letters.size())
            return letters[0];
        
        return letters[idx];
    }
};
