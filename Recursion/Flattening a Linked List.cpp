/*
   
    Company Tags                : 24*7 Innovation Labs, Amazon, Drishti-Soft, Flipkart, Goldman Sachs, Microsoft, Paytm, Payu, Snapdeal, Visa
    GFG Link               : https://www.geeksforgeeks.org/problems/flattening-a-linked-list--170645/1

//Also Watch - Merge Two Sorted Lists - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Linked%20List/Merge%20Two%20Sorted%20Lists.cpp

/********************************************************** C++ **********************************************************/
//T.C : O(N*N*M) See my detailed video above to understand this.
//S.C : Auziliary Space = O(1) and O(N*M) – because of the recursion. 

// Function to merge two linked lists in sorted order
Node* mergeTwoLists(Node* head1, Node* head2) {
    // If one of the linked lists is empty, return the other
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node* result;
    // Compare the nodes and merge them in sorted order
    if (head1->data < head2->data) {
        result = head1;
        // Recursively merge the rest of the nodes
        result->bottom = mergeTwoLists(head1->bottom, head2); //Trust
    } else {
        result = head2;
        // Recursively merge the rest of the nodes
        result->bottom = mergeTwoLists(head1, head2->bottom); //Trust
    }

    return result;
}

Node *flatten(Node *head) {
    if(!head)
        return head;

    Node* temp = flatten(head->next);
    
    return mergeTwoLists(head, temp);
}


/********************************************************** JAVA **********************************************************/
//T.C : O(N*N*M) - See my detailed video above to understand this.
//S.C : Auziliary Space = O(1) and O(N*M) – because of the recursion . N*M is the total number of elements in the flattened linked List
class GfG
{
    
    Node mergeList(Node l1,Node l2){
        
        if(l1==null)return l2;
        
        if(l2==null)return l1;
        
        Node result;
     
            
            if(l1.data<l2.data){
                result=l1;
                result.bottom=mergeList(result.bottom,l2);
            }
            else{
                result=l2;
                result.bottom=mergeList(l1,result.bottom);
            }
        
        
        return result;
        
        
    } 
    Node flatten(Node root)
    {
	// Your code here
	
	     if(root==null)return null;
	     
	     Node root2=flatten(root.next);
	     
	     return mergeList(root,root2);
    }
}
