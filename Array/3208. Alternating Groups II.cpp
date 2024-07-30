/*
    
    Company Tags                : will be soon 
    Leetcode Link               : https://leetcode.com/problems/merge-two-sorted-lists/
*/

/************************************************ C++ ************************************************/


class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
           int numFound = 0;
        int i = 0;
        int j = 1;
        int n = colors.size();
        
        while (j < n + k && i < n) {
            int tempJ = j;
            int tempEnd = tempJ % n;
            
          
            while (colors[tempEnd] != colors[(tempEnd - 1 + n) % n] && tempJ < n + k - 1) {
                tempJ++;
                tempEnd = tempJ % n;
            }
            
      
            numFound += max(tempJ - i - k + 1, 0);
            i = tempJ;
            j = i + 1;
        }
        
        return numFound;
        
    }
};
