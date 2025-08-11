/*
    Company Tags                     : Flipkart, Amazon, Microsoft, Samsung, MakeMyTrip, Oracle, Adobe
    GFG Link                         : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

/************************************************ C++ ************************************************/

//T.C : O(V + E)
//S.C : O(V + E)

class Solution {
  public:
    bool dfs(int vertex,vector<int>adj[],vector<bool>&vis,int p){
         
         vis[vertex]=true;
         
         bool is_cycle=false;
         
         for(auto child:adj[vertex]){
             
               if(vis[child] && child==p)continue;
               if(vis[child])return true;
               
               is_cycle|=dfs(child,adj,vis,vertex);
         }
         
         return is_cycle;
           
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>adj[V+1];
        
        for(int i=0;i<edges.size();i++){
            
              int u=edges[i][0];
              int v=edges[i][1];
              
              adj[u].push_back(v);
              adj[v].push_back(u);
        }
        
        vector<bool>vis(V+10,false);
        
        for(int i=0;i<V;i++){
            
              if(vis[i]==false){
                  
                   if(dfs(i,adj,vis,-1))return true;
              }
        }
        
        
        return false;
        
    }
};
