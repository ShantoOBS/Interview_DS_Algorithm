/*
    Company Tags                : VMWare, Amazon, Microsoft, Oracle
    GFG Link                    : https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
*/
/************************************************************ C++ ************************************************/
//Approach-1 
//T.C : O(n)
//S.C : O(n)

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        Node* dummy=new Node(-1);
        Node* nxt=dummy;
        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, 
        greater<pair<int, Node*>>>pq;
        
        for(auto *it:arr){
            pq.push({it->data, it});
        }
        
        while(!pq.empty()){
            auto it=pq.top();
            int val=it.first;
            Node* node=it.second;
            pq.pop();
            
            nxt->next=node;
            nxt=node;
            if(node->next){
                pq.push({node->next->data, node->next});
            }
        }
        
        return dummy->next;
        
    }
};
