/*
Minimum_number_of_jumps.cpp

time: O(N), space: O(1)
1
10
2 3 1 1 2 4 2 0 1 1
11
1 3 5 8 9 2 6 7 6 8 9
7
0 1 0 3 2 6 7
7
1 4 3 2 6 7
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int getNextElementAfterJump(int index, int valueAtIndex, int arr[]) {
        int max = arr[index];
        int maxIndex = index;
        while(index <= valueAtIndex) {
            if(arr[index] > max) {
                maxIndex = index;
            }
            index++;
        }
        cout << "maxIndex: " << maxIndex << " index: "<< index << " valueAtIndex: " << valueAtIndex << endl;

        return maxIndex;
    }

    int minJumps(int arr[], int n){
        if(n <= 1) return 0;
        if(arr[0] == 0) return -1;

        int maxReach = arr[0];
        int step = arr[0];
        int jump = 1;
        int i;
        for(i=1; i<n; i++) {
            if(i == n-1) return jump;
            maxReach = max(maxReach, i + arr[i]);
            step--;
            if(step == 0) {
                jump++;
                if(i >= maxReach) return -1;
                step = maxReach - i;
            }
        }
        return -1;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}