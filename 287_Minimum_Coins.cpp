/*
Minimum_Coins.cpp

https://www.codingninjas.com/codestudio/problems/minimum-coins_982764
*/

#include <bits/stdc++.h> 
int minimumCoins(int p) {
    int deno[] = {1,2,5,10,20,50,100,500,1000};
    int n = 9;

    vector<int> ans;
    int count = 0;

    for(int i=n-1; i>=0; i--) {
    	while(p >= deno[i]) {
    		p -= deno[i];
    		count++;
    	}
    }

    return count;
}