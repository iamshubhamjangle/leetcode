/*
Next_Permutation 

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}

Method 1: find idx1, idx2, swap, reverse. time: O(N), space: O(1)
	- find idx1 = loop until arr[i] < arr[i+1]
	- if idx1 == -1, reverse and return;
	- find idx2 = loop until arr[idx1] < arr[i]
	- swap idx1, idx2
	- reverse idx1 + 1, end

*/



#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        if(n <= 1) {
        	return arr;
        }

        int idx1 = -1;
        int idx2 = -1;

        for(int i=n-2; i>=0; i--) {
        	// cout << "is " << arr[i] << " < " << arr[i+1] << endl; 
        	if(arr[i] < arr[i+1]) {
        		idx1 = i;
        		break;
        	}
        }

        // cout << "idx1: " << idx1 << endl;

        if(idx1 == -1) {
        	reverse(arr.begin(), arr.end());
        	return arr;
        }

        for(int i=n-1; i>idx1; i--) {
        	if(arr[idx1] < arr[i]) {
        		idx2 = i;
        		break;
        	}
        }

        // cout << "idx1: " << idx1 << " idx2: " << idx2 << endl;

        swap(arr[idx1], arr[idx2]);

        reverse(arr.begin() + idx1 + 1, arr.end());

        return arr;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}