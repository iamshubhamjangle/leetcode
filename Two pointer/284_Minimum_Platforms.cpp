/*
Minimum_Platforms.cpp

Given arrival and departure times of all trains that reach a railway station. 
Find the minimum number of platforms required for the railway station 
so that no train is kept waiting.

https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
TC: O(2nlogn + 2n) ~ O(NlogN)
SC: O(1)
*/


class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
    	if(n == 0) return 0;
    	
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int platform = 1;
    	int maxPlatforms = 1;
    	
    	int i = 1, j = 0;
    	
    	while(i < n && j < n) {
    	    if(arr[i] <= dep[j]) {
    	        platform++;
    	        i++;
    	    } 
    	    else if(arr[i] > dep[j]) {
    	        platform--;
    	        j++;
    	    }
    	    
    	    maxPlatforms = max(maxPlatforms, platform);
    	}
    	
    	return maxPlatforms;
    }
};