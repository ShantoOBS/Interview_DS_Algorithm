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


/* Given Q Queries, Q<=1e5

   * In each Query given v
   * Print subtree sum of v number of even number in a subtree of vector 
   
   */

int even[mx];
int sum[mx];
vector<int>adj[mx];


void dfs(int vertex,int par=0){
     
     if(vertex%2==0)even[vertex]++;
     sum[vertex]+=vertex;
     
     for(auto child:adj[vertex]){
       
           if(child==par)continue;
           
           
           dfs(child,vertex);
           sum[vertex]+=sum[child];
           even[vertex]+=even[child];
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
    
   
    for(int i=1;i<=v;i++){
      
      cout<< sum[i]<<" "<< even[i]<<endl;
      
    }
} 

// tc :
// sc :

int32_t main() {
    fastIO;
    
   solve();

    return 0;
}
