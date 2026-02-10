// Solution of LeetCode Problem 
// 543. Diameter of Binary Tree 
// Solution in CPP 

// Approach - 1 (Using DFS to iterate through tree)
// traversel used is postorder 

class Solution {
public:

private : int maxdiameter = 0 ;

public :
    int diameterOfBinaryTree(TreeNode* root) {

// post order traversel is done becaue we first find the leftpath  then rightpath  from parent node then then return the (max(rightpath ,leftpath) + 1 ) to parent node then calculate at every node diamenter i.e = leftpath + rightpath  so its traversal is (Left , right , node ) so post order traversal

// at every place we will find the diameter and also return the parent node (max(rightpath ,leftpath) + 1 ) 


    DFS(root);
    return maxdiameter ;

    }

// helper loop to iterate in tree 

    int DFS(TreeNode *node)
    {
        if(node == NULL) return 0 ;

        int left_path = DFS(node->left); // calculate the left path by recursion 
        int right_path = DFS(node->right); // calculating the right path by recursion 

        maxdiameter = max(maxdiameter , left_path + right_path) ; // checking the path if found so updating the max path 
        
        return max(left_path , right_path)+1; 

    }
};