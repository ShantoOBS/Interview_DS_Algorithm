/*
  
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/merge-intervals/description/
*/

T.C. - O(n)
S.C. - O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
          
          vector<vector<int>>ans;

          sort(intervals.begin(),intervals.end());
          
          int n=intervals.size();


          int i=0;

          while(i<n){

                int mini=intervals[i][0];
                int maxi=intervals[i][1];

                int j=i;

                while(j<n-1 && intervals[j+1][0]<=maxi){
                     maxi=max(maxi,intervals[j+1][1]);
                     j++;
                    
                }

                ans.push_back({mini,maxi});

                i=j+1;
          }
        

          return ans;
    }
};
