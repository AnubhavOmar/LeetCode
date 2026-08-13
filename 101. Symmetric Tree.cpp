// Solution of LeetCode Problem
// 101. Symmetric Tree
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

// Approach - 1
// Using Recursion (DFS Comparison)
// Time Complexity: O(N) - Traversing each node in the binary tree of size N once
// Space Complexity: O(H) - Recursive call stack space proportional to the height H of the binary tree
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return comparee(root->left , root->right);
    }
    
    bool comparee(TreeNode * p , TreeNode * q)
    {
        if(p == NULL && q == NULL)
        {
            return true ;
        }
        else if(p == NULL || q == NULL)
        {
            return false ;
        }
        else if(p->val != q->val )
        {
            return false ;
        }
        
        bool left = comparee(p->left , q->right);
        bool right = comparee(p->right , q->left);
        
        return left && right ;
        
    }
};

// Approach - 2
// Using Tree Inversion and Comparison
// Time Complexity: O(N) - Inverting the left subtree and comparing both subtrees of size N
// Space Complexity: O(H) - Recursive call stack space proportional to the height H of the binary tree
class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {

        TreeNode *temp = root->left ;
        invert(temp);
        return comparee(root->left , root->right);
    }

    void invert(TreeNode * node ) 
    {
        if(node == NULL)
        {
            return ;
        }
        
        invert(node->left);
        invert(node->right);
        swap(node->left,node->right); 
    }

    bool comparee(TreeNode * p , TreeNode * q)
    {
        if(p == NULL && q == NULL)
        {
            return true ;
        }
        else if(p == NULL || q == NULL)
        {
            return false ;
        }
        else if(p->val != q->val)
        {
            return false;
        }

        bool left = comparee(p->left , q->left);
        bool right = comparee(p->right , q->right);

        return left && right; 

    }

};