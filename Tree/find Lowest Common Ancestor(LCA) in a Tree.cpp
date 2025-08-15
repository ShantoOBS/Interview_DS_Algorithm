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


/* How to find Lowest Common Ancestor(LCA) in a Tree 
   
 */


vector<int>adj[mx];
int p[mx];



void dfs(int vertex,int par=-1){
     
     
     p[vertex]=par;
     
     for(auto child:adj[vertex]){
       
           if(child==par)continue;
           dfs(child,vertex);
           
     }
      
}

vl get_path(int vertex){
  
     vl ans;
     
     while(vertex!=-1){
       
         ans.pb(vertex);
         vertex=p[vertex];
     }
     
     reverse(all(ans));
     
     return ans;
}

inline void solve(){
 
    int v; cin>>v;
    
    
    for(int i=0;i<v-1;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1);
    
    int a,b; cin>>a>>b;
    
    vl temp1=get_path(a);
    vl temp2=get_path(b);
    
    
    int ans=0;
    for(int i=0;i<min(temp1.size(),temp2.size());i++){
        if(temp1[i]==temp2[i]){
          ans=temp1[i];
        }
        else break;
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
