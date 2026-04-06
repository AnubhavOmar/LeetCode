// Solution of LeetCode Problem 
// 107. Binary Tree Level Order Traversal II 
// Solution in CPP 

// Approach - 1 


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans ; 
        queue<TreeNode *> q ;
        q.push(root) ;
        
        if(root == NULL) return ans; 
        while(!q.empty())
        {
            int level_size = q.size() ; 
            vector<int> current_level ; 
            for(int i = 0 ; i<level_size ; i++)
            {
                TreeNode * node = q.front() ;
                q.pop() ; 
                // handling not null childs 
                
                if(node->left != NULL)
                {
                    q.push(node->left);
                }
                
                if(node->right != NULL)
                {
                    q.push(node->right);
                }
                current_level.push_back(node->val) ;  
            }
            ans.push_back(current_level);
        }

        reverse(ans.begin() , ans.end()) ;

        return ans ;
    }
};