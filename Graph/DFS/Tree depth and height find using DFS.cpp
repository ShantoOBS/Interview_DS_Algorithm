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

int depth[mx];
vector<int>adj[mx];
int height[mx];

void dfs(int vertex,int par=0){
     
     
     for(auto child:adj[vertex]){
       
           if(child==par)continue;
           
           depth[child]=depth[vertex]+1;
           dfs(child,vertex);
           height[vertex]=max(height[vertex],height[child]+1);
     }
      
}

inline void solve(){
 
    int v; cin>>v;
    
    
    for(int i=0;i<v;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    dfs(1);
    
    for(int i=1;i<=v;i++)cout<<depth[i]<<" ";
    cout<<endl;
    for(int i=1;i<=v;i++)cout<<height[i]<<" ";
    cout<<endl;
} 

// tc :
// sc :

int32_t main() {
    fastIO;
    
   solve();

    return 0;
}
