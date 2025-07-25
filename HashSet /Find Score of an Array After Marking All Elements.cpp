/*
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements
*/

/************************************************************ C++ ************************************************************/
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    long long findScore(vector<int>& arr) {

        multiset<pair<int,int>>st;

        int n=arr.size();

        if(n==1)return arr[0];

        long long ans=0;

        for(int i=0;i<n;i++){

              st.insert({arr[i],i});
        }


        for(auto u:st){
               
               int index=u.second;

               if(arr[index]!=-1){

                   ans+=u.first;

               if(index>0 && index<n-1){
                     arr[index-1]=-1;
                     arr[index+1]=-1;
                     arr[index]=-1;
                 
               }

               if(index==0){
                 arr[index]=-1;
                 arr[index+1]=-1;
                
               }


               if(index==n-1){
                arr[index]=-1;
                arr[index-1]=-1;
          
               }

               }

             

        }


        return ans;
        
    }
};
