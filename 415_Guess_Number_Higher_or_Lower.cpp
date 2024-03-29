/*
Guess_Number_Higher_or_Lower.cpp

https://leetcode.com/problems/guess-number-higher-or-lower/
*/

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);
            
            if(res == 0)
                return mid;
            else if(res > 0)
                low = mid+1;
            else
                high = mid-1;
        }
        
        return -1;
    }
};