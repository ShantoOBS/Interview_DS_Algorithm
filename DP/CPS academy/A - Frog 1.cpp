/*
 
    Company Tags          : will be soon 
    Leetcode Link         : https://atcoder.jp/contests/dp/tasks/dp_a
*/


/*************************************************************** C++ ******************************************************/
//Approach-1 (Normal Recursion & Memoization )
//T.C : O(n)
//S.C : O(n)


#include <bits/stdc++.h>
using namespace std;

#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);

#define int long long
#define all(v) v.begin(),v.end()
#define vl vector<int>
#define pb emplace_back
#define in(v) for(auto &k:v)cin>>k;

const int mx=1e5+23;

int h[mx],dp[mx];

int n;

int solve(int index){
  
  
       if(index==n)return 0;
       
       if(dp[index]!=-1)return dp[index];
       
       
       int r1=2e9,r2=2e9;
       
       if(index+1<=n)r1=abs(h[index]-h[index+1])+ solve(index+1);
       if(index+2<=n)r2=abs(h[index]-h[index+2])+ solve(index+2);
       
       return dp[index]=min(r1,r2);
       
       
}

inline void solve(){
 
      cin>>n;
     
     for(int i=1;i<=n;i++)cin>>h[i];
     
     memset(dp,-1,sizeof(dp));
     
     
     cout<<solve(1)<<endl;
    
   

} 

// tc : O(n)
// sc : O(n)

int32_t main() {
  
    fastIO;
    
    solve();

    return 0;
}
