/*
    Company Tags                : VMWare, Flipkart, Accolite, Amazon, Microsoft, Snapdeal, D-E-Shaw, FactSet, MakeMyTrip, Visa,Goldman Sachs, MAQ Software, Adobe, Qualcomm
    GFG Link                    : https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
*/
/************************************************************ C++ ************************************************/
//Approach (simple binary search trick)
//T.C : O(m+n)
//S.C : O(m)

class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
         unordered_map<Node*,bool>mp;
        int ans=-1;
        while(head1!=NULL){
            mp[head1]=true;
            head1=head1->next;
        }
        while(head2!=NULL){
            if(mp[head2]==true) {
                ans=head2->data;
                return ans;
            }
            head2=head2->next;
        }
        return ans;
    }
};
