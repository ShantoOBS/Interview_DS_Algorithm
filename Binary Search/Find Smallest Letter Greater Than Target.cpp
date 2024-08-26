/*
    Company Tags                : LinkedIn
    Leetcode Link               : https://leetcode.com/problems/find-smallest-letter-greater-than-target/
*/

//Approach-1 (Brute Force) - TC : O(n)

//Approach-2 (Using Own Binary Search) - TC : O(log(n))
class Solution {
public:
    
    int binarySearch(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n-1;
        
        int position = n;
        
        while(l <= r) {
            
            int mid = l + (r-l)/2;
            
            if(letters[mid] > target) {
                position = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
            
        }
        
        return position;
    }
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int idx = binarySearch(letters, target);
        
        if(idx == letters.size())
            return letters[0];
        
        return letters[idx];
        
    }
};

