/*
    Company Tags                     : Flipkart, Amazon, Microsoft, Samsung, MakeMyTrip, Oracle, Adobe
    GFG Link                         : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

/************************************************ C++ ************************************************/

//T.C : O(V + E)
//S.C : O(V + E)

class Solution {
  public:
    bool bfs(int u,vector<bool>&vis,vector<int>g[]){
        
           queue<pair<int,int>>q;
           
           q.push({u,-1});
           
           
           vis[u]=true;
           
           while(!q.empty()){
               
                 auto t=q.front();
                 
                 q.pop();
                 
                 int child=t.first;
                 int par=t.second;
                 
                 for(auto u:g[child]){
                      
                      if(vis[u] && u==par)continue;
                      if(vis[u])return true;
                      vis[u]=true;
                      q.push({u,child});
                 }
           }
           
            
            return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<int>g[V];
        
        for(int i=0;i<edges.size();i++){
            
              int u=edges[i][0];
              int v=edges[i][1];
              
              g[u].push_back(v);
              g[v].push_back(u);
        }
        
        
        vector<bool>vis(V,false);
        
        for(int i=0;i<edges.size();i++){
            
             if(vis[i]==false){
              if(bfs(i,vis,g))return true;
                 
             }
        }
        
        return false;
        
    }
};
