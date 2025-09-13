/*
    Company Tags                     : Flipkart, Amazon, Microsoft, Samsung, MakeMyTrip, Oracle, Adobe
    GFG Link                         : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/

/************************************************ C++ ************************************************/

//T.C : O(V + E)
//S.C : O(V + E)

class Solution {
  public:
    bool dfs(int vertex,vector<int>adj[],vector<bool>&vis,vector<bool>&inRecarsion){
         
         vis[vertex]=true;
         inRecarsion[vertex]=true;
         
        
         
         for(auto child:adj[vertex]){
             
               if(vis[child]==false && dfs(child,adj,vis,inRecarsion))return true;
               else if(inRecarsion[child])return true;
    
         }
         
         inRecarsion[vertex]=false;
         
         return false;
           
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>adj[V+1];
        
        for(int i=0;i<edges.size();i++){
            
              int u=edges[i][0];
              int v=edges[i][1];
              
              adj[u].push_back(v);
             
        }
        
        vector<bool>vis(V+10,false);
        vector<bool>inRecarsion(V+10,false);
        
        for(int i=0;i<V;i++){
            
              if(vis[i]==false && dfs(i,adj,vis,inRecarsion)){
                  
                  return true;
              }
        }
        
        
        return false;
    }
};
