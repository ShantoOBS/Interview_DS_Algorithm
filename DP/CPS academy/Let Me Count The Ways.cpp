// Problem Link : https://vjudge.net/problem/uva-357

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

const int mx=3e4+123;

int dp[6][mx];

int coin[]={1,5,10,25,50};


int fun(int i,int n){
  
     if(i==5 || n==0)return n==0;
     
     if(dp[i][n]!=-1)return dp[i][n];
     
     
     int ret=0;
     
     
     for(int j=0;j<=n;j++){
       
         if(n-(j*coin[i])>=0)ret+=fun(i+1,n-(j*coin[i]));
         else break;
     }
     
     
     return dp[i][n]=ret;
}



inline void solve(){
 
      memset(dp,-1,sizeof(dp));
      
      int n; 
      
      while(cin>>n){
          
       
        
          int x=fun(0,n);
          
          if(x==1){
            
             cout<<"There is only "<<x<<" way to produce "<<n<<" cents change."<<endl;
          }
          else{
             cout<<"There are "<<x<<" ways to produce "<<n<<" cents change."<<endl;

          }
      }
      
} 

// tc :
// sc :

int32_t main() {
    fastIO;
    
    solve();

    return 0;
}
