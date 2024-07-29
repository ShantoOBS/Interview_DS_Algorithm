

//https://leetcode.com/problems/count-the-digits-that-divide-a-number/

class Solution {
    public int countDigits(int num) {
        int count = 0;
        int pop = 0;
        int ans = num;

        while(ans > 0){
            pop = ans%10;
            ans = ans/10;

            if(num % pop == 0){
                count++;
            }
        }
        return count;
    }
}