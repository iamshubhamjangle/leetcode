/*
Find_Minimum_Number_Of_Coins.cpp

https://www.codingninjas.com/codestudio/problems/975277
*/

#include <bits/stdc++.h> 
int findMinimumCoins(int amount) {
    vector<int> coins = {1000,500,100,50,20,10,5,2,1};

    int maxCoinsNeeded = 0;

    for(auto coin: coins) {
        if(amount >= coin) {
            int coinsNeeded = amount/coin;
            amount -= coinsNeeded * coin;
            maxCoinsNeeded += coinsNeeded;
        }
    }

    return maxCoinsNeeded;
}