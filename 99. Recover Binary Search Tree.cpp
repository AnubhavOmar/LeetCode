// Solution of LeetCode Problem 
// 99. Recover Binary Search Tree
// Solution in CPP 

/* Approach - 1

// Space Complexity = o(n) 

in this approach we are going to apply inorder traversal of tree because it will give the sorted array as it is a BST then storing the nodes in a global  vector and  then traversing its values and finding the misplaced values in the tree and storing those nodes and then changing those values
 */

class Solution {
public:


vector<TreeNode*> vec ;


    void recoverTree(TreeNode* root) { // main function 
        
        inorder_traversal(root) ;

        // now we have a vector which contains all the nodes and X and Y will be two nodes which value have to be swapped ;
        TreeNode * X = NULL ;
        TreeNode * Y = NULL ;
        bool first_value_found  = false ; // this will tell that we have found the first value
        for(int i = 0 ; i<vec.size() - 1; i++)
        {
            if( vec[i]->val > vec[i+1]->val  && !first_value_found)
            {
                X = vec[i] ;
                first_value_found = true ;
            }
            if( vec[i]->val > vec[i+1]->val  && first_value_found )
            {
                // in this we will store the second value 
                Y = vec[i+1] ;
            }
           
        }

        // swapping both X->val with Y->val 
        swap(X->val , Y->val) ;


    }

    void inorder_traversal(TreeNode *root )
    {
        // first traverse left and then node and then right childs 
        if(root == NULL)
        {
            // base case 
            return ;
        }

        inorder_traversal(root->left );

        vec.push_back(root);

        inorder_traversal(root->right );
        // this is complete inorder taraversal 

    }
};




/*  Approach - 2
in this approach i am thinking that during the inorder traversal i will find the X and Y nodes and store them in global variable and then swap both of them value in this way we will store Space of vector 
 */ 
class Solution {
public:
    // Global Variable 
    TreeNode * X = NULL ;
    TreeNode * Y = NULL ;
    TreeNode* prev = NULL;
    bool first_value_found = false; 

    void recoverTree(TreeNode* root) {
        
        inorder_traversal_2(root) ;
        swap(X->val, Y->val); 

    }

    void inorder_traversal_2(TreeNode * root )
    {
        if(root == NULL)
        {
            // base case 
            return ;
        }

        // recursive cases 

        inorder_traversal_2(root->left);
    
        if( prev != NULL && prev->val > root->val && !first_value_found )
        {
            X = prev ;
            Y = root ;
            first_value_found = true ;
        }
        if( first_value_found && prev->val > root->val )
        {
            Y = root ;
        }
        prev = root ;

        
        inorder_traversal_2(root->right);

    }
    
};
