/* Longest_consecutive_subsequence.cpp
Given an array of positive integers. 
Find the length of the longest sub-sequence such that elements in 
the subsequence are consecutive integers, 
the consecutive numbers can be in any order.

Example 1:
Input:	N = 7,	a[] = {2,6,1,9,4,5,3}
Output:	6

https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
Method 1: sort and increase the count. O(N log N)
	- sort
	- increment count if consecutive element is one higher
	- skip the count if both elements are same

Method 2: Using unordered_map, map.count(x). time: O(N), space: O(N)
    - add to un-map
    - check if prev element exist in map.
    - if it doesn't exist. we are at first element. do element++ until values doesn't exist. keep a count also return it.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  	// // Method 1: sort and increase the count. O(N log N)
   //  int findLongestConseqSubseq(int arr[], int n) {
   //  	sort(arr, arr+n);
   //  	for(int i=0; i<n; i++) {
	  //   	cout << arr[i] << " "; 
   //  	}
   //  	cout << endl;

   //  	int count=0;
   //  	int temp=0;

   //  	for(int i=0; i<n; i++) {
   //  		if(arr[i] == arr[i+1] - 1) {
   //  			temp++;
   //  		} else if (arr[i] == arr[i+1]) {
   //  			continue;
   //  		}
   //  		else {
   //  			count = max(count, temp);
   //  			temp = 0;
   //  		}
   //  	}

   //  	return ++count;
   //  }
	
	// Method 2: Using unordered_map, map.count(x). time: O(N), space: O(N)
    // Put elements in map, we don't care about duplicate hence put map[a[x]] = 1
    // loop over array check if previous element exist. 
    //      if yes, go to next array element
    //      if no, start from current element and check next elements exist or not increase count if they exist. keep a local count, compare with global count and return.
    int findLongestConseqSubseq(int arr[], int n) {
        unordered_map<int, int> um;
        for(int i=0; i<n; i++) {
            um[arr[i]] = 1;
        }

        int count = 0;
        for(int i=0; i<n; i++) {
            int x = arr[i];
            int localCount = 0;
            if(um.count(x - 1) > 0) continue;
            while(um.count(x) > 0) {
                localCount++;
                x++;
            }
            count = max(count, localCount);
        }
        return count;
    }


    // 2. Optimised. UnorderedSet -> Iterate (find min and count) TC: O(3N) SC: O(N)
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());    // this is faster
        // for(auto i: nums) us.insert(i);

        int maxCount = 0;
        for(auto &i: nums) {
            if(us.find(i-1) == us.end()) {
                int count = 0;
                while(us.find(i) != us.end()){
                    count++;
                    i++;
                }
                maxCount = max(count, maxCount);
            }
        }

        return maxCount;
    }
};

int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}