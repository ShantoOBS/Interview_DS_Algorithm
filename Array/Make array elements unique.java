/*
    Company Tags                : Dunzo
    GFG Link                    : https://www.geeksforgeeks.org/problems/make-array-elements-unique--170645/1
*/
/************************************************************ JAVA ************************************************/
//Approach ()
//T.C : O(n)
//S.C : O(n)

class Solution {
    public int minIncrements(int[] arr) {
        // Code here
          Arrays.sort(arr);

        HashSet<Integer> set = new HashSet<>();

        int sum = 0;

        int max = 0;

        for(int i=0;i<arr.length;i++){

            max = Math.max(arr[i],max);

            if(set.contains(arr[i])){

                sum+=max+1-arr[i];

                max++;

                set.add(max);

            }

            else{

                set.add(arr[i]);

            }

        }

        return sum;
        
    }
}
