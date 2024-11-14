/*     Scroll below to see JAVA code also    */
/*
    Company Tags                : Google
    GFG Link                    : https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1
*/
/************************************************************ C++ ************************************************/
//Approach (priority-queue)
//T.C : O(n)
//S.C : O(n)

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        
           int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < n; ++i) {
            minHeap.push(arr[i]);

            // If heap size exceeds k, extract the minimum element
            if (minHeap.size() > k) {
                arr[i - k] = minHeap.top();
                minHeap.pop();
            }
        }

        // Update the remaining elements
        int j = n - k;
        while (!minHeap.empty()) {
            arr[j++] = minHeap.top();
            minHeap.pop();
        }
        
    }
};


/************************************************************ JAVA ************************************************/
//Approach (priority-queue)
//T.C : O(n)
//S.C : O(n)

class Solution {
    // Non-static method, so you need to call it on an instance of the class
    public void nearlySorted(int[] arr, int k) {
        // code
          PriorityQueue<Integer>pq= new PriorityQueue<>();
        int n= arr.length;
        for(int i=0;i<=k;i++)pq.add(arr[i]);
        
    int ind=0;
    
    for( int i=k+1;i<n;i++){
        arr[ind++]=pq.poll();
        pq.add(arr[i]);        
    }
    
    while(!pq.isEmpty()){
        arr[ind++]=pq.poll();
    }
    
    
    }
}
