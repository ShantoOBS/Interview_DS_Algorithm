/*    Scroll below to see JAVA code as well    */
/*
    Company Tags                : will update later
    GFG Link                    : https://www.geeksforgeeks.org/problem-of-the-day
*/
/*************************************************************************** C++ ***************************************************************************/
//T.C : O(n)
//S.C : O(n)

class Solution {
  public:
    Node * solve(vector<int>&inorder,int inStart,int inEnd,vector<int>&preorder,int pStart,int pEnd,map<int,int>&mp){
        
        if(inStart>inEnd || pStart>pEnd)return NULL;
        
        Node * temp=new Node(preorder[pStart]);
        int inRoot=mp[temp->data];
        int numsleft=inRoot-inStart;
 
        temp->left=solve(inorder,inStart,inRoot-1,preorder,pStart+1,pStart+numsleft,mp);
        temp->right=solve(inorder,inRoot+1,inEnd,preorder,pStart+numsleft+1,pEnd,mp);
      
        return temp;        
          
    }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        
       map<int,int>mp;
        
        for(int i=0;i<inorder.size();i++){
            
            mp[inorder[i]]=i;
        }
        
        Node * root=solve(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,mp);
        
        return root;         
    }
};

/*************************************************************************** JAVA ***************************************************************************/
//T.C : O(n)
//S.C : O(n)

import java.util.HashMap;
import java.util.Map;

class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class Solution {
    public Node solve(int[] inorder, int inStart, int inEnd, int[] preorder, int pStart, int pEnd, Map<Integer, Integer> mp) {
        if (inStart > inEnd || pStart > pEnd) return null;

        Node temp = new Node(preorder[pStart]);
        int inRoot = mp.get(temp.data);
        int numsLeft = inRoot - inStart;

        temp.left = solve(inorder, inStart, inRoot - 1, preorder, pStart + 1, pStart + numsLeft, mp);
        temp.right = solve(inorder, inRoot + 1, inEnd, preorder, pStart + numsLeft + 1, pEnd, mp);

        return temp;
    }

    // Function to build the tree from given inorder and preorder traversals
    public Node buildTree(int[] inorder, int[] preorder) {
        Map<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < inorder.length; i++) {
            mp.put(inorder[i], i);
        }

        return solve(inorder, 0, inorder.length - 1, preorder, 0, preorder.length - 1, mp);
    }
}

