// Solution of LeetCode Problem
// 106. Construct Binary Tree from Inorder and Postorder Traversal
// Solution in CPP

// Approach - 1
// Using Divide and Conquer with Hash Map Indexing
// Time Complexity: O(n) - Each node is processed once, and each map lookup is O(1) on average.
// Space Complexity: O(n) - The hash map stores the inorder index of each value, and recursion uses O(h) stack space where h is tree height.

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if (inorder.empty() || postorder.empty())
        {
            return NULL;
        }

        unordered_map<int , int> ump;
        for(int i = 0  ; i < inorder.size() ; i++)
        {
            ump[inorder[i]] = i ;
        }

        TreeNode * root = buildTree(inorder , 0 , inorder.size() - 1 , postorder , 0 , postorder.size() - 1 , ump) ;

        return root ;

    }
    TreeNode * buildTree(vector<int> & inorder , int inorder_start , int inorder_end , vector<int> & postorder , int postorder_start , int postorder_end , unordered_map<int,int> & ump)
    {
        if(inorder_start > inorder_end || postorder_start > postorder_end)
        {
            return NULL;
        }

        TreeNode * root = new TreeNode(postorder[postorder_end]) ;

        // breaking the array inorder
        int rootValue = postorder[postorder_end];
        int rootIndex = ump[rootValue];

        int left_size = rootIndex - inorder_start ;


        root->left = buildTree(inorder , inorder_start , rootIndex - 1 , postorder , postorder_start , postorder_start + left_size - 1 , ump ) ;
        
        root->right = buildTree(inorder , rootIndex + 1 , inorder_end , postorder , postorder_start + left_size , postorder_end - 1 , ump ) ;

        return root ;
    }
};