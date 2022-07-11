/*
Non_Repeating_Numbers.cpp

Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers 
exist in pairs whereas the other two number occur exactly once and are distinct. 
Find the other two numbers.

Input : N = 2, arr[] = {1, 2, 3, 2, 1, 4}
Output: 3 4

Input : N = 1, arr[] = {2, 1, 3, 2}
Output: 1 3 

https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1
Method 1: Bruteforce: TC: O(N*N) SC: O(1)
Method 2: Unordered_map: TC: O(N) SC: O(N)
Method 3: Bit manipulation: TC: O(N) SC: O(1) 

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> nums) {
        int n = nums.size();
        cout << endl;
        // calculate XOR of all nums, we will get the sum or two distinct nums
        int XOR = nums[0];
        for(int i=1; i<n; i++)
            XOR ^= nums[i];
            
        // get the rightmost setbit of XOR
        int rightBit = XOR & ~(XOR-1);
        
        // Now lets & the rightmost bit with each int, Those with true are our int 1 and false are int 2
        // keep ^ XOR them in x, y finally {x,y} will be the ans.
        int x=0, y=0;
        for(int i=0; i<n; i++) {
            if(nums[i] & rightBit)
                x ^= nums[i];
            else
                y ^= nums[i];
        }
        
        return {min(x,y), max(x,y)};
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends