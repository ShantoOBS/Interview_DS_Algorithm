/*
 
    Company Tags          : will be soon 
    Leetcode Link         : https://atcoder.jp/contests/dp/tasks/dp_d
*/


/*************************************************************** C++ ******************************************************/
//Approach-1 (Normal Recursion & Memoization )
//T.C : O(n*S) size of weight 
//S.C : O(n*S)


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

const int mx=1e5+123;

int dp[123][mx];

int w[123],p[123];

int n,s;

int solve(int i,int curr){
  
     if(i>n)return 0;
     
     if(dp[i][curr]!=-1)return dp[i][curr];
     
     
     int ans1=0,ans2=0;
     
     if(w[i]+curr<=s)ans1=p[i]+solve(i+1,w[i]+curr);
     
     ans2=solve(i+1,curr);
     
     
     return dp[i][curr]=max(ans1,ans2);
}

inline void solve(){
 
      
      cin>>n>>s;
      
      for(int i=1;i<=n;i++){
        
          cin>>w[i]>>p[i];
      }
    
     memset(dp,-1,sizeof(dp));
     
     cout<<solve(1,0)<<endl;
     
     
   

} 

// tc : O(n * s)
// sc : O(n * s)

int32_t main() {
  
    fastIO;
    
    solve();

    return 0;
}
