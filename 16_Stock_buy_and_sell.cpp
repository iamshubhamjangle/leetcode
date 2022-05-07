/*
Stock_buy_and_sell.cpp

Method 1: loop to check the prices and buy/sell - time: O(N), space: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int> > stockBuySell(vector<int> a, int n){
        bool isStockBuyed = false;
        vector<vector<int>> ans;
        vector<int> stock;
        int i;

        for(i=0; i<n-1; i++) {
        	if(a[i] < a[i+1] && !isStockBuyed) {
        		stock.push_back(i);
        		isStockBuyed = true;
        	} else if(a[i] > a[i+1] && isStockBuyed) {
        		stock.push_back(i);
        		ans.push_back(stock);
        		stock.clear();
        		isStockBuyed = false;
        	}
        }

        if(isStockBuyed) {
        	stock.push_back(i);
    		ans.push_back(stock);
    		stock.clear();
    		isStockBuyed = false;
        }

        return ans;
    }
};


int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}