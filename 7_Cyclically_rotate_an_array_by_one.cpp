/*
Cyclically_rotate_an_array_by_one 
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

// void rotate(int arr[], int n)
// {
//     for(int i=n-1;i>0;i--)
//     {
//         swap(arr[i],arr[i-1]);
//     }
// }