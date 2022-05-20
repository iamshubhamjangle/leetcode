/*
Sort an array of 0s, 1s and 2s

https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

Method 1: Use temp array. time: O(N), space = O(N)
    - loop through array 3 times
    - first time if value == 0, add it to temp array
    - do this for 2 and 3. out temp array will be in sorted order
    - copy the temp array to main array

Method 2: Keep 3 counters. time: O(N), space = O(1)
    - loop through array once. increment the counter.
    - put 0, 1, 2 counter times in main array
*/



#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int temp[n];
        int j = 0;
        for(int i=0; i<n; i++){
            if(a[i] == 0) {
                temp[j] = a[i];
                j++;
            }
        }
        for(int i=0; i<n; i++){
            if(a[i] == 1) {
                temp[j] = a[i];
                j++;
            }
        }
        for(int i=0; i<n; i++){
            if(a[i] == 2) {
                temp[j] = a[i];
                j++;
            }
        }
        for(int i=0; i<n; i++){
            a[i] = temp[i];
        }
    }

   // Method2 : counter
   // int count1 = 0;
   // int count2 = 0;
   // int count3 = 0;
   // for(int i =0; i < n; i++){
   //     if(a[i] == 0){
   //         count1++;
   //     }
   //      if(a[i] == 1){
   //         count2++;
   //     }
   //      if(a[i] == 2){
   //         count3++;
   //     }
   // }
   // for(int i =0; i < count1; i++){
   //     a[i]=0;
   // }
   //  for(int i =count1; i < count1 + count2; i++){
   //     a[i]=1;
   // }
   //  for(int i =count1 + count2; i < n; i++){
   //     a[i]=2;
   // }
};

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}
