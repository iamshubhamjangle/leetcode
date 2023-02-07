/*
Minimum_Platforms.cpp

https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
*/

class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n) {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int pfNeeded = 1; int maxpf = 1;
    	// two pointer approach
    	int i = 1; int j = 0;
    	
    	while(i<n && j<n) {
    	    if(arr[i] <= dep[j]) {
    	        pfNeeded++;
    	        i++;
    	    } else {
    	        pfNeeded--;
    	        j++;
    	    }
    	    
    	    maxpf = max(pfNeeded, maxpf);
    	}
    	
    	return maxpf;
    }
};