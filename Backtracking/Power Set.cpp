/*
  
    Company Tags                : Snapdeal
    GFG Link                    : https://www.geeksforgeeks.org/problems/power-set4302/1
*/


class Solution{
	public:
	int n;
	vector<string>result;
	   
	    void solve(string s,int i,string temp){
	        
	        if(i>=n){
	            if(temp.length()>=1){
	                result.push_back(temp);
	            }
	            return;
	        }
	        
	        temp.push_back(s[i]);
	        solve(s,i+1,temp);
	        temp.pop_back();
	        solve(s,i+1,temp);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    n=s.length();
		    
		    string temp="";
		    
		    solve(s,0,temp);
		    
		    sort(result.begin(),result.end());
		    
		    return result;
		}
};
