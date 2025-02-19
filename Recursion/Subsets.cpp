/*                                       Scroll down to see JAVA code also                                      /*
/*
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/subsets/
*/

//NOTE : 
//-------- This is basically we are doing backtracking using Recursion. (I told you, Recursion is the father of many topics)




/************************************************************ C++ ************************************************************/
//Approach-1
//T.C : O(2^n)
//S.C :  O(2^n*length of each subset) to store each subset
//       The recursion stack space complexity is O(N) , the maximum depth of the recursion is N, where N is the length of the input array.
class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int idx, vector<int>& temp) {
        if(idx >= nums.size()) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums, idx+1, temp);
        temp.pop_back();
        solve(nums, idx+1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;

        solve(nums, 0, temp);

        return result;
    }
};


//Approach-1
//T.C : O(2^n)
//S.C :  O(2^n*length of each subset) to store each subset

class Solution {
public:
    
    vector<vector<int>>result;

    void solve(vector<int>&nums,vector<int>subset,int index){
        
        result.push_back(subset);

        for(int i=index;i<nums.size();i++){
           
            subset.push_back(nums[i]);

            solve(nums,subset,i+1);

            subset.pop_back();

        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {


        vector<int>temp;
        solve(nums,temp,0);

        sort(result.begin(),result.end());

        return result;
        
    }
};




/************************************************************ JAVA ************************************************************/
//Approach-1
//T.C : O(2^n)
//S.C :  O(2^n*length of each subset) to store each subset
//       The recursion stack space complexity is O(N) , the maximum depth of the recursion is N, where N is the length of the input array.
public class Solution {
    private List<List<Integer>> result = new ArrayList<>();

    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> temp = new ArrayList<>();
        solve(nums, 0, temp);
        return result;
    }

    private void solve(int[] nums, int idx, List<Integer> temp) {
        if (idx >= nums.length) {
            result.add(new ArrayList<>(temp));
            return;
        }

        temp.add(nums[idx]);
        solve(nums, idx + 1, temp);
        temp.remove(temp.size() - 1);
        solve(nums, idx + 1, temp);
    }
}
