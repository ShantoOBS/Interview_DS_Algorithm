/*
    Company Tags                : 
    Leetcode Link               : https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
*/


class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

       int ct=0;

       ListNode * last=list1;
       ListNode * head=list1;

        while(ct<=b){

            if(ct<a-1){
                list1=list1->next;
            }
            last=last->next;
            ct++;
        }

        list1->next=list2;

        while(list2->next!=NULL) list2=list2->next;

        list2->next=last;

        return head;
        
    }
};
