/*

    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/description/?envType=daily-question&envId=2025-09-02
*/


/********************************************************************** C++ **********************************************************************/
//Approach  (Sliding Window)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
    bool check(vector<int>v1,vector<int>v2,vector<vector<int>>&p){
          
             int x1=v1[0],y1=v1[1];
             int x2=v2[0],y2=v2[1];

             int maxix=max(x1,x2);
             int minix=min(x1,x2);

             int maxiy=max(y1,y2);
             int miniy=min(y1,y2);

            
            for(auto u:p){

                  if(u==v1 || u==v2)continue;

                  else{
                      
                      int currx=u[0],curry=u[1];

                      if( (minix<=currx && currx<=maxix ) && (miniy<=curry && curry<=maxiy) ){
                            
                          return false;
                      }


                  }
            }

            return true;
            
    }
    int numberOfPairs(vector<vector<int>>& points) {

        int n=points.size();

        int ans=0;

        for(auto &u:points)reverse(u.begin(),u.end());

        sort(points.rbegin(),points.rend());

        for(auto &u:points)reverse(u.begin(),u.end());


         for(int i=0;i<n;i++){

               
                 for(int j=i+1;j<n;j++){

                 if(points[j][0]<points[i][0] && points[j][1]<points[i][1])continue;
         
                  if(check(points[i],points[j],points)){
                     ans++;
                     }

                  
                        
                 }
         }
        

          
    

          return ans;

        
    }
};
