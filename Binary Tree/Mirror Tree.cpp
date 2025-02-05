/*         Scroll down to see JAVA code also        */
/*
    Company Tags                : Paytm, VMWare, Morgan Stanley, Accolite, Amazon, Microsoft
    GFG Link                    : https://www.geeksforgeeks.org/problems/mirror-tree/1
*/
/*********************************************************** C++ **************************************************/
//T.C : O(n)
//S.C : O(h) h is the hight of the tree
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node==NULL)return ;
        
        swap(node->right,node->left);
        
        mirror(node->left);
        mirror(node->right);
        
    }
};

/*********************************************************** JAVA **************************************************/
//T.C : O(n)
//S.C : O(h) h is the hight of the tree

class Solution {
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node node) {
        // Your code here
        if(node==null)return ;
        
        Node  temp=node.left;
        node.left=node.right;
        node.right=temp;
        
        mirror(node.left);
        mirror(node.right);
    }
}
