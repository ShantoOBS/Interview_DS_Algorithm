/*
    Company Tags                : will update later
    GFG-Link                    : https://www.geeksforgeeks.org/problems/triplet-family/1
*/
/****************************************************** C++ *********************************************/
//Approach - Simple travarsal
//T.C : O(n^2)
//S.C : O(n)



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        
        sort(arr.begin(),arr.end());
        
        
        unordered_map<int,int>mp;
        
        for(auto i:arr){
            mp[i]++;
        }
        
        for(int i=0;i<arr.size();i++){
            
            for(int j=i+1;j<arr.size();j++){
                
                if( mp[arr[i]+arr[j] ]){
                    return true;
                }
            }
        }
        
        return false;
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
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
