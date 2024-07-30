/*
    
    Company Tags                : 24*7 Innovation Labs, Amazon, Drishti-Soft, Flipkart, Goldman Sachs, Microsoft, Paytm, Payu, Snapdeal, Visa
    GFG Link               : https://www.geeksforgeeks.org/problems/flattening-a-linked-list--170645/1
*/


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
