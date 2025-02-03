/*
    Company Tags                : VMWare, Zoho, Amazon, Microsoft, Snapdeal, D-E-Shaw, FactSet, MakeMyTrip, Teradata, Synopsys, CouponDunia, Cadence India, Monotype Solutions, FreeCharge
    GFG Link                    : https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
*/
/*********************************************************** C++ **************************************************/

class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // code here
        if(node==NULL)return 0;
        
        int ans=0;
        
        queue<Node* > q;
        
        q.push(node);
        
        while(!q.empty()){
            
            int n=q.size();
            
            for(int i=0;i<n;i++){
                
                Node * temp=q.front();
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
                
                q.pop();
                    
            }
            
            ans++;
            
        }
        
        return ans-1;
    }
};
