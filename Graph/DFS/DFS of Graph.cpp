/*
    Company Tags                : Accolite, Amazon, Samsung, Intuit
    GfG Link                    : https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
*/
//Approach-1 
//T.C :O(v+e)
//S.C :O(v)

  class Solution {
  public:
     vector<int>ans;
     
    void DFS(vector<vector<int>>&adj,int u,vector<bool>&vis){
        
        if(vis[u]==true)return;
        
        vis[u]=true;
        ans.push_back(u);
        
        for(auto v:adj[u]){
            
            if(!vis[v]){
                DFS(adj,v,vis);
            }
        }
    } 
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        vector<bool>visited(adj.size(),false);        
        DFS(adj,0,visited);
       
        return ans;
    }
};
