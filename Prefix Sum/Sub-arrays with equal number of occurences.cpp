/*
    Company Tags                : Will update soon
    GFG Link                    : https://www.geeksforgeeks.org/problems/sub-arrays-with-equal-number-of-occurences3901/1
*/
/************************************************************ C++ ************************************************/
//Approach 
//T.C : O(n)
//S.C : O(n)


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        
        unordered_map<int,int>mp;
        
        int curr=0,ans=0;
        
        mp[0]=1;
        
        for(auto i:arr){
            
            if(i==x)curr++;
            else if(i==y)curr--;
            
            
            ans+=mp[curr];
            mp[curr]++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends
