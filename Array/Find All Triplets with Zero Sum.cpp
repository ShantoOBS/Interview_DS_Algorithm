/*     Scroll below to see JAVA code also    */
/*
    Company Tags                : will update soon
    GFG Link                    : https://www.geeksforgeeks.org/problems/find-all-triplets-with-zero-sum/1
*/
/**************************************************************** C++ ****************************************************************/
//Approach (Simple Simulation)
//T.C : O(n^3)
//S.C : O(1)


class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        
        int n=arr.size();
        
        vector<vector<int>>ans;
        
        
        for(int i=0;i<n;i++){
            
           for(int s=i+1;s<n;s++){
               
                for(int e=s+1;e<n;e++){
                    
                   if(arr[i] + arr[s] + arr[e] ==0 ){
                    ans.push_back({i,s,e});
                   }
                }
            }
                
        }
        
        return ans;
    }
};


/**************************************************************** JAVA ****************************************************************/
//Approach (Simple Simulation)
//T.C : O(n^3)
//S.C : O(1)

class Solution {
    public List<List<Integer>> findTriplets(int[] arr) {
        // Your code here
        List<List<Integer>>res=new ArrayList<>();
        
        int n=arr.length;
        
        
        for(int i=0;i<n-2;i++){
            
            for(int j=i+1;j<n-1;j++){
                
                 for(int k=j+1;k<n;k++){
                     
                     if(arr[i] + arr[j] + arr[k] == 0 ){
                       List<Integer> ans=new ArrayList<>();
                        ans.add(i);
                        ans.add(j);
                        ans.add(k);
                        res.add(ans);
                     }
                 }
            }
        }
        
        return res;
    }
}

