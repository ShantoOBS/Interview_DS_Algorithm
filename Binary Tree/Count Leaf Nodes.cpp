/*
    Company Tags                : Samsung, Ola, Slice, BYJUS, Synopsys, Incadea
    Coding Neja Link            : https://www.naukri.com/code360/problems/count-leaf-nodes_893055?source=youtube&campaign=LoveBabbar_Codestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudio&leftPanelTabValue=PROBLEM
*/
/************************************************************ C++ ************************************************/
//Approach-1 (Inorder-traversal)
//T.C : O(n)
//S.C : O(1)

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/

void inorder(BinaryTreeNode<int> *root,int &cnt){

     if(root==NULL)return;

     inorder(root->left,cnt);

     if(root->left==NULL && root->right==NULL)cnt++;

     inorder(root->right,cnt);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
      int cnt=0;

      inorder(root,cnt);
        
      return cnt;
}
