// Solution of LeetCode Problem
// 94. Binary Tree Inorder Traversal
// Solution in CPP 

// Approach - 1
// Using Morris Algorithm
// Time Complexity: O(2N) - Visiting each node and its predecessor thread in the binary tree of size N
// Space Complexity: O(1) - Constant auxiliary space used

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode * curr = root ;
        vector<int> ans ;

        while(curr != NULL)
        {  
            // if the left child is null of current
            if(curr->left == NULL)
            {
                // if curr left child is null so visiting the node amd then move the pointer to the right side of the node
                ans.push_back(curr->val);
                curr = curr->right ;
            }
            else
            {
                
                TreeNode *predecessor = curr->left ;
                // find predecessor and creating a tempraray link to the curr node 
                while(predecessor->right != NULL && predecessor->right != curr)
                {
                    predecessor = predecessor->right;
                }
                // after finding the predecessor i.e rigth lastnode of the tree and now creating a temproary link and also moving the currnt pointer to the left subtree of the tree
                if(predecessor->right == NULL)
                {
                    // it means that left subtree is not visited
                    predecessor->right = curr ;
                    curr = curr->left; 
                }
                else
                {
                    // it tells that left subtree is already visited so do 3 works i.e 1. reset the pointer , 2. visit the current node , 3. move current ptr to right side or jump on right sub tree
                    predecessor->right = NULL ;
                    ans.push_back(curr->val);
                    curr = curr->right; 
                }
            }
        }
            return ans;

    }
};