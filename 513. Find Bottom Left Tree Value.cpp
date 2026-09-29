// Solution of LeetCode Problem
// 513. Find Bottom Left Tree Value
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
// Using Breadth-First Search (BFS), Visiting Right Before Left
// Time Complexity: O(N) - Visits every node in the tree once
// Space Complexity: O(W) - The queue can hold up to W nodes, where W is the maximum tree width

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        6int ans = root->val ; 
        queue<TreeNode *> q ;
        q.push( root ) ;

        while(!q.empty()) 
        {
            int curr_level = q.size() ;
            for(int i = 0 ; i < curr_level ; i++)
            {
                TreeNode * node = q.front() ;
                q.pop() ;
                
                ans = node->val ;

                if(node->right != NULL)
                {
                    q.push( node->right ) ;
                }
                if(node->left != NULL)
                {
                    q.push( node->left ) ;
                }
            }
        }
        return ans;

    }
};

// Approach - 2
// Using Level-Order Breadth-First Search (BFS)
// Time Complexity: O(N) - Visits every node in the tree once
// Space Complexity: O(W) - The queue can hold up to W nodes, where W is the maximum tree width

class Solution1 {
public:
    int findBottomLeftValue(TreeNode* root) {

        int ans = root->val ; 
        queue<TreeNode *> q ;
        q.push( root ) ;

        while(!q.empty()) 
        {
            int curr_level = q.size() ;
            for(int i = 0 ; i < curr_level ; i++)
            {
                TreeNode * node = q.front() ;
                q.pop() ;
                if(i == 0)
                {
                    ans = node->val ;
                }
                if(node->left != NULL)
                {
                    q.push( node->left ) ;
                }
                if(node->right != NULL)
                {
                    q.push( node->right ) ;
                }
            }
        }
        return ans;
    }
};