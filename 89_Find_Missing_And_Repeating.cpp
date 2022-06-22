/*
Find_Missing_And_Repeating.cpp
Medium_Accuracy: 37.77% Submissions: 100k+ Points: 4.cpp

Given an unsorted array Arr of size N of positive integers. 
One number 'A' from set {1, 2, …N} is missing and one number 
'B' occurs twice in array. Find these two numbers.

Input : N = 2, Arr[] = {2, 2}
Output: 2 1

Input : N = 3, Arr[] = {1, 3, 3}
Output: 3 2

6 = [1,10,3,4,5,6]
if i is the index
missing = i+1;
temp = arr[i];
if(temp == arr[i]) duplicate = temp;

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ N
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int *findTwoElement(int *a, int n) {
        int *answer=new int[2]{-1};
        int i=0;
        int value=0;
        int element=0;
        
        for(i=0; i<n;i++){
            value = abs(a[i]);
            element = a[value-1];
            if(element > 0) a[value-1] = -element;
            else answer[0]=value;
        }
        for(i=0;i<n;i++){
            if(a[i]>0){
                answer[1]=i+1;
                break;
            }
        }
        return answer;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
