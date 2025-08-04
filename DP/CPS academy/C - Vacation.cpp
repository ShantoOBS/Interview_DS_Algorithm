/*
 
    Company Tags          : will be soon 
    Leetcode Link         : https://atcoder.jp/contests/dp/tasks/dp_c
*/


/*************************************************************** C++ ******************************************************/
//Approach-1 (Normal Recursion & Memoization )
// T.C : O(n)
// S.C : O(n)


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

int v[mx][4],dp[mx][4];

int n;

int solve(int index,int pre){
  
   
    if(index>n)return  0;
    
    
    if(dp[index][pre]!=-1)return dp[index][pre];
    
    int result=0;
    
    for(int j=1;j<=3;j++)if(j!=pre)result=max(result,v[index][j]+solve(index+1,j));
    
  
    return dp[index][pre]=result;
     
       
       
}

inline void solve(){
 
      
      cin>>n;
      
      for(int i=1;i<=n;i++){
         cin>>v[i][1]>>v[i][2]>>v[i][3];
      }
      
      memset(dp,-1,sizeof(dp));
      
      cout<<solve(1,0)<<endl;
      
    
   

} 

// tc : O(n)
// sc : O(n)

int32_t main() {
  
    fastIO;
    
    solve();

    return 0;
}
