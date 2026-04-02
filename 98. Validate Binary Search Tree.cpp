// Solution of LeetCode Problem 
// 98. Validate Binary Search Tree
// Solution in CPP 

// Approach - 1 
// Using DFS preorder traversal and everynode is passin upper and lower bound value 


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        return DFS(root , LONG_MIN , LONG_MAX);

    }

    // dfs preorder 
    bool DFS(TreeNode * root , long int lower , long int upper)
    {
        if(root == NULL) return true; 

        if(root->val <= lower || root->val >= upper)
        {
            // main condition that will return false if tree is not bst   
            return false ;
        }
        
        // at every node i am doing this i.e if traversing to left so updating upperbond and if traversing to right then updating the lowerbond  with root->val  

        bool left = DFS(root->left ,  lower , root->val) ;
        bool right = DFS(root->right , root->val , upper);
        
        return left && right  ;

    }
};

// Approach - 2 

// taversing the tree and checking it with previous element only beacuse inorder traversal of binary search tree gives sorted array so by this we are validating that the given tree is binary tree or not 


class Solution {
public:
    TreeNode * previous = nullptr ;
    bool isValidBST(TreeNode* root) {
       
        return dfs_inorder( root );
    }

    bool dfs_inorder(TreeNode *root)
    {
        if(root == NULL)
        {
            return true; // base case 
        }

        if(dfs_inorder(root->left) == false)
        {
            // left pura check kiya agr false aaya to bst nahi  
            return false ;
        }
        // node check kar rhe 
        if(previous != NULL && root-> val <= previous->val)
        {
            // jo current node pe hai wo smaller hai then previous node se to not a a bst 
            return false ; 
        }

        // updating the current node everytime 
        previous = root ;

        return dfs_inorder(root->right); // checking right sub tree

    }

};