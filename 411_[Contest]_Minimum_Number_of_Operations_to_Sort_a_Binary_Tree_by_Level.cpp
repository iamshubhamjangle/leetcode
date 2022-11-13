/*
[Contest]_Minimum_Number_of_Operations_to_Sort_a_Binary_Tree_by_Level.cpp

https://leetcode.com/contest/weekly-contest-319/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/
*/



class Solution {
public:
    int minSwaps(int arr[], int n) {
        pair<int, int> arrPos[n]; // {element, pos}
        for (int i = 0; i < n; i++) {
            arrPos[i].first = arr[i];
            arrPos[i].second = i;
        }

        sort(arrPos, arrPos + n);
        vector<bool> vis(n, false);
        int ans = 0;

        // Traverse array elements
        for (int i = 0; i < n; i++) {
            // already swapped and corrected or  already present at correct pos
            if (vis[i] || arrPos[i].second == i)
                continue;

            // find out the number of  node in  this cycle and add in ans
            int cycle_size = 0;
            int j = i;
            while (!vis[j]) {
                vis[j] = 1;
                j = arrPos[j].second;
                cycle_size++;
            }

            // Update answer by adding current cycle.
            if (cycle_size > 0)
                ans += (cycle_size - 1);
        }

        return ans;
    }

    int minimumOperations(TreeNode* root) {
    	int ans = 0;
    	if(root == NULL) return ans;

    	queue<TreeNode*> q;
    	q.push(root);

    	while(!q.empty()) {
    		int size = q.size();
    		int arr[size];
    		// arr

    		for(int i=0; i<size; i++) {
    			TreeNode* node = q.front(); q.pop();
    			if(node->left) q.push(node->left);
    			if(node->right) q.push(node->right);

    			// arr.push_back(node->val);
    			arr[i] = node->val;
    		}

        	ans += minSwaps(arr, size);
    	}

        return ans;
    }
};