/*
Sorting_Elements_of_an_Array_by_Frequency.cpp

Given an array A[] of integers, sort the array according to frequency of elements. 
That is elements that have higher frequency come first. If frequencies of two elements 
are same, then smaller number comes first.

Example:
Input:
2
5
5 5 4 6 4
5
9 9 9 2 5

Output:
4 4 5 5 6
9 9 9 2 5

https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0
	Method1: Using custom sort comparator TC: O(N*logN) SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int,int> p1, pair<int,int> p2){
    if(p1.second == p2.second){		// if both frequency are equal
      return p1.first < p2.first;	// return the one with small first value
    }
    return p1.second > p2.second;	// if freq not equal return the one with more frequency
}

void Sort_Array_by_Freq (){
    int n;
    cin >> n;
    
    vector<pair<int,int>> vp(61);
    
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;

      vp[x].first = x;
      vp[x].second = (vp[x].second)+1;
    }

    // for(auto i: vp){
    //   cout << "first: " <<i.first<< " second: " << i.second << endl;
    // }

    sort(vp.begin(),vp.end(),comparator);
    
    for(auto p: vp){
        int t = p.second;
        while(t--){
          cout << p.first << " ";
        }
    }
}

int main() {
  int t;
  cin >> t;
  
  while(t--){
      Sort_Array_by_Freq();
      cout << endl;
  }
  return 0;
}