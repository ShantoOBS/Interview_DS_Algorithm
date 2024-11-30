/*
    Company Tags                : will be soon
    GfG Link                    : https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1
*/
------------------------------------------------------------- C++ ---------------------------------------------------------
//Approach 
//T.C : O(V+E) where E is the number of edges in graph.
//S.C : O(V)

class Solution {
public:
    void DFS(vector<int>adj[],int u,vector<bool>&vis){
        
        if(vis[u]==true)return;
        
        vis[u]=true;
        
        for(auto v:adj[u]){
            
            if(!vis[v])DFS(adj,v,vis);
        }
        
    }
    bool is_conneted(int V,vector<int>adj[]){
        
       int nonZeroIndex=-1;
       
       for(int i=0;i<V;i++){
           
           if(adj[i].size()!=0){
               nonZeroIndex=i;
               break;
           }
       }
       
       vector<bool>visited(V,false);
       
       DFS(adj,nonZeroIndex,visited);
       
       for(int i=0;i<V;i++){
           
           if(visited[i]==false && adj[i].size()>0)return false;
       }
       
       return true;
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	   
	   if(is_conneted(V,adj)==false)return 0; 
	  
	    int odd=0;
	    
	   for(int i=0;i<V;i++){
	       
	       if(adj[i].size()%2!=0)odd++;
	   }
	   
	   if(odd>2)return 0;
	   
	   if(odd==2)return 1;
	   
	   return 2;
	    
	}
};
