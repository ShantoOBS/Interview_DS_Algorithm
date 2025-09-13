/*
    Company Tags                        : Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, OYO Rooms
    GfG Link                            : https://practice.geeksforgeeks.org/problems/topological-sort/1#
    NOTE: This can also be used to check if the graph contains cycle or not (Please see Line:56 below)
*/


//NOTE : This assumes that, we don't have cycle in the given directed graph. You can simply add few things in the same code to check for cycle also

//T.C : O(V + E)
//S.C : O(V + E)

class Solution {
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int N, vector<int> adj[])  {
	    queue<int> que;
	    vector<int> indegree(N, 0);
	    
	    //1
	    for(int u = 0; u<N; u++) {
	        for(int &v : adj[u]) {
	            indegree[v]++;
	        }
	    }
	    
	    //2. Fill que, indegree with 0
	    for(int i = 0; i<N; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	        }
	    }
	    
	    //3. Simple BFS
	    vector<int> result;
	    while(!que.empty()) {
	        int u = que.front();
	        result.push_back(u);
	        que.pop();
	        
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            
	            if(indegree[v] == 0) {
	                que.push(v);
	            }
	            
	        }
	    }
	    
	    return result;
	}
};
