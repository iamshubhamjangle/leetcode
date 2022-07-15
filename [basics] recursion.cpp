/*
Basics #1: [basics] recursion.cpp
    printName(5);   cout<<endl;
    print1toNLinearly(10);  cout<<endl;
    printNto1Linearly(10);  cout<<endl;
    print1toNBacktracking(10);  cout<<endl;
    printNto1Backtracking(10);  cout<<endl;
*/

#include <bits/stdc++.h>
using namespace std;

void printName(int n) {
    if(n == 0) return;
    cout << "Shubham ";
    printName(n-1);
}

void print1toNLinearly(int n, int i = 1) {
    if(i > n) return;
    cout << i << " ";
    print1toNLinearly(n, i+1);
}

void printNto1Linearly(int n) {
    if(n == 0) return;
    cout << n << " ";
    printNto1Linearly(n - 1);
}

void print1toNBacktracking(int n) {
    if(n == 0) return;
    print1toNBacktracking(n-1);
    cout << n << " ";
}

void printNto1Backtracking(int n, int i = 1) {
    if(i > n) return;
    printNto1Backtracking(n, i+1);
    cout << i << " ";
}

int main(){
    printName(5);   cout<<endl;
    print1toNLinearly(10);  cout<<endl;
    printNto1Linearly(10);  cout<<endl;
    print1toNBacktracking(10);  cout<<endl;
    printNto1Backtracking(10);  cout<<endl;
    return 1;
}