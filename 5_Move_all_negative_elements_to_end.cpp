/*
Move_all_negative_elements_to_end
Method 1: use temp array	time: O(3N), space: O(N)
	- copy negative elements to temp array then positive elements
	- copy the temp array to main array
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
    	int temp[n];
    	int tempIndex = 0;
    	for(int i=0; i<n; i++) {
    		if(arr[i] >= 0) {
    			temp[tempIndex] = arr[i];
    			tempIndex++;
    		}
    	}
    	for(int i=0; i<n; i++) {
    		if(arr[i] < 0) {
    			temp[tempIndex] = arr[i];
    			tempIndex++;
    		}
    	}
    	for(int i=0; i<n; i++) {
    		arr[i] = temp[i];
    	}
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}