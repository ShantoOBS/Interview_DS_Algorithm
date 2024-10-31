/*
    Company Tags  : will be soon
    GFG Link      : https://www.geeksforgeeks.org/problems/insert-in-sorted-way-in-a-sorted-dll/1
*/
************************************************************ JAVA ************************************************************

  
class Solution {
    public Node sortedInsert(Node head, int x) {
        // add your code here
        
        Node newNode = new Node(x);
        
        Node temp = head;
        Node prev = null;
        
        while(temp != null){
            if(temp.data < x){
                prev = temp;
                temp = temp.next;
            }else{
                //find greater then or equal to x 
                //then insert the given  
                if(prev == null){
                    newNode.next = temp;
                    head = newNode;
                }else{
                    prev.next = newNode;
                    newNode.next = temp;   
                }
                break;
            }
        }
        
        //if the temp is null means the elment is larger than last element
        if(temp == null){
            prev.next = newNode;
            newNode.next = null;
        }
        return head; 

    }        
        
}
