class Solution {
public:
    int minOperations(vector<string>& l) {

          int ans=0;

          for(int i=0;i<l.size();i++){
             
           
            if(l[i]=="../" && ans>0)  ans--;
            
            if(l[i] !="./"  &&  l[i] !="../")ans++;;

            
           
          }

          return ans;
        
    }
};
