// Solution of LeetCode Problem
// 965. Univalued Binary Tree
// Solution in CPP

// Approach - 1
// Using Breadth-First Search
// Time Complexity: O(n) - Each node is visited once.
// Space Complexity: O(w) - The queue stores at most w nodes, where w is the maximum tree width.

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode *> q ;
        q.push(root);

        while(!q.empty())
        {
            TreeNode * node = q.front() ;
            q.pop() ;
            if(node->val != root->val)
            {
                return false;
            }
            if( node->left != NULL  )
            {
                if(node->left->val != root->val)
                {
                    return false;
                }
                q.push(node->left) ;
            }
            if( node->right != NULL )
            {
                if(node->right->val != root->val)
                {
                    return false;
                }
                q.push(node->right) ;
            }
        }
        return true ;
    }
};

// Approach - 2
// Using Depth-First Search with Recursion
// Time Complexity: O(n) - Each node is checked at most once.
// Space Complexity: O(h) - The recursion stack can reach the tree height h.

class Solution1 {
public:
    bool isUnivalTree(TreeNode* root) {
        bool ans = true ;
        int val = root->val ;

        dfs(root , ans , val) ;
        
        return ans;     
    }
    void dfs(TreeNode * node , bool & ans , int & val)
    {
        if(!ans)
        {
            return ;
        }
        if(node == NULL)
        {
            return ;
        }

        if(node->val != val) 
        {
            ans = false;
            return ;
        }

        dfs(node->left , ans , val) ;
        dfs(node->right , ans , val) ;
    }
    
};

// Approach - 3
// Using Breadth-First Search
// Time Complexity: O(n) - Each node is visited once.
// Space Complexity: O(w) - The queue stores at most w nodes, where w is the maximum tree width.

// normal bfs

class Solution3 {
public:
    bool isUnivalTree(TreeNode* root) {

        int val = root->val;

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            if(val != top->val) return false;
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }

        return true;
    }
};