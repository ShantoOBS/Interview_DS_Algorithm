/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/kth-distinct-string-in-an-array/description/?envType=daily-question&envId=2024-08-05
*/

/************************************************************** C++ **************************************************************/

//T.C : O(n*k) - n and m = length of word1 and word2 respectively
//S.C : O(n+k)


class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {

         unordered_map<string, bool> map;
        int count = 0;

        // Count occurrences of each string
        for (const string& item : arr) {
            if (map.find(item) != map.end()) {
                map[item] = false;  // Mark as not distinct
            } else {
                map[item] = true;   // Mark as distinct
            }
        }

        // Find the k-th distinct string
        for (const string& item : arr) {
            if (map[item]) {  // Check if it's distinct
                count++;
                if (count == k) {
                    return item;
                }
            }
        }

        return "";  // Return empty string if not found
    }
        
    
};
