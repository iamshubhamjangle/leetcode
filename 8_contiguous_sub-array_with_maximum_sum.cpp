/*
Kadane's Algorithm -  contiguous sub-array(containing at least one number) which has the maximum sum
// Method 1: bruteforce	
// Method 2: currsum, maxsum = INT_MIN
	
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
	//Function to find the sum of contiguous subarray with maximum sum.
   // Method 1: Brutefore and find the sum O(N*N)
   //  long long maxSubarraySum(int arr[], int n){
   //  	long long int sum = arr[0];
   //  	for(int i=0; i<n; i++) {
   // 		long long int localSum = 0;
   //  		for(int j=i; j<n; j++) {
   //  			localSum += arr[j];
   //  			if(localSum > sum) sum = localSum;
   //  		}
   //  	}
   //  	return sum;
   //  }

	// Method 2: currsum, maxsum = INT_MIN
	long long maxSubarraySum(int arr[], int n) {
        long long int cursum=0;
        long long int maxsum=INT_MIN;
        for(int i=0;i<n;i++){
           cursum+=arr[i];
           if(cursum>maxsum) maxsum=cursum;
           if(cursum<0) cursum=0;
        }
        return maxsum;
	}

};

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}