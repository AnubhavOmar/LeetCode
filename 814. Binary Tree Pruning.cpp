// Solution of LeetCode  
// 814. Binary Tree Pruning 
// Solution in CPP 

// Appraoch - 1   (Using DFS)

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        // checking if DFS(root) i.e root node of the tree have some 1 in the tree so returning its address else returning the null ptr ;

        return DFS(root) ? root : NULL ;
    
    }

// post order traversel is done becaue we first check the left then right side from node then at last go back to node so its traversal is (Left , right , node ) so post order traversal 

    bool DFS(TreeNode *node)
    {
        if( node == NULL)
        {
            return false ;
        }
        bool left_node = DFS(node->left); // checking that is leftnode is 0 or 1 
        bool right_node = DFS(node->right); // checking that is rightnode is 0 or 1 

        // if anyone of them is false so removing that subtree 
        // else returning the or of all the subtree form node left , right , value
        if(left_node == false)
        {
            node->left = NULL ;
        }
        if(right_node == false)
        {
            node->right = NULL ;
        }
        return (left_node || right_node || node->val) ; 
    }
};