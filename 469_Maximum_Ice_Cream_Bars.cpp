/*
Maximum_Ice_Cream_Bars.cpp

https://leetcode.com/problems/maximum-ice-cream-bars/description/
*/

class Solution {
public:
    // // Sorting. TC: O(NlogN) SC: O(1)
    // int maxIceCream(vector<int>& costs, int coins) {
    //     sort(costs.begin(), costs.end());
    //     int count = 0;

    //     for(auto &n: costs) {
    //         if(coins > 0 && coins-n >= 0) {
    //             coins -= n;
    //             count++;
    //         }
    //     }

    //     return count;
    // }


    // Running Max. TC: O(N) SC: O(1)
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = 0;
        int count = 0;

        for(auto &n: costs) {
            if(coins > 0 && coins-n >= 0) {
                coins -= n;
                count++;
                maxi = max(maxi, n);
            } else {
                if(n < maxi) {
                    coins = maxi - n;
                    maxi = n;
                }
            }
        }

        return count;
    }
};