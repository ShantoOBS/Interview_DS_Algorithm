/*     Scroll below to see JAVA code also    */
/*
    Company Tags                : will soon update
    GFG Link                    : https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-with-distinct-elements/1
*/

/******************************************************** C++ ********************************************************/

//Approach - Set
//T.C : O(n)
//S.C : O(n)

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        
        set<int>st;
        
        for(auto i:a)st.insert(i);
        
        for(auto i:b)st.insert(i);
        
        vector<int>ans(st.begin(),st.end());
        
        return ans;
    }
};


