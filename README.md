# C++ DSA Docs

Git Commands

```
git add filename.cpp / git add .
git commit -a -m ":)"
git push
```
```cpp
(2^n) can be written in c++ as (1<<n)
```
<br>
<br>

## Index

- ✅ [Sorting & Searching Algo](https://www.youtube.com/watch?v=4gW6P5A1gxs)
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
- ✅ [Two Pointer](https://www.youtube.com/playlist?list=PLgUwDviBIf0rBT8io74a95xT-hDFZonNs)
- ✅ [Greedy](https://www.youtube.com/playlist?list=PLgUwDviBIf0pmWCl2nepwGDO05a0-7EfJ)
- ✅ [Hashing](https://www.youtube.com/playlist?list=PLgUwDviBIf0rVwua0kKYlsS_ik_1lyVK_)
- ✅ [Recursion & Backtracking](https://www.youtube.com/playlist?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9)
- ✅ [DP](https://www.youtube.com/playlist?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY)
- ✅ [Linked List](https://www.youtube.com/playlist?list=PLKZaSt2df1gz775Mz-2gLpY9sld5wH8We)
- ✅ [Binary trees & BST](https://www.youtube.com/playlist?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)
- ✅ [Stacks and Queues](https://www.youtube.com/playlist?list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj)
- ✅ [Heaps - Priority Queue](https://www.youtube.com/playlist?list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9)
- ✅ [Bit manipulation](https://www.youtube.com/playlist?list=PLEJXowNB4kPwa5VPvdQ1U3B2yaogEGDjX)
- ✅ [Graphs](https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw) - BFS, DFS, Cycle, Bipartite, TopoSort, ShortestPath, Dijkstra(weighted)
- ✅ [OOPS](https://www.youtube.com/watch?v=wN0x9eZLix4)
- [Trie](https://www.youtube.com/playlist?list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp)

<br>
<br>

## Important Concepts

Comparator
```cpp
sort(score.begin(), score.end(), [k](vector<int>& a, vector<int>& b) { return a[k] > b[k]; });
```


Sizes

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

String/Array Types

- **Subsequences**: Contiguous/Non-Contiguous + ordered - Power Set / Recursion (take - notake) - for n there are 2^n subsequences.
- **Substring**: Contiguous + ordered
- **Super-Sequence**: After merging two numbers, ordered + non contiguous.

<br>
<br>

## Constraints

By looking at the constraints of a problem, we can often "guess" the solution.
Common time complexities
Let n be the main variable in the problem.

```
If n ≤ 12, the time complexity can be O(n!).
If n ≤ 25, the time complexity can be O(2n).
If n ≤ 100, the time complexity can be O(n4).
If n ≤ 500, the time complexity can be O(n3).
If n ≤ 104, the time complexity can be O(n2).
If n ≤ 106, the time complexity can be O(n log n).
If n ≤ 108, the time complexity can be O(n).
If n > 108, the time complexity can be O(log n) or O(1).
Examples of each common time complexity

O(n!) [Factorial time]: Permutations of 1 ... n
O(2n) [Exponential time]: Exhaust all subsets of an array of size n
O(n3) [Cubic time]: Exhaust all triangles with side length less than n
O(n2) [Quadratic time]: Slow comparison-based sorting (eg. Bubble Sort, Insertion Sort, Selection Sort)
O(n log n) [Linearithmic time]: Fast comparison-based sorting (eg. Merge Sort)
O(n) [Linear time]: Linear Search (Finding maximum/minimum element in a 1D array), Counting Sort
O(log n) [Logarithmic time]: Binary Search, finding GCD (Greatest Common Divisor) using Euclidean Algorithm
O(1) [Constant time]: Calculation (eg. Solving linear equations in one unknown)
```

## Important Questions

- Longest Common Subsequence & Substring

<br>
<br>

# DSA Notes

## Seaching and Sorting

### Binary search

```cpp
vector<int>::iterator lower = lower_bound(v.begin(), v.end(), 6);     // pointer not less than 6
vector<int>::iterator upper = upper_bound(v.begin(), v.end(), 6);     // pointer  greater than 6
```

<br>
<br>
<br>

## DP

**DP Types**

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

#### DP Notes

- Recursion
- Memoisation
- Memoisation (Index Shifting)
  - If base condition contains i < 0, increase the size of dp +1 and reduce the state variables -1)
  - Whenever we have curr in base condition. i.e. we need to assign column value for each row. put this in first for loop.
  - Always use m (column) / m+1 (idx shifted) size in vectors.
- Tabulation (Bottom up)
- Space Optimisation (Top down)
- Space Optimisation to single array (Move from right to left)

#### Recurrence Steps:

1. Express in terms of Index.
2. Explore all possibilities.
3. Sum all possibilities/min/max

#### Tabulation Steps:

1. Base cases
2. Look at the changing parameters & write nested loop

   - if base condition is `ind == n` its loop will start from n-1 to 0
   - if base condition is `cap == 0` its loop will start from n-1 to 1

3. copy the recursion

#### Space Optimization Steps:

1. Declare two vectors (prev, curr) of size (column + 1) init with 0's.
2. Fill the prev vector with base conditions.
3. Replace `dp[ind-1]` with prev, and `dp[ind]` with curr.
4. End of first `for` loop. set `prev = curr`
5. return prev.

<br>
<br>
<br>

## Miscellaneous Code Snippets

**Reverse, Sort**

```cpp
reverse(arr, arr+n);						// TC: O(N)
reverse(vector.begin(), vector.end());		// TC: O(N)
reverse(string.begin(), string.end());		// TC: O(N)

sort(vector.begin(), vector.end())		          // sort - O(N*logN);
sort(vector.rbegin(), vector.rend());           // decending
sort(arr, arr+n, greater<int>());               // decending
sort(nums.begin(), nums.end(), greater<int>()); // decending

sort(arr, arr+n, comparator) // custom sort
bool comparator(<T> a, <T> b) {
  return true;    // noswap
  return false;   // swap
}

// Quicksort, Heapsort and Insertion Sort
```

**Printing**

```cpp
// Print vector<T>:
template<typename T>
void print(vector<T> &v) {
  cout << "vector<T> = [";
  for(int i=0; i<v.size(); i++) { cout << v[i]; if(i<v.size()-1) cout << ","; }
  cout << "]" << endl;
}

// Print vector<vector<string>>
void print(vector<vector<string>> &v) {
  cout << "vector<vector<string>> = [";
  for(auto i: v) { cout << "["; for(auto j: i) cout << j << ","; cout << "]"; }
  cout << "]" << endl;
}
```

**Iterating**

```cpp
// Iterate unordered_map
for (auto i : m)
  cout << i.first << "    " << i.second
```

**Comparator**

```cpp
bool comparator(struct meeting m1, meeting m2) {
    if(condition) return true;    // no swap
    return false;                 // swap
}

sort(meet, meet+n, comparator);
```

**Maps**

```cpp
if(umap.find(num) != um.end()) // number present in unorderedmap

unordered_set<int> s(begin(nums), end(nums));
```

<br>
<br>
<br>

## Trees

#### Bottom View of Binary Tree

```
BFS => Queue, Vertical Line Info => Map

As this is BFS traversal, if we use DFS, right side of the tree nodes will be considered later
this may cause using prev level node appearing in the line map.
```

#### Complete Binary Tree

Tree which is completed filled except the last level where the node are filled from left to right
TC: O(N) SC: O(log N)

#### Full Binary Tree

All the nodes are completely filled.
TC: O(N), # nodes = (2^h - 1) SC: O(log N)

#### Binary Search Tree

**Inorder** traversal for BST is always sorted.

<br>
<br>
<br>

## Heap - Priority Queue

Question ask find largest/smallest/top/bottom/frequent/closest k elements.

Types

- Min Heap
  `priority_queue<int, vector<int>, greater<int>> minPQ`
  ```
  typedef pair<int, pair<int, int> ppi;
  priority_queue<ppi, vector<ppi>, greater<ppi> minPQ;
  ```
- Max Heap
  `priority_queue<int> maxPQ`

Identification
K + smallest = max heap
K + largest = min heap

Normally can be solved by sorting (nlogn), but K is provided so that you can reduce it to (nlogk).
Heap doesnt gaurentee the elements are in sorted only the top element is max.

<br>
<br>
<br>

## Graph

Nodes connected with edges is a graph. A graph can be consisting of several components.

Types:

- Directed
- Undirected
- Weighted

Traversal

- DFS (recursive & visited[])
- BFS (using queue & visited[])

Adjacency List

```cpp
vector<int> adj[];              // unweighted [{node1, node2},...]
vector<pair<int, int>> adj[];   // weighted [{{node1, weight1},{}},...]
```

### Problems

1. Detect a cycle

   - BFS: Found a node visited but not equal to prev it's a cycle. Use `visited[]` and `queue<int, prev>`
   - DFS: Found a node visited but not equal to prev it's a cycle. Use `visited[]` and `prev`

2. Bipartite

   - BFS: If node is uncolored, color it using -1 \* prevColor. If colored check if its equal to prevColor. If equal return false; else true;. Use `visited[]` and `queue<int, prev>`
   - DFS: If node is uncolored, color it using -1 \* prevColor. If colored check if its equal to prevColor. If equal return false, else true. Use `visited[]` and `prev`

3. Topo Sort

   - BFS: (Kahn's Algorithm) Find all indegree. Push 0th indegree to `queue` and `bfsVisited`. Reduce the indegree of adj if indegree == 0 push it to queue.
   - DFS: Visit all nodes till end while coming back push them to vector.

4. Shortest Path (Undirected, Unit weight)

   - BFS:

   ```cpp
   // Push src = 0 to queue.
   while(!q.empty()) {
     if(dist[node] + 1 < dist[it])
       q.push(it);
   }
   ```

5. Shortest Path (Directed Acyclic Graph, Unit weight)

   - DFS: First find topo sort

   ```cpp
     dist[src] = 0;
     if(dist[node] + it.second < dist[it.first])
       dfs();
   ```

6. Shortest Path (Weighted)

   - BFS (Dijsktra Algorithm) Use `priority_queue<minheap>` for implementation.

7. MST (Minimum Spanning Tree)
   - Tree where nodes are N and Edges are N-1.
   - We can convert a normal graph to MST using
     - Prims Algorithm
     - Kruskal Algorithm
