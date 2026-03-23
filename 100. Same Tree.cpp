// Solution of LeetCode Problem 
// 100. Same Tree
// Solution in CPP 

// Approach - 1 (Using DFS)

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
bool isSameTree(TreeNode* p, TreeNode* q)
{
    return DFS(p ,q);
}

bool DFS(TreeNode* p_node , TreeNode* q_node )
{
    // Case 1: Agar dono nodes NULL hain
    // -> iska matlab dono trees me yaha kuch nahi hai -> same hai
    if(p_node == NULL && q_node == NULL) 
        return true;

    // Case 2: Agar ek NULL hai aur dusra nahi
    // -> structure mismatch -> trees same nahi hain
    if(p_node == NULL || q_node == NULL) 
        return false;

    // Case 3: Agar dono nodes ki values different hain
    // -> trees same nahi hain
    if(p_node->val != q_node->val){
        return false ;
    }

    // Recursively left subtree check karo
    bool left = DFS(p_node->left , q_node->left);

    // Recursively right subtree check karo
    bool right = DFS(p_node->right , q_node->right);

    // Final result:
    // Tabhi true hoga jab left aur right dono same ho
    return left && right;
}


};