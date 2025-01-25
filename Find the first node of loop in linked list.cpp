/*
    Company Tags                : will soon update
    GFG Link                   : https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1
*/
/******************************************************** C++ ********************************************************/
//Approach-1 
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        
        Node * slow=head;
        Node * fast=head;
        
        while(fast->next && slow){
            
            slow=slow->next;
            fast=fast->next->next;
            
            if(fast==NULL)return NULL;
            
            if(slow==fast){
                Node * h=head;
                
                while(h!=fast){
                    fast=fast->next;
                    h=h->next;
                }
                return h;
            }
            
        }
        
        return NULL;
    }
};
