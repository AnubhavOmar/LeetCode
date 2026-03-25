// Solution of LeetCode Problem 
// 563. Binary Tree Tilt
// Solution in CPP 

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
int total_tilt = 0 ; // tilt formula = abs(left_sum - right_sum) 
    int findTilt(TreeNode* root) {
        dfs(root);
        return total_tilt ;
    }

    int dfs(TreeNode *node)
    {

        if(node == NULL) return 0 ;

        // recursive call for childs 
        int left_sum = dfs(node->left);
        int right_sum = dfs(node->right);

        total_tilt += abs(left_sum - right_sum) ;
        // at every node updating the total tilt 

        return left_sum + right_sum + node->val ;

    }

};