
// Leetcode Link : https://leetcode.com/problems/n-ary-tree-postorder-traversal/?envType=daily-question&envId=2024-08-26


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>a;

    void postOrder(Node* root)
    {
        if(root == NULL) return;
        for(Node* child: root->children)
            postOrder(child);
          a.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
              postOrder(root);
              return a;        
    }
};
