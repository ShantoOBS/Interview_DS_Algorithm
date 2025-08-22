/*
        Company        : will be soon 
        Leet-Code Link : https://leetcode.com/problems/network-delay-time/description/
*/

//T.C : O((V + E) log V)
//S.C :  O(V+E)

-------------------------------------------------------------------------------- C++ ----------------------------------------------------------------------------------
class Solution {
public:
 int INF=1e9+10;
 int N=1e3+10;

int dijkstra(int source,int n , vector<pair<int,int>>g[]){
    
      vector<int>dis(N,INF);
      vector<int>vis(N,0);
      
      set<pair<int,int>>st;
      
      st.insert({0,source});
      
      dis[source]=0;
  
      
      while(st.size()>0){
          
            auto node=*st.begin();
            
            int v=node.second;
            int w=node.first;
            
            st.erase(st.begin());
            
            if(vis[v])continue;
            
            vis[v]=1;
            
            
            for(auto child:g[v]){
              
              int v_child=child.first;
              int w_child=child.second;
            
            if(dis[v]+w_child<dis[v_child]){
              dis[v_child]=dis[v]+w_child;
              st.insert({dis[v_child],v_child});
            }
     
          }

      }
          
          int ans=0;
          
          for(int i=1;i<=n;i++){
           
             if(dis[i]==INF)return -1;
             ans=max(ans,dis[i]);
          }
            
    return ans;
      
}


int networkDelayTime(vector<vector<int>>& times, int n, int k) {

       vector<pair<int,int>>g[N];

       for(auto vec:times){
         
           g[vec[0]].emplace_back(vec[1],vec[2]);
       }
       
       return dijkstra(k,n,g);

    }


};
