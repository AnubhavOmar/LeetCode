// Solution of LeetCode Problem
// 111. Minimum Depth of Binary Tree
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
// Using Breadth-First Search (BFS) with Queue
// Time Complexity: O(N) - In the worst case, traversing all nodes in the binary tree of size N until the first leaf node is found
// Space Complexity: O(W) - Queue space proportional to the maximum width W of the binary tree
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int depth = 1;

        while(!q.empty())
        {
            int curr_level = q.size();

            for(int i = 0; i < curr_level; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left == NULL && node->right == NULL)
                {
                    return depth;
                }

                if(node->left != NULL)
                {
                    q.push(node->left);
                }

                if(node->right != NULL)
                {
                    q.push(node->right);
                }
            }

            depth++;
        }

        return depth;
    }
};


// Approach - 2
// Using Recursion (Depth-First Search)
// Time Complexity: O(N) - Visiting every node in the binary tree of size N in the worst case
// Space Complexity: O(H) - Recursive call stack space proportional to the height H of the binary tree
class Solution1 {
public:
    int minDepth(TreeNode* root) {
        
        if(root == NULL) return 0 ;


        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if(left == 0)
            return right + 1;

        if(right == 0)
            return left + 1;

        return min(left,right) + 1;
    }
};