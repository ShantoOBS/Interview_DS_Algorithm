/*    Scroll below to see JAVA code also    */
/*
    Company Tags                : will be soon
    GFG Link                    : https://www.geeksforgeeks.org/problems/linked-list-length-even-or-odd/1
*/

/****************************************** C++ ***********************************************************/

class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        // Code here
        
           int cnt=0;
        Node* temp=*head;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        return cnt%2==0;
    }
};


/****************************************** JAVA ***********************************************************/

class Solution {
    public boolean isLengthEven(Node head) {
        // code here
        int ans=0;
        
        while(head!=null){
            ans++;
            head=head.next;
        }
        
        if(ans%2==0)return true;
        
        return false;
    }
}

