// Solution of LeetCode Porblem 
// 257. Binary Tree Paths 
// Solution in Cpp

// Appraoch - 1 
// Using Recursion DFS 

 
class Solution {
public:
    vector<string> binaryTreePaths(Treeroot* root) {
        DFS(root , "");
        return total_path;
    }

public : vector<string>total_path ;
    void DFS(Treeroot *root , string path )
    {
        if(root == nullptr) return ;
        
        path += to_string(root->val);
    
        if(root->left == NULL && root->right == NULL)
        {
            total_path.push_back(path);
        }

        DFS(root->left , path+"->" );
        DFS(root->right, path+"->" );
    }
};


// Appraoch - 2 
// Using Iterative DFS 


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        if (root == nullptr) return {};

        stack<TreeNode*> node_stack;
        
        stack<string> path_stack;
        
        vector<string> total_path;

        node_stack.push(root);
        path_stack.push(to_string(root->val));

        while (!node_stack.empty()) {

            TreeNode* node = node_stack.top();
            node_stack.pop();

            string path = path_stack.top();
            path_stack.pop();

            // If leaf node → store path in total_path 
            if (node->left == nullptr && node->right == nullptr) {
                total_path.push_back(path);
            }

            // Push right first (so left processes first)

            if (node->right != nullptr) {
                node_stack.push(node->right);
                path_stack.push(path + "->" + to_string(node->right->val));
            }

            if (node->left != nullptr) {
                node_stack.push(node->left);
                path_stack.push(path + "->" + to_string(node->left->val));
            }
        }

        return total_path;
    }
};
