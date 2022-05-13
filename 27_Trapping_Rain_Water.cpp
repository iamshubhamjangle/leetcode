/*
Trapping_Rain_Water.cpp
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

Input: N = 6, arr[] = {3,0,0,2,0,4}
Output: 10

Input: N = 4, arr[] = {7,4,0,9}
Output: 10

Input: N = 3, arr[] = {6,9,9}
Output: 0

https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
Method 1: Bruteforce - time: O(N*N), space: O(1)
	- ans += min(maximum(arr,0,i), maximum(arr,i,n-1)) - arr[i];
Method 2: precompute max from L2R, R2L, then min(L2R, R2L) then diff(min - arr). time: O(N), space: O(2N)
Method 3: most optimal. Using left right pointer. time: O(N), space: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    // Method 1: Bruteforce - time: O(N*N), space: O(1)
	// int maximum(int arr[], int start, int end){
 //        int max = INT_MIN;
 //        for(int i=start; i<=end; i++){
 //            if(arr[i] > max)
 //                max = arr[i];
	//     }
 //        return max;
 //    }

 //    long long trappingWater(int arr[], int n){
 //        int ans=0;
 //        for(int i=0; i<n; i++){
 //            ans += min(maximum(arr,0,i), maximum(arr,i,n-1)) - arr[i];
 //        }
 //    	return ans;
	// }

  // Method 2: precompute max from L2R, R2L, then min(L2R, R2L) then diff(min - arr). time: O(N), space: O(2N)
  //   long long trappingWater(int arr[], int n){
  //   	int preComputeLR[n];
  //   	int preComputeRL[n];
		// int maxi;

		// maxi = arr[0];
  //   	for(int i=0; i<n; i++) {
  //   		maxi = max(maxi, arr[i]);
  //   		preComputeLR[i] = maxi;
  //   	}

		// maxi = arr[n-1];
  //   	for(int i=n-1; i>=0; i--) {
  //   		maxi = max(maxi, arr[i]);
  //   		preComputeRL[i] = maxi;
  //   	}

  //   	long long pr = 0;
  //   	for(int i=0; i<n; i++) {
  //   		pr += min(preComputeLR[i], preComputeRL[i]) - arr[i];
  //   	}

  //   	return pr;
  //   }

    // Method 3: most optimal. time: O(N), space: O(1)
    long long trappingWater(int arr[], int n){
        int left = 0; 
        int right = n-1;
        long long int res = 0;
        int maxleft = 0, maxright = 0;
        
        while(left <= right){
            
            if(arr[left] <= arr[right]){

                if(arr[left] >= maxleft) maxleft= arr[left];
                else res += maxleft-arr[left];
                
                left++;
            }
            else{

                if(arr[right] >= maxright) maxright=  arr[right];
                else res += maxright-arr[right];
                
                right--;
            }
        }
        return res;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        cout << obj.trappingWater(a, n) << endl;
    }
    
    return 0;
}