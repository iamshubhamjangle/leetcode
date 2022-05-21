/*
Cyclically_rotate_an_array_by_one 

Given an array, rotate the array by one position in clock-wise direction.

Input:
N = 5
A[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4

https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0
Method 1: Use temp var and loop over and replace. time = O(N), space: O(1)

*/

#include <stdio.h>

void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}

void rotate(int arr[], int n)
{
	int lastValue = arr[n-1];
	int j;
	for(j=n-1; j!=0; j--) {
		arr[j] = arr[j-1];
	}
	arr[j] = lastValue;
}
