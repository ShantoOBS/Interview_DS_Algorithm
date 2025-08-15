/*
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11

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

const int mx=1e5+32;


/*
   * Print diameter of a tree
   
*/


vector<int>adj[mx];
int depth[mx];


void dfs(int vertex,int par=-1){
     
     
     for(auto child:adj[vertex]){
       
           if(child==par)continue;
           depth[child]=depth[vertex]+1;
           dfs(child,vertex);
           
     }
      
}

inline void solve(){
 
    int v; cin>>v;
    
    
    for(int i=0;i<v-1;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    dfs(1);
    
    int max_node=-1;
    int max_depth=0;
    
    for(int i=1;i<=v;i++){
      
         if(max_depth<depth[i]){
            max_depth=depth[i];
            max_node=i;
         }
         
         depth[i]=0;
    }
    
    dfs(max_node);
    
    
    int ans=0;
    
    for(int i=1;i<=v;i++){
       ans=max(ans,depth[i]);
    }
  
   cout<<ans<<endl;    
   
   
} 

// tc :
// sc :

int32_t main() {
    fastIO;
    
   solve();

    return 0;
}
