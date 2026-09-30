// Solution of LeetCode Problem
// 662. Maximum Width of Binary Tree
// Solution in CPP

// Approach - 1
// Using Breadth-First Search with Index Encoding
// Time Complexity: O(n) - Each node is visited once in level-order traversal.
// Space Complexity: O(w) - The queue holds the current level, where w is the maximum width of the tree.

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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        queue<pair<TreeNode * , long long>> q ;
        q.push({root , 0}) ;

        int ans = 1 ;

        while(!q.empty())
        {
            int size = q.size() ;
            long long minn = q.front().second ;
            
            long long first , last ;
            
            for(int i = 0 ; i < size ; i++)
            {
                long long index = q.front().second - minn ;
                TreeNode * node = q.front().first ;

                q.pop() ;

                if(i == 0) first = index ;
                if(i == size - 1) last = index ;
                
                if(node->left != NULL)
                {
                    q.push({ node->left , 2 * index + 1 } ) ;
                }
                if(node->right != NULL)
                {
                    q.push({ node->right , 2 * index + 2 } ) ;
                }
            }
            ans = max(ans , int(last - first + 1)) ;
        }
        return ans;
    }
};