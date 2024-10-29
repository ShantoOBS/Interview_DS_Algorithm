/*     Scroll below to see JAVA code also    */
/*
    Company Tags                : Paytm
    Leetcode Link               : https://www.geeksforgeeks.org/problems/quick-sort-on-linked-list/1
*/
/************************************************************ C++ ************************************************/

//T.C : O(n log n) Worst-case : O(n^2)
//S.C : O(log n)   Worst-case : O(n)

class Solution {
public:
    struct Node* quickSort(struct Node* head) {
        
        if (!head || !head->next) return head; // Base case for empty list or single element

        // Recursive quicksort call with the head and tail of the list
        return quickSortRec(head, getTail(head));
    }

private:
    // Utility function to get the tail of the list
    struct Node* getTail(struct Node* node) {
        
        while (node && node->next) {
            node = node->next;
        }
        return node;
    }

    // Recursive quicksort function
    struct Node* quickSortRec(struct Node* start, struct Node* end) {
        if (start == end) return start; // Base case for single node

        struct Node* lessHead = nullptr;
        struct Node* pivot = nullptr;
        struct Node* greaterHead = nullptr;

        // Partition the list around the pivot (first element as pivot)
        partition(start, end, lessHead, pivot, greaterHead);

        // Sort the left and right partitions
        lessHead = quickSortRec(lessHead, getTail(lessHead));
        greaterHead = quickSortRec(greaterHead, getTail(greaterHead));

        // Concatenate less, pivot, and greater lists and return the new head
        return concatenate(lessHead, pivot, greaterHead);
    }

    // Partition function using the first node as pivot
    void partition(struct Node* start, struct Node* end,
                   struct Node*& lessHead, struct Node*& pivot, struct Node*& greaterHead) {
        pivot = start;
        lessHead = nullptr;
        greaterHead = nullptr;
        
        struct Node* current = start->next;
        struct Node* lessTail = nullptr;
        struct Node* greaterTail = nullptr;

        // Partition nodes into less and greater lists
        while (current != end->next) {
            if (current->data < pivot->data) {
                if (!lessHead) {
                    lessHead = lessTail = current;
                } else {
                    lessTail->next = current;
                    lessTail = current;
                }
            } else {
                if (!greaterHead) {
                    greaterHead = greaterTail = current;
                } else {
                    greaterTail->next = current;
                    greaterTail = current;
                }
            }
            current = current->next;
        }

        // End both lists
        if (lessTail) lessTail->next = nullptr;
        if (greaterTail) greaterTail->next = nullptr;
    }

    // Concatenate less, pivot, and greater lists
    struct Node* concatenate(struct Node* less, struct Node* pivot, struct Node* greater) {
        struct Node* head = less;

        if (less) {
            struct Node* tail = getTail(less);
            tail->next = pivot;
        } else {
            head = pivot;
        }

        pivot->next = greater;
        return head;
    }
};


/************************************************************ JAVA ************************************************/


class GfG {
    public static Node getTail(Node node) {
        if (node == null) return null;
        while (node.next != null) {
            node = node.next;
        }
        return node;
    }
    public static Node concatenate(Node firstHead, Node pivot, Node secondHead) {
        Node head = firstHead;

        if (firstHead != null) {
            Node tail = getTail(firstHead);
            tail.next = pivot;
        } else {
            head = pivot;
        }

        pivot.next = secondHead;
        return head;
    }
    private static Node[] partition(Node start, Node end) {
        Node pivot = start;
        Node firstHead = null, firstTail = null;
        Node secondHead = null, secondTail = null;
        Node current = start.next;
        while(current != end.next){
            if(current.data < pivot.data){
                if(firstHead == null){
                    firstHead = current;
                    firstTail = current;
                }
                else {
                    firstTail.next = current;
                    firstTail = current;
                }
            }
            else {
                if(secondHead == null){
                    secondHead = current;
                    secondTail = current;
                }
                else {
                    secondTail.next = current;
                    secondTail = current;
                }
            }
            current = current.next;
        }
        if(firstTail !=null) firstTail.next = null;
        if(secondTail !=null) secondTail.next = null;
        return new Node[]{firstHead, pivot, secondHead};
    }
    public static Node quickSortFunc(Node start, Node end) {
        if(start == null || start == end) return start;
        Node[] partitioned = partition(start, end);
        Node firstHead = partitioned[0];
        Node pivot = partitioned[1];
        Node secondHead = partitioned[2];
        
        firstHead = quickSortFunc(firstHead, getTail(firstHead));
        secondHead = quickSortFunc(secondHead, getTail(secondHead));
        
        return concatenate(firstHead, pivot, secondHead);
        
    }
    public static Node quickSort(Node node) {
        // Your code here
        node = quickSortFunc(node, getTail(node));
        return node;
    }
}


