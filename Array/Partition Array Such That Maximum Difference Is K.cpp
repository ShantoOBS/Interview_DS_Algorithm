/*     Scroll below to see JAVA code as well    */
/*
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k
*/


/************************************************************ C++ *****************************************************/
//Approach (Using sorting + greedily partitioning)
//T.C : O(n log n )
//S.C : O(1)
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
         
        int n=nums.size() ;
        sort(nums.begin(),nums.end());
        
        int ans=0;

        int i=0;
        while(i<n) {
           
            int j=i;

            while(j<n && nums[j]-nums[i]<=k){
                 j++;
            }
            
            i=j;

            ans++;  
      }

        return ans;

    }
};



/************************************************************ JAVA *****************************************************/
//Approach (Using sorting + greedily partitioning)
//T.C : O(n log n)
//S.C : O(1)
class Solution {
    public int partitionArray(int[] nums, int k) {

        int n=nums.length;

        Arrays.sort(nums);

        int ans=0;

        int i=0;
        while(i<n) {
           
            int j=i;

            while(j<n && nums[j]-nums[i]<=k){
                 j++;
            }
            
            i=j;

            ans++;
              
       }

        return ans;
        
    }
}
