/*
    Company Tags                : Facebook, Samsung, Microsoft, Flipkart
    GfG Link                    : https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1
*/

//Time Complexity: O(V + E)
//Space Complexity: O(V)

class Solution {
  public:
    // Function to detect cycle using DSU in an undirected graph.
    int Find(int u,vector<int>&parent){
         if(u==parent[u])return u;
         return parent[u]=Find(parent[u],parent);
    }
    
    bool Union(int x,int y,vector<int>&parent,vector<int>&rank){
        
        int x_parent=Find(x,parent);
        int y_parent=Find(y,parent);
        
        if(x_parent==y_parent)return true;
        
        
        if(rank[x_parent]==rank[y_parent]){
             parent[x_parent]=y_parent;
             rank[y_parent]+=1;
        }
        else if(rank[x_parent]<rank[y_parent]){
             parent[x_parent]=y_parent;
        }
        else parent[y_parent]=x_parent;
        
        return false;
        
        
    }
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>parent(V),rank(V);
        
        for(int i=0;i<V;i++){
             parent[i]=i;
             rank[i]=0;
        }
        
        for(int u=0;u<V;u++){
            
              for(auto v:adj[u]){
                  
                   if(u<v && Union(u,v,parent,rank))return 1;
              }
        }
        
        return 0;
        
    }
};
