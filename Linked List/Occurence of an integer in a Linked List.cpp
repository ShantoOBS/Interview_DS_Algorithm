/*     Scroll below to see JAVA code also    */
/*
    Company Tags                : will update later
    Leetcode Link               : https://www.geeksforgeeks.org/problems/occurence-of-an-integer-in-a-linked-list/1
*/
/****************************************************** C++ *********************************************/
//Approach - Simple travarsal
//T.C : O(n)
//S.C : O(n)

class Solution {
  public:
    int count(struct Node* head, int key) {
        // add your code here
        int ans=0;
        
        while(head){
            if(head->data==key)ans++;
            head=head->next;
        }
        
        return ans;
    }
};


/****************************************************** JAVA *********************************************/
//Approach - Simple travarsal
//T.C : O(n)
//S.C : O(n)

class Solution {
    public static int count(Node head, int key) {
        // code here
        
        int ans=0;
        
        while(head!=null){
            if(head.data==key)ans++;
            head=head.next;
        }
        
        return ans;
    }
}

