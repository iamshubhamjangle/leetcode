# leetcode
```
git add filename.cpp / git add .
git commit -a -m ":)"
git push
```

# Questions
```
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

Todo:
	- Binary Search
	- Selection Sort
	- Bubble Sort
	- Insertion Sort

## Notes
### Print Vector string:
```
vector<int> counter(string &s) {
	vector<int> count(26);
	for(char c: s) count[c - 'a']++;
	return count;
}
```

### Recurrence: Count no of ways.
1. Express in terms of Index.
2. Explore all possibilities.
3. Sum all possibilities.

## DP Types
- Unbounded Knapsack - stand at the same index while recursion.
