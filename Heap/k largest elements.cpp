/*
    Company Tags                : Amazon, Microsoft, Samsung, Walmart, Google
    GFG Link                    : https://www.geeksforgeeks.org/problems/k-largest-elements4206/1
*/
/************************************************************ C++ ************************************************/
//Approach-1 
//T.C : O(n))
//S.C : O(n)
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        
    priority_queue<int>pq;
        for(auto it: arr)pq.push(it);
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
