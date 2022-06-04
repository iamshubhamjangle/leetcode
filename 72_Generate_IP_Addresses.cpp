/*
Generate_IP_Addresses.cpp

Given a string S containing only digits, Your task is to complete the function genIp() 
which returns a vector containing all possible combinations of valid IPv4 IP addresses 
and takes only a string S as its only argument.
Note: Order doesn't matter.

For string 11211 the IP address possible are 
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1

Input : S = 1111
Output: 1.1.1.1

Input : S = 55
Output: -1

https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1
    - Use 4 for loops O(N^4) SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<string> genIp(string &s) {
        vector<string>ans;
        for(int a=1;a<=3;a++)
         for(int b=1;b<=3;b++)
          for(int c=1;c<=3;c++)
           for(int d=1;d<=3;d++)
           if(a+b+c+d==s.size()){
               int A=stoi(s.substr(0,a));
               int B=stoi(s.substr(a,b));
               int C=stoi(s.substr(a+b,c));
               int D=stoi(s.substr(a+b+c,d));
               string temp;
               if(A<=255 && B<=255 && C<=255 &&D<=255){
                   temp=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D);
               if(temp.size()==s.size()+3)
               ans.push_back(temp);
               }
           }
           return ans;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}