/*
    Company Tags                : Accolite, Amazon, Flipkart, MakeMyTrip, Microsoft, Qualcomm, Snapdeal
    Leetcode Link               : https://leetcode.com/problems/add-two-numbers-ii/   
*/

//Approach-1 (Reverse the LinkedList)
class Solution {
public:
    
    ListNode* reverseLL(ListNode* head) {
        
        if(!head || !head->next) {
            return head;
        }
        
        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        int sum = 0, carry = 0;
        ListNode* ans = new ListNode();
        while (l1 || l2) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            ans->val = sum % 10;
            carry    = sum / 10;
            
            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            sum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};


//Approach-2 (Using Stack) - What if you cannot modify the input lists? In other words, reversing the lists is not allowed. 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while (l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int sum = 0, carry = 0;
        ListNode* ans = new ListNode();
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            ans->val = sum % 10;
            carry    = sum / 10;
            
            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            sum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};



//Approach-1 (My code)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode * rev(ListNode * head){

        ListNode * pre=NULL;
        ListNode * curr=head;
        ListNode * n=NULL;

        while(curr){

            n=curr->next;
            curr->next=pre;
            pre=curr;
            curr=n;
        }

        return pre;
    }

    void insert_head(ListNode * &head,int data){
        ListNode * temp=new ListNode(data);
        temp->next=head;
        head=temp;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode * r1=rev(l1);

        ListNode * r2=rev(l2);

      

    ListNode* head=NULL;
   
    int carry=0;

  
        while(r1 ||  r2){

            int sum=0;
            
            if(r1){
                sum+=r1->val;
                r1=r1->next;
            }
           
             if(r2){
                sum+=r2->val;
                r2=r2->next;
            }

            sum+=carry;

            int mod=sum%10;
             carry=sum/10;

            if(carry){
                insert_head(head,mod);
            }
            else{
                insert_head(head,sum);
            }
        }

        if(carry){
            insert_head(head,1);
        }

       
        return head;
    }
};
