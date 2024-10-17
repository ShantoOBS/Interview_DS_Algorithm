
/*
    Company Tags                : will soon update
    GFG Link                    : https://www.geeksforgeeks.org/problems/two-swaps--155623/1
*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        
         Node * node1=new Node(-1);
         Node * node2=new Node(-1);
         
         Node *temp1=node1;
         Node *temp2=node2;
         
         int i=1;
         
         while(head){
             
             if(i&1){
                 
                 temp1->next=head;
                 temp1=temp1->next;
             }
             else{
                 
                 temp2->next=head;
                 temp2=temp2->next;
                 
             }
             
             head=head->next;
             temp1->next=NULL;
             temp2->next=NULL;
             i++;
         }
         
         return {node1->next,node2->next};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends
