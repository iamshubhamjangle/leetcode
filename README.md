# Coding Docs
Git Commands
```
git add filename.cpp / git add .
git commit -a -m ":)"
git push
```

## Index
```
Sorting & Searching Algo: 0 - 0
Arrays 					: 1  - 33
Matrix 					: 34 - 44
Strings 				: 
Searching and Sorting 	: 
Linked List 			: 
Bit manipulation 		: 
Greedy 					: 
Backtracking 			: 
DP 						: 
Stacks and Queues 		: 
Binary trees 			: 
BST 					: 
Graphs 					: 
Heaps 					: 
Trie 					: 
```

Index:
- Sorting & Searching Algo
	- Binary Search
	- Bubble Sort
	- Heap Sort
	- Insertion Sort
	- Merge Sort
	- Quick Sort
	- Selection Sort



## Code Snippets
```cpp
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



# Notes
# DP
## DP Types
- DP on grids
	- Count paths
	- Count paths with obstacles
	- Min path sum
	- Max path sum
	- Triangle
	- 2 start points with 2 people
- DP on subsequences/substrings/subarray/subsets
	- Subsets with target
	- Unbounded Knapsack - stand at the same index while recursion.


### Extras
- Recursion
- Memoisation
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

