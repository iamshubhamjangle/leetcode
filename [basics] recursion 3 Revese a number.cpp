/* Revese a number
*/

#include <bits/stdc++.h>
using namespace std;


void printReverse(int i, int a[], int n) {
    if(i >= n/2) return;
    swap(a[i], a[n-i-1]);
    printReverse(i+1, a, n);
}

void printReverseFunctional(int i, int a[], int n) {
    int j = n-1;
    while(i<j) {
        swap(a[i], a[j]);
        i++; j--;
    }
}

int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    printReverseFunctional(0, a, n);
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
    printReverse(0, a, n);
    for(int i=0; i<n; i++) cout << a[i] << " ";
}