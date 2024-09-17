/*
    Company Tags                - MICROSOFT
    Leetcode Link               - https://leetcode.com/problems/minimum-cost-to-make-array-equal/
*/

// T.C : O(n (long n + long r) )
// S.C : O(n)

Appoach -(without using function)

typedef long long ll;
class Solution {
public:

    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        ll n=nums.size();

         vector<pair<ll,ll>>v;

         for(ll i=0;i<nums.size();i++){
            v.emplace_back(nums[i],cost[i]);
         }

         sort(v.begin(),v.end());

         ll l=v[0].first;

         ll r=v[n-1].first;

         ll ans=LLONG_MAX;

         while(l<=r){

            ll mid= l+(r-l) /2;

            ll cal_mid=0;

            ll cal_mid_plus=0;

            for(ll i=0;i<n;i++){
                cal_mid+=abs(v[i].first-mid)*v[i].second; 
            }

             for(ll i=0;i<n;i++){
                cal_mid_plus+=abs(v[i].first-(mid+1))*v[i].second; 
            }

            if(cal_mid<=cal_mid_plus){

                ans=min(ans,cal_mid);
                r=mid-1;
            }
            else{
                ans=min(ans,cal_mid_plus);
                l=mid+1;
            }

            


         }


         return ans;

    }
};


Appoach -(using function)

class Solution {
public:
    typedef long long ll;
    
    ll getCost(vector<int>& nums, vector<int>& cost, int target) {
        ll result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            result += (ll) abs(nums[i] - target) * cost[i];
        }
        return result;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        ll answer = INT_MAX;
        
        int left = *min_element(nums.begin(), nums.end());  //1
        int right = *max_element(nums.begin(), nums.end()); //5
        
        while (left <= right) {
            int mid = left + (right-left)/2;
            
            ll cost1 = getCost(nums, cost, mid);
            ll cost2 = getCost(nums, cost, mid + 1);
            
            answer = min(cost1, cost2);
            if (cost1 > cost2)
                left = mid + 1;
            else
                right = mid-1;
        }
        return answer == INT_MAX ? 0 : answer;
    } 
};
