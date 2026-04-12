// Solution of leetCode Problem 
// 199. Binary Tree Right Side View
// Solution in CPP 

// Approach - 1 (Brute Force type)


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        /// BFS laga ke har level ke sabhi nodes ko store kar rahe hain 2D vector me,
        /// phir us 2D vector ko traverse karke har level ka last element (rightmost node) nikal rahe hain

        if(root == NULL) return {} ;

        vector<vector<int>> node_values ;
        queue<TreeNode *> q ;
        q.push(root);
        // node_values.push_back({root->val});

        while(!q.empty())
        {
            int curr_level_size = q.size() ;
            vector<int> curr_level_values ;

            for(int i = 0 ; i< curr_level_size ; i++)
            {
                TreeNode *node = q.front() ;
                q.pop() ;

                curr_level_values.push_back(node->val);

                // push left child if exists
                if(node->left != NULL)
                    q.push(node->left);

                // push right child if exists
                if(node->right != NULL)
                    q.push(node->right);
            }

            // store current level values
            node_values.push_back(curr_level_values);
        }

        vector<int> ans;

        // traverse each level and pick the last element (rightmost node)
        for(int i = 0 ; i<node_values.size() ;i++)
        {
            ans.push_back(node_values[i][node_values[i].size()-1]);  
        }

        return ans;
    }
};


// Approach - 2 
// in this we have done this traversing using bfs and at every level we are pushing right child of the every node in visit array and after the complete traversal of that level we are pushing the last element of the visit array 

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        queue<TreeNode*> q ; // it will consist of all the nodes of a level and 
         

        vector<int> ans ;

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
            ans.push_back(visit[visit.size() - 1 ]);
        }
        return ans ;
    }
};  

// Approach - 3 
// bfs laga ke har level pe right child ko pehle queue me push kar rahe hain isliye queue ka front hamesha us level ka rightmost node hota hai har level ka front node answer me daal rahe hain


class Solution2{
public:
    vector<int> rightSideView(TreeNode* root) {
         // bfs and queue  
        queue<TreeNode*> q ; // it will consist of all the nodes of a level 
        
        vector<int> ans ;

        if(root == NULL) return ans ; // handling edge case 

        q.push(root) ;

        while(!q.empty())
        {
            TreeNode* nodee = q.front() ;
            int level_size = q.size() ;

            for(int i = 0 ; i<level_size ; i++)
            {
                TreeNode * nodee = q.front() ;
                q.pop() ; 

                // handling not null CHILDS
                if(nodee->right != NULL)
                {
                    q.push(nodee->right);
                }

                if(nodee->left != NULL)
                {
                    q.push(nodee->left);
                }
            }

            ans.push_back(nodee->val);
        }
        
        return ans ;
    }
};