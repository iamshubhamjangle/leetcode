/*
    printSumOfnNumbers(5);
    cout << returnSumOfNNumbers(5) << endl;
    printFactorial(3);
    cout << returnFactorial(3) << endl;
*/

#include <bits/stdc++.h>
using namespace std;


void printSumOfnNumbers(int n, int sum = 0) {
    if(n == 0) {
        cout << sum << endl;
        return;
    }
    printSumOfnNumbers(n-1, n+sum);
}

int returnSumOfNNumbers(int n) {
    if(n == 0) return 0;
    return n + returnSumOfNNumbers(n-1);
}

void printFactorial(int n, int ans = 1) {
    if(n == 1) {
        cout << ans << endl;
        return;
    }
    printFactorial(n-1, n * ans);
}

int returnFactorial(int n) {
    if(n == 1) return 1;
    return n * returnFactorial(n-1);
}

int main(){
    printSumOfnNumbers(5);
    cout << returnSumOfNNumbers(5) << endl;
    printFactorial(3);
    cout << returnFactorial(3) << endl;
}