// Solution of LeetCode Problem 
// 979. Distribute Coins in Binary Tree
// Solution in CPP 

// Approach - 1 (Using DFS and post order traversal)

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
    int distributeCoins(TreeNode* root) {
        DFS(root , 0);
        return move;
    }
    int move = 0 ;
    int DFS(TreeNode * node , int extra_coin)
    {
        if(node == NULL)
        {
            return 0 ;
        }
        int left_coin = DFS(node->left , extra_coin);
        int right_coin = DFS(node->right , extra_coin);
        
        extra_coin = left_coin + right_coin + node->val - 1 ; // main formula to calculate extra coins
        move += abs(left_coin) + abs(right_coin);  // formula to calculate the moves 

        return extra_coin;
    }

};