/*
Count_the_Digits_That_Divide_a_Number.cpp

https://leetcode.com/contest/weekly-contest-326/problems/count-the-digits-that-divide-a-number/
*/


class Solution {
public:
    int countDigits(int num) {
    	int numCopy = num;
    	int cnt = 0;

        while(num) {
        	int temp = num % 10;
        	if(numCopy % temp == 0) cnt++;
        	num /= 10;
        }

        return cnt;
    }
};