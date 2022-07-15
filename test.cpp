#include <bits/stdc++.h>
using namespace std;



bool isPalindrome(int i, string s) {
    int n = s.size();

    if(i >= n/2)
        return true;

    if(s[i] != s[n-i-1])
        return false;
    else
        return isPalindrome(i+1, s);
}

int main(){
    cout << isPalindrome(0, "madam") << endl;
    cout << isPalindrome(0, "raceacar") << endl;
    cout << isPalindrome(0, "circleelcric") << endl;
}