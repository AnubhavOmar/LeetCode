// Solution of LeetCode Problem
// 108. Convert Sorted Array to Binary Search Tree
// Solution in CPP

// Approach - 1
// Using Recursion and Divide and Conquer
// Time Complexity: O(n) - Each array element is processed once to create a tree node.
// Space Complexity: O(log n) - The recursion stack has a maximum depth of O(log n) for the balanced tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int st = 0 ;
        int end = nums.size() - 1 ;
        int mid = (st + end) / 2 ;

        TreeNode * node = new TreeNode(nums[mid]) ;

        node->left = helper(node , st , mid - 1 , nums) ;
        node->right = helper(node , mid + 1 , end , nums) ;

        return node ;
    }
    TreeNode *  helper(TreeNode * node , int st , int end , vector<int> & nums)
    {
        if(st > end) return NULL ;

        int mid = (st + end) / 2 ;

        TreeNode * new_node = new TreeNode(nums[mid]);

        new_node->left = helper(new_node , st , mid - 1 , nums ) ;

        new_node->right = helper(new_node , mid + 1 , end , nums ) ;
        
        return new_node; 
    }
};