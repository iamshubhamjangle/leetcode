# C++ DSA Docs

Git Commands

```
git add filename.cpp / git add .
git commit -a -m ":)"
git push
```

<br>
<br>

## Index

- [Sorting & Searching Algo](https://www.youtube.com/watch?v=4gW6P5A1gxs)
  - ✅ [Binary Search](https://www.youtube.com/playlist?list=PLBsIjVjZHP8pfwgl9tb72lPadnZ_S8U_m)
  - ✅ Bubble Sort
  - ✅ Heap Sort
  - ✅ Insertion Sort
  - ✅ Merge Sort
  - ✅ Quick Sort
  - ✅ Selection Sort
- ✅ Arrays
- ✅ 2D Array - Matrix
- ✅ Strings
- [Two Pointer](https://www.youtube.com/playlist?list=PLgUwDviBIf0rBT8io74a95xT-hDFZonNs)
- [Greedy](https://www.youtube.com/playlist?list=PLgUwDviBIf0pmWCl2nepwGDO05a0-7EfJ)
- [Hashing](https://www.youtube.com/playlist?list=PLgUwDviBIf0rVwua0kKYlsS_ik_1lyVK_)
- ✅ [Recursion & Backtracking](https://www.youtube.com/playlist?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9)
- ✅ [DP](https://www.youtube.com/playlist?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY)
- ✅ [Linked List](https://www.youtube.com/playlist?list=PLKZaSt2df1gz775Mz-2gLpY9sld5wH8We)
- [Binary trees & BST](https://www.youtube.com/playlist?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)
- [Stacks and Queues](https://www.youtube.com/playlist?list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj)
- [Heaps - Priority Queue](https://www.youtube.com/playlist?list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9)
- [Graphs](https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw)
- [Bit manipulation](https://www.youtube.com/playlist?list=PLEJXowNB4kPwa5VPvdQ1U3B2yaogEGDjX)
- [Trie](https://www.youtube.com/playlist?list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp)
- [OOPS](https://www.youtube.com/watch?v=wN0x9eZLix4)

<br>
<br>

## Important Concepts

Important Sizes

```cpp
int main(){
	int arr[6] = {1,2,3,4,5,6};
	string str = "shubham";
	vector<int> vec = {1,2,3,4,5,6,7,8};

	cout << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << str.size() << endl;
	cout << vec.size() << endl;
}
```

- **Subsequences**: Contiguous/Non-Contiguous + ordered - Power Set / Recursion (take - notake) - for n there are 2^n subsequences.
- **Substring**: Contiguous + ordered
- **Super-Sequence**: After merging two numbers, ordered + non contiguous.

<br>
<br>

## Important Questions

- Longest Common Subsequence & Substring

<br>
<br>
<br>

# DSA Notes

# DP

## DP Types

- DP on grids
  - Count paths
  - Count paths with obstacles
  - Min path sum
  - Max path sum
  - Triangle
  - 2 start points with 2 people
- DP on subsequences/subarray/subsets
  - Subsets with target
  - Unbounded Knapsack - stand at the same index while recursion.
- DP on strings
  - Comparisions, Replacement, Edits
  - String Matching
- DP on stocks
  - Buy/Sell Transaction - 1, N
  - Buy/Sell K stocks - 2, N
  - Buy/Sell with capacity
  - Buy/Sell with transaction fee

### Extras

- Recursion
- Memoisation
- Memoisation (Index Shifting)
  - If base condition contains i < 0, increase the size of dp +1 and reduce the state variables -1)
  - Whenever we have curr in base condition. i.e. we need to assign column value for each row. put this in first for loop.
  - Always use m (column) / m+1 (idx shifted) size in vectors.
- Tabulation (Bottom up)
- Space Optimisation (Top down)
- Space Optimisation to single array (Move from right to left)

### Recurrence Steps:

1. Express in terms of Index.
2. Explore all possibilities.
3. Sum all possibilities/min/max

### Tabulation Steps:

1. Base cases
2. Look at the changing parameters & write nested loop

   - if base condition is `ind == n` its loop will start from n-1 to 0
   - if base condition is `cap == 0` its loop will start from n-1 to 1

3. copy the recursion

### Space Optimization Steps:

1. Declare two vectors (prev, curr) of size (column + 1) init with 0's.
2. Fill the prev vector with base conditions.
3. Replace `dp[ind-1]` with prev, and `dp[ind]` with curr.
4. End of first `for` loop. set `prev = curr`
5. return prev.

<br>
<br>
<br>

## Miscellaneous Code Snippets

```cpp
reverse(arr, arr+n);						// TC: O(N)
reverse(vector.begin(), vector.end());		// TC: O(N)
reverse(string.begin(), string.end());		// TC: O(N)

sort(vector.begin(), vector.end())		    // O(N*logN);
sort(vector.rbegin(), vector.rend());       // reverse sort
sort(...) // custom sort

// Print Vector string:
void print(vector<string> &v) {
	for(auto i: v) cout << i << ", ";
	cout << endl;
}

// Print Vector int:
void print(vector<int> &v) {
	for(auto i: v) cout << i << ", ";
	cout << endl;
}
```
