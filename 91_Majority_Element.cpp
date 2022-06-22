/*
Majority_Element.cpp

Given an array A of N elements. Find the majority element in the array. 
A majority element in an array A of size N is an element that appears 
more than N/2 times in the array.

Input : N = 3, A[] = {1,2,3} 
Output: -1

Input : N = 5 , A[] = {3,1,3,3,2} 
Output: 3

https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#
	Method 1: Using unordered_map TC: O(N). SC: O(N)
	Method 2: Using Moore's Algorithm TC: O(N). SC: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  	// Using unordered_map TC: O(N). SC: O(N)
    int majorityElement1(int a[], int size) {
        int minCount = size / 2;

        unordered_map<int, int> um;

        for(int i=0; i<size; i++)
        	um[a[i]]++;

        int ans = -1;
		for(auto i: um) {
			if(i.second > minCount) {
				ans = i.first;
			}
		}

		return ans > size/2 ? ans : -1;
    }

    // Using Moore's Algorithm TC: O(N). SC: O(1)
    int majorityElement(int a[], int size) {
        if(size==1){
           return a[0];
        }
        int count=0;
        int temp=0;
        
        int ab=(int)(size/2);
        for(int i=0;i<size;i++){//3 1 3 3 2
            if(count==0){
                temp=a[i];      //3 3
            }
            if(temp==a[i]){
                count++;
            } else {            //2
            count--;
            }           //1
        }
        
        for(int i=0;i<size;i++) {
            if(a[i]==temp)
                count++;
        }
        
        if(count>ab)
            return temp;
        else
            return -1;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
        cout << "-------------------------" << endl;
    }
    return 0;
}