// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    long long colosseum(int n,vector<int> a) {
        sort(a.begin(), a.end());
        int sum1 = 0;
        int size = 3*n;
        for(int i=0; i<size-(2*n); i++)
            sum1 += a[i];

        int temp = n;
        int sum2 = 0;
        while(temp--) {
            sum2 += a[(3*n) - temp];
        }

        return sum1 + sum2;
   }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        Solution obj;
        int n;
        cin>>n;
        vector<int> a(3*n);
         for (int i = 0; i <3*n; ++i){
            cin>>a[i];
        }
        cout << obj.colosseum(n,a) <<"\n";
    }
    return 0;
}
  // } Driver Code Ends