
// 94. Binary Tree Inorder Traversal
// Solution in CPP 

// Appraoch - 1 Morris Algorithm  
// time complexity = O(2n)
// space complixity = O(1)

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
    vector<int> inorderTraversal(TreeNode* root) {

        TreeNode* curr = root;
        TreeNode* pred;
        vector<int> ans;

        while (curr != NULL) {

            // This should be == NULL
            if (curr->left == NULL) {

                ans.push_back(curr->val);
                curr = curr->right;
            }

            else {

                // Predecessor only when left exists
                pred = curr->left;  // find the predecessor 

                while (pred->right != NULL && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == NULL) { // if not visited before 

                    // establishing a link to go back to current node 
                    pred->right = curr;
                    curr = curr->left;
                }

                else {  // if already visited

                    // restore the tree structure
                    pred->right = NULL;

                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};
