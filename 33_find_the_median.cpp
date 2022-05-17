/*
Find the median 

Given an array arr[] of N integers, calculate the median
Median
	- for n = even: median = average of center two elements of sorted array
	- for n = odd: median = average of center two elements of sorted array

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	public:
		int find_median(vector<int> v)
		{
		    sort(v.begin(),v.end());
		    int n = v.size();
		    if(n%2 != 0){
		        return v[(n)/2];
		    }
		    return (v[(n/2)-1 + v[n/2]])/2;
		}
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}