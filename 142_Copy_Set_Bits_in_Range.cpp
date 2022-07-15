/*
Copy_Set_Bits_in_Range.cpp



*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        bitset<32> a(x);
        bitset<32> b(y);

        // cout << a.to_string() << endl;
        // cout << b.to_string() << endl;

        for(int i=l-1;i<r;i++){
            if(b[i]) a[i]=1;
        }

        // cout << a.to_string() << endl;

        return a.to_ulong();
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}