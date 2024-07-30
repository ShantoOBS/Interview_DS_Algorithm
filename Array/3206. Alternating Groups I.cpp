
/*
    
    Company Tags                : will be soon 
    Leetcode Link               : https://leetcode.com/problems/alternating-groups-i/description/
*/

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c) {
        
        c.insert(c.end(), c.begin(), c.begin() + 2);
        
         int ans=0;
        
        for(int i=0;i<c.size()-2;i++){
            if( c[i]!= c[i+1] && c[i]==c[i+2]){
                ans++;
            }
        }
        
        
        return ans;
        
    }
};
