// Solution Of LeetCode Problem 
// 110. Balanced Binary Tree
// Solution in CPP

// Approach - 1 (Using DFS)

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
    bool isBalanced(TreeNode* root) {
        DFS(root);
        return ans; 
    }
    bool ans = true; 
    int DFS(TreeNode* node)
    {
        if(node == NULL ) return 0 ;
        // base case 

        // recurseive case 
        int left = DFS(node->left);
        int right = DFS(node->right);

        

        if( abs(left - right) > 1 && ans )
        {
            ans = false ;
        }
        return max(left,right)+1; // this is returning that which side of tree has max size beacuse that will be used to calculate the height of the tree 
    }

};
