
/*
    Company Tags                : will soon update
    GFG Link                    : https://www.geeksforgeeks.org/problems/two-swaps--155623/1
*/
// T.C : O(n)
// S.C : O(n+1)


//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
       int n=arr.size();
       
       
       vector<int>v(n+1);
       
       for(int i=0;i<n;i++){
           v[i+1]=arr[i];
       }
       
       int ct=0;
       
       
       for(int i=1;i<=n;i++){
           
           if(i+1==v[i]){
               i++;
           }
           else{
               swap(v[i],v[v[i]]);
               ct++;
           }
           
           
           if(ct>2)return false;
       }

       return (ct==0 || ct==2);
       
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends
