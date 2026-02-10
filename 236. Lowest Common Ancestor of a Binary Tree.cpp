// Solution of LeetCode Problem 
// 236. Lowest Common Ancestor of a Binary Tree
// Solution in CPP 

// Approach - 1 (Using DFS to iterate through tree)


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        (DFS(root , p , q));
        return ans ;
        
    }

private : TreeNode *ans =NULL ;


public : 
    bool DFS(TreeNode *node , TreeNode * p , TreeNode * q )
    {
        if(node == NULL )return false ;

        bool left_side = DFS(node->left , p ,q);
        bool right_side = DFS(node->right, p ,q);

        bool mid = (node == p || node == q);

        if( ((mid ? 1 :0 ) + (left_side ? 1: 0) +(right_side ? 1: 0) ) >=2 )
        {
            ans = node; 
        }
        
        return mid || left_side || right_side  ;
    }

};