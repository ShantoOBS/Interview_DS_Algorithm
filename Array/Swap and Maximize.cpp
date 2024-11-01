/*
    Company Tags      : will be soon
    Leet-Code Link    : https://www.geeksforgeeks.org/problems/swap-and-maximize5859/1
*/
************************************************************ C++ ************************************************************
// T.C : O(n)
// S.C : O(n)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        
        vector<int>temp;
        
        sort(arr.begin(),arr.end());
        
        int n=arr.size();
        
        long long sum=0;
        
        int i=0;
        int j=n-1;
        
        while(i<=j){
            
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            
            i++;
            j--;
            
        }
        
        for(int i=1;i<n;i++){
            sum+=abs(temp[i]-temp[i-1]);
        }
        
        sum+=abs(temp[n-1]-temp[0]);
        
        return sum;
        
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
