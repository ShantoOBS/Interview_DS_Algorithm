### :memo: std::set_difference and std::back_inserter :1234:
```c++
set_difference -> Copies the elements from the sorted s1 which are not found in the sorted s2 to a container in sorted order
back_inserter -> Can be used to add elements to the end of a container
Example : 
        set<int> st1, st2;
	vector<int> v1;
	//Find difference in between set1 and set2 and put unique element of set1 in v1
	set_difference(begin(st1), end(st1), begin(st2), end(st2), back_inserter(v1));
	
	Qns on Leetcode: 2215
	Leetcode - : Find the Difference of Two Arrays
<br\>

### :memo: Heap :1234:
```
priority_queue<int> maxHeap; // NOTE: default is max heap

priority_queue<int, vector<int> , greater<int>> minHeap;  // NOTE: min heap
