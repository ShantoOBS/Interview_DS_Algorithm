/*     Scroll below to see JAVA code also    */
/*
    Company Tags                : Will update soon
    Leetcode Link               : https://www.geeksforgeeks.org/problems/remove-duplicates-in-small-prime-array/1
*/
/************************************************************ C++ ************************************************/
//Approach-1 (Using map)
//T.C : O(n)
//S.C : O(n)

class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        
        vector<int>ans;
        
        unordered_map<int,int>mp;
        
        
        for(auto i:arr){
            
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
                mp[i]++;
            }
        }
        
        return ans;
    }
};


/************************************************************ JAVA ************************************************/
//Approach-1 (Using map)
//T.C : O(n)
//S.C : O(n)

class Solution {
    ArrayList<Integer> removeDuplicate(int arr[]) {
        // code here
        
       ArrayList<Integer> ans = new ArrayList<Integer>();
       
       HashMap<Integer,Integer> mp = new HashMap<Integer,Integer>();
        
        
        for(int i:arr){
            
            if(mp.get(i)==null){
                ans.add(i);
                mp.put(i,1);
            }
        }
        
        return ans;
    }
}
