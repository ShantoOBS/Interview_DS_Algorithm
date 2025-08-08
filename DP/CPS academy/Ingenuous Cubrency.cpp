// Problem Link : https://vjudge.net/problem/uva-11137


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

const int mx=1e4+123;

int dp[22][mx];

int coin[22];


int fun(int i,int n){
  
     if(i==21 || n==0)return n==0;
     
     if(dp[i][n]!=-1)return dp[i][n];
     
     
     int ret=0;
     
     
     for(int j=0;j<=n;j++){
       
         if(n-(j*coin[i])>=0)ret+=fun(i+1,n-(j*coin[i]));
         else break;
     }
     
     
     return dp[i][n]=ret;
}



inline void solve(){
  
  
      for(int i=1;i<=21;i++)coin[i-1]=i*i*i;
      
      memset(dp,-1,sizeof(dp));
      
      int n; 
      
      while(cin>>n){
         cout<<fun(0,n)<<endl;
      }
      
     
    
} 

// tc :
// sc :

int32_t main() {
    fastIO;
    
    solve();

    return 0;
}
