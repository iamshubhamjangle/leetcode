/* 
Binary_Search_in_C++.cpp


*/

#include <iostream>
using namespace std;

// Iterative
int binarySearchIterative(int arr[], int x, int low, int high) {
  while(low < high) {
    int mid = (low + high) / 2;
    if(x == arr[mid])
      return mid;
    else if(x < arr[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  return -1;
}

// Recursive
int binarySearchRecursive(int arr[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (arr[mid] == x)
      return mid;

    // Search the left half
    if (arr[mid] > x)
      return binarySearchRecursive(arr, x, low, mid - 1);

    // Search the right half
    return binarySearchRecursive(arr, x, mid + 1, high);
  }

  return -1;
}


int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9};
   int n = sizeof(array) / sizeof(array[0]);
  int x = 8;           //  number to find

  cout << binarySearchIterative(array, x, 0, n - 1);
  cout << endl;
  cout << binarySearchRecursive(array, x, 0, n - 1);

}