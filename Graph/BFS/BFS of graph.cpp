/*
    Company Tags                : Flipkart, Amazon, Microsoft, Samsung, Ola Cabs, Adobe, SAP Labs
    GfG Link                    : https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/
//Approach-1 
//T.C :O(v+e)
//S.C :O(v)

class Solution {
  public:
    vector<int>ans;
    
    void BFS(vector<vector<int>>&adj,int u,vector<bool>&vis){
        
        queue<int>q;
        q.push(u);
        vis[u]=true;
        ans.push_back(u);
      
        while(!q.empty()){
            
            int v=q.front();
            q.pop();
            
            
            for(auto i:adj[v]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=true;
                    ans.push_back(i);
                }
            }
        }
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        
        vector<bool>vis(adj.size(),false);
        
        BFS(adj,0,vis);
        
        return ans;
    }
};
