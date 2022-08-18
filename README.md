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

1. Sorting & Searching Algo
   - Binary Search
   - Bubble Sort
   - Heap Sort
   - Insertion Sort
   - Merge Sort
   - Quick Sort
   - Selection Sort
2. Searching and Sorting
3. Arrays
4. Matrix
5. Strings
6. Greedy
7. Backtracking
8. DP
9. Linked List
10. Stacks and Queues
11. Heaps - Priority Queue
12. Binary trees
13. BST
14. Graphs
15. Bit manipulation
16. Trie

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

sort()		// O(N*logN);

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
