// Solution of LeetCode Problem 
// 102. Binary Tree Level Order Traversal
// Solution in CPP 

// Approach - 1 (Using a Queue and Traversal : BFS)


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        // bfs and queue 

        queue<TreeNode*> q ; // it will consist of all the nodes of a level and 
         

        vector<vector<int>> ans ;

        if(root == NULL) return ans ; // handling edge case 

        q.push(root) ;

        while(!q.empty())
        {
            TreeNode* nodee = q.front() ;
            int level_size = q.size() ;

            vector<int> visit ;
            
            for(int i = 0 ; i<level_size ; i++)
            {
                TreeNode * nodee = q.front() ;
                q.pop() ; 

                // handling not null CHILDS and inserting them into queue 
                if(nodee->left != NULL)
                {
                    q.push(nodee->left);
                }

                if(nodee->right != NULL)
                {
                    q.push(nodee->right);
                }
                
                visit.push_back(nodee->val) ; /// visiting the node of current level 

            }
            ans.push_back(visit);
        }
        return ans ;
    }
};
