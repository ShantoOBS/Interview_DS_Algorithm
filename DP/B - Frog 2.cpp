/*
 
    Company Tags          : will be soon 
    Leetcode Link         : https://atcoder.jp/contests/dp/tasks/dp_b
*/


/*************************************************************** C++ ******************************************************/
//Approach-1 (Normal Recursion & Memoization )
//T.C : O(n)
//S.C : O(n*k)



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

int n,k;

int solve(int index){
  
  
       if(index==n)return 0;
       
       if(dp[index]!=-1)return dp[index];
       
       
       int r=LLONG_MAX;
       
       for(int i=1;i<=k;i++){
         
          if(index+i<=n)r=min(abs(h[index]-h[index+i])+solve(index+i),r);
       }
       
       
       return dp[index]=r;
       
       
}

inline void solve(){
 
      cin>>n>>k;
     
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
