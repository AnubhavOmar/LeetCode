// Solution of LeetCode Problem
// 112. Path Sum
// Solution in CPP

// Approach - 1
// Using Recursion (Depth-First Search)
// Time Complexity: O(N) - Visiting every node in the binary tree of size N in the worst case
// Space Complexity: O(H) - Recursive call stack space proportional to the height H of the binary tree
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
         if(root == NULL && targetSum == 0 ) return false;
        return DFS(root , targetSum , 0);
    }

    bool DFS(TreeNode * node , int target , int sum )
    {
        if(node == NULL)
        {
           return false ;
        }

        sum += node->val ;

        if(node->left == NULL && node->right == NULL )
        {
            return sum == target;
        }
        
        bool left = DFS(node->left , target , sum);
        bool right =  DFS(node->right , target , sum);

        return  left || right  ;

    }
};