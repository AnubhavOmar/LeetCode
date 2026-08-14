// Solution of LeetCode Problem
// 103. Binary Tree Zigzag Level Order Traversal
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
// Using Breadth-First Search (BFS) with Queue and Level Reversal Flag
// Time Complexity: O(N) - Visiting every node in the binary tree of size N once
// Space Complexity: O(W) - Queue space proportional to the maximum width W of the binary tree
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {} ;

        queue<TreeNode *>q;

        vector<vector<int>> answer;

        q.push(root);
        
        bool flag = false;

        while(!q.empty())
        {

            int current_level = q.size();


            vector<int>curr_level_nodes ;
            for(int i = 0 ; i < current_level ; i++)
            {
                TreeNode * node = q.front() ;
                q.pop() ;

                curr_level_nodes.push_back(node->val);
                
                if(node->left != NULL)
                {
                    q.push(node->left) ;
                }
                
                if(node->right != NULL)
                {
                    q.push(node->right) ;
                }
            }

            if(flag)
            {
                reverse(curr_level_nodes.begin() , curr_level_nodes.end()) ;
            }
            answer.push_back(curr_level_nodes);
            flag = !flag;
        }
        return answer;
    }
};