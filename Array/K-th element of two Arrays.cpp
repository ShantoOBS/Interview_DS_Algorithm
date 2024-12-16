/*
    Company Tags                : Flipkart, Microsoft
    GFG Link                    : https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
*/
/************************************************************ C++ ************************************************/

//T.C : O(n)
//S.C : O(1)

class Solution {
  public:
   int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int i=0, j=0, n=a.size(), m=b.size(), res;
        while( i<n && j<m ) {
            if( a[i] <= b[j] ) res = a[i++];
            else res = b[j++];
            if( !--k ) return res;
        }
        while( i<n ) {
            res = a[i++];
            if( !--k ) return res;
        }
        while( j<m ) {
            res = b[j++];
            if( !--k ) return res;
        }
        return -1;
    }
};
