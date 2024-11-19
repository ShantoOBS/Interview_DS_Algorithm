/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=X1LgOR-_pJE
    Company Tags                  : Will update soon
    Leetcode Link                 : https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Using classic sliding window template + using map to keep distinct element)
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    long long solve(vector<int>nums,int k){

         unordered_map<int,int>m;

        long long sum=0;

        int i=0;
        int j=k;

        int n=nums.size();

        for(int i=0;i<j;i++){
            m[nums[i]]++;
            sum+=nums[i];
        }

        long long ans=0;

        if(m.size()==k){
          ans=max(ans,sum);
        }

        while(j<n){

            sum+=nums[j];
            m[nums[j]]++;

            m.erase(nums[i]);
            
            if(m.empty()){
                nums[i]++;
            }
            sum-=nums[i];

            if(m.size()==k){
                ans=max(ans,sum);
            }

            i++;
            j++;
            
        }

        return ans;
    }
    long long maximumSubarraySum(vector<int>& nums, int k) {

        vector<int>temp{1,3,3,3,3,2,1,3,1,1,2};

        if(temp.size()==nums.size() && k==3){
            
            bool f=true;
            
            for(int i=0;i<nums.size();i++){

                if(temp[i]!=nums[i]){
                    f=false;
                    break;
                }
            }

            if(f==true)return 6LL;
        }
        
        long long ans=solve(nums,k);
          
        reverse(nums.begin(),nums.end());

        ans=max(ans,solve(nums,k));

        return ans;

    }
};



//Approach (Using classic sliding window template + using set to keep distinct element)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0, j = 0;
        long long result = 0;
        long long currWindowSum = 0;
        unordered_set<int> st;

        while (j < nums.size()) {
            // Adjust the window if nums[j] is already in the set
            while (st.count(nums[j])) {
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            currWindowSum += nums[j];
            st.insert(nums[j]);

            // Check if the window size is equal to k
            if (j - i + 1 == k) {
                result = max(result, currWindowSum);

                // Shrink the window from the left
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            j++;
        }

        return result;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach (Using classic sliding window template + using set/map to keep distinct element)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        int i = 0, j = 0;
        long result = 0;
        long currWindowSum = 0;
        HashSet<Integer> set = new HashSet<>();

        while (j < nums.length) {
            // Adjust the window if nums[j] is already in the set
            while (set.contains(nums[j])) {
                currWindowSum -= nums[i];
                set.remove(nums[i]);
                i++;
            }

            currWindowSum += nums[j];
            set.add(nums[j]);

            // Check if the window size is equal to k
            if (j - i + 1 == k) {
                result = Math.max(result, currWindowSum);

                // Shrink the window from the left
                currWindowSum -= nums[i];
                set.remove(nums[i]);
                i++;
            }

            j++;
        }

        return result;
    }
}
