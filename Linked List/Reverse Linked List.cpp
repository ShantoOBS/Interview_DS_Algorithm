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

class Solution {
    public ListNode reverseList(ListNode head) {
        // We start with three pointers:
        // 1. prev: This will keep track of the previous node we processed (starts as null).
        // 2. next: This will keep track of the next node to process.
        // 3. curr: This is the current node we are processing (starts as the head of the list).
        ListNode prev = null;
        ListNode next = null;
        ListNode curr = head;

        // We loop through the linked list until we reach the end (when curr is null).
        while (curr != null) {
            // Store the next node in the list. We need to do this because we will change the current node's next pointer.
            next = curr.next;

            // Reverse the link. Instead of pointing to the next node, the current node now points to the previous node.
            curr.next = prev;

            // Move the previous pointer to the current node (since the current node is now processed).
            prev = curr;

            // Move the current pointer to the next node (to continue processing the rest of the list).
            curr = next;
        }

        // When we've processed all nodes, the prev pointer will be at the new head of the reversed list.
        return prev;
    }
}
