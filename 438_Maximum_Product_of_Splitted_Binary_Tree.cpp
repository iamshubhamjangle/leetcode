/*
Maximum_Product_of_Splitted_Binary_Tree.cpp

https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
*/

// Observation
// The easiest way to do this is to check the sum of each subtree and subtract it with total sum of the tree to get sum of both the trees when the current subtree is removed.

static int MOD = 1e9+7;
class Solution {
public:
    long long totalTreeSum = 0;
    long long result = 0;

    void getTotalTreeSum(TreeNode* root) {   //Get total sum of the tree.
        if(!root) return;

        totalTreeSum += root->val;
        getTotalTreeSum(root->left);
        getTotalTreeSum(root->right);
    }

    int SumUnder(TreeNode* root) {             //Get the totalSum under the node `root` including root.
       if(!root) return 0;

       // Get the sum of left and right subtree under node 'root'
       int sumUnderLeft  = SumUnder(root->left);
       int sumUnderRight = SumUnder(root->right);

       // Get the max product after making left or right subtrees as seprarate tree.
       result = max({ result, (totalTreeSum-sumUnderLeft)*sumUnderLeft, (totalTreeSum-sumUnderRight)*sumUnderRight });

       return sumUnderLeft + sumUnderRight + root->val;
    }

    int maxProduct(TreeNode* root) {
        getTotalTreeSum(root);
        SumUnder(root);
        return result%MOD;
    }
};