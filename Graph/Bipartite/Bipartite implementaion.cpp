/* Quesion Link : https://vjudge.net/problem/uva-10004
   T.C : O(V + E)
   S.C : O(V + E)
*/


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

const int mx=500;

vector<vector<int>>adj(mx);

vector<int>col(mx,-1);



bool isBicoloring(int s){
  
      for(int i=0;i<mx;i++)col[i]=-1;
      
      queue<int>q;
      
      col[s]=1;
      
      q.push(s);
      
      
      while(!q.empty()){
         
          int u=q.front();
          q.pop();
          
          for(auto v:adj[u]){
            
               if(col[v]==-1){
                  
                    if(col[u]==1)col[v]=2;
                    else col[v]=1;
                    
                    q.push(v);
               }
               else if(col[v]==col[u])return false;
          }
      }
      
      return true;
         
}


inline void solve(){
 
   int n; 
   
   while(cin>>n){
     
       if(n==0)break;
       
       for(int i=0;i<n;i++)adj[i].clear();
       
       int m; cin>>m;
       
       for(int i=0;i<m;i++){
         
          int u,v; cin>>u>>v;
          
          adj[u].pb(v);
          adj[v].pb(u);
          
       }
       
       
       if(isBicoloring(0)){
           cout<<"BICOLORABLE."<<endl;
       }
       else{
          cout<<"NOT BICOLORABLE."<<endl;
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
