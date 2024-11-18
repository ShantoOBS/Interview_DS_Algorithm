/*     Scroll below to see JAVA code also    */
/*
  
    Company Tags                  : Amazon, Microsoft, MAQ Software
    Leetcode Link                 : https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1
   
*/
/**************************************************************** C++ ****************************************************************/
//Approach -1
//T.C : O(n)
//S.C : O(n)

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        
        int n=arr.size();
        
        queue<int>q;
        
        for(auto i:arr){
            q.push(i);
        }
        
        
        for(int i=1;i<=d;i++){
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
        
        for(int i=0;i<n;i++){
            arr[i]=q.front();
            if(!q.empty())
              q.pop();
        }
        
        
    }
};


/**************************************************************** JAVA ****************************************************************/

//Approach -1
//T.C : O(n)
//S.C : O(n)

class Solution {
    // Function to rotate an array by d elements in counter-clockwise direction.
    static void rotateArr(int arr[], int d) {
        // add your code here
        
        int n=arr.length;
        
        Queue<Integer> q=new ArrayDeque<>();
        
        for(int i:arr){
            q.add(i);
        }
        
        for(int i=1;i<=d;i++){
            
            q.add(q.poll());
        }
        
        
        for(int i=0;i<n;i++){
            arr[i]=q.poll();
        }
    }
}




