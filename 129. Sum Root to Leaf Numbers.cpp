// Solution of LeetCode Problem 
// 129. Sum Root to Leaf Numbers
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

// Approach - 1 (Using Recursion)
class Solution1 {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0 ;
        dfs(root , 0 , sum);
        return sum ;
    }
    
    void dfs(TreeNode* node , int currno , int& sum)
    {
        if(node == NULL)
        {
            return ;
        }
        // following pre order traversal 

        currno = currno * 10 + node->val ;

        // Only adding the child when the node is at child node 
        if(node->left == NULL && node->right == NULL)
        {
            sum += currno ;
        }

        dfs(node->left , currno , sum);
        dfs(node->right , currno , sum);

        return ;
    }

};git