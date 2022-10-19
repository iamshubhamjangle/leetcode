/*
Sum_of_Number_and_Its_Reverse.cpp

https://leetcode.com/contest/weekly-contest-315/problems/sum-of-number-and-its-reverse/
*/

class Solution {
public:
	int reverse(int i){
        int ans = 0;
        while(i > 0){
            ans *= 10;
            ans += i%10;
            i /= 10;
        }
        return ans;
    }

    bool sumOfNumberAndReverse(int n) {
    	if(n == 0) return 0;

        for(int i=1; i<=n; i++) {
        	if(i + revOfNumber(i) == n)
        		return true;
        }

        return false;
    }
};	

