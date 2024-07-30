/*
      
      Company Tags                : Paytm, VMWare, Zoho, Accolite, Amazon, Microsoft, Samsung, Snapdeal, D-E-Shaw, MakeMyTrip, Teradata, Walmart, 
                                    Goldman Sachs, Intuit, Adobe, SAP Labs, Tejas Network, Cisco, Qualcomm, Cognizant, Mahindra Comviva, IgniteWorld
      Leetcode Link               : https://leetcode.com/problems/reverse-linked-list/
      
*/

/********************************************************************** C++ **********************************************************************/

//T.C : O(n)
//S.C : O(n) 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head==NULL){
            return head;
        }
        
        ListNode *temp=head;
        stack<int>s;
        while(temp!=NULL){
            s.push(temp->val);
            temp=temp->next;
        }

        ListNode *t=head;

        while(t!=NULL){
           t->val=s.top();
           s.pop();
           t=t->next;
        }


        return head;


    }
};
