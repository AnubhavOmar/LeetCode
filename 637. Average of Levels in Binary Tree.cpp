// Solution of LeetCode Problem
// 637. Average of Levels in Binary Tree
// Solution in CPP

// Approach - 1
// Using DFS and a 2D Vector
// Time Complexity: O(N) - Visit every tree node and then add all stored values
// Space Complexity: O(N) - Store all node values by level and use the DFS call stack

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {

        vector<vector<int>> nodes ;

        dfs(root , 0 , nodes) ;

        int n = nodes.size() ;

        vector<double> ans(n) ;

        for(int i = 0 ; i < n ; i++)
        {
            double sum = summ(nodes[i]);
            
            ans[i]  = (sum / nodes[i].size() ) ;
        }
        return ans;
    }

    void dfs(TreeNode * node , int level , vector<vector<int>> & nodes )
    {
        if(!node) return ;

        if(nodes.size() <= level ) nodes.push_back({}) ;
        	// Create a vector if the required level doesn't exist

        nodes[level].push_back(node->val);
        dfs(node->left , level + 1 , nodes ) ;
        dfs(node->right , level +  1 , nodes ) ;
    }

    double summ(vector<int> & vec)
    {
        double sum = 0 ;
        int n = vec.size();
        for(int i = 0 ; i < n ; i++)
        {
            sum += vec[i] ;
        }
        return sum ;
    }
};


// Approach - 2
// Using DFS and an Unordered Map
// Time Complexity: O(N) - Visit every node and use average O(1) map insertion
// Space Complexity: O(N) - Store all node values in the map

class Solution3 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        unordered_map<int,vector<int>> ump ;
        // here for dfs approach we will assume every level as key and push that level nodes in that vector of ump 
        dfs(root , 0 , ump) ;

        int n = ump.size() ;

        vector<double> ans(n) ;

        for(int i = 0 ; i < n ; i++)
        {
            double sum = summ(ump[i]);
            
            ans[i] = (sum / ump[i].size() ) ;
        }
        return ans;
    }

    void dfs(TreeNode * node , int level , unordered_map<int,vector<int>> &ump )
    {
        if(!node) return ;
        ump[level].push_back(node->val);
        dfs(node->left , level + 1 , ump ) ;
        dfs(node->right , level +  1 , ump ) ;
    }

    double summ(vector<int> & vec)
    {
        double sum = 0 ;
        int n = vec.size();
        for(int i = 0 ; i < n ; i++)
        {
            sum += vec[i] ;
        }
        return sum ;
    }
};


// Approach - 3
// Using DFS and an Ordered Map
// Time Complexity: O(N log H) - Each insertion costs O(log H), where H is the tree height
// Space Complexity: O(N) - Store all node values in the map

class Solution2 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        map<int,vector<int>> mp ;

        // here for dfs approach we will assume every level as key and push that level nodes in that vector of mp 

        dfs(root , 0 , mp) ;
        
        vector<double> ans ;

        for(auto a : mp)
        {

            double sum = summ(a.second);
            
            ans.push_back(sum / a.second.size() ) ;
        }
        return ans;
    }

    void dfs(TreeNode * node , int level , map<int,vector<int>> &mp )
    {
        if(!node) return ;
        mp[level].push_back(node->val);
        dfs(node->left , level + 1 , mp ) ;
        dfs(node->right , level +  1 , mp ) ;
    }

    double summ(vector<int> & vec)
    {
        double sum = 0 ;
        int n = vec.size();
        for(int i = 0 ; i < n ; i++)
        {
            sum += vec[i] ;
        }
        return sum ;
    }
};

// Approach - 4
// Using Breadth-First Search (BFS) with a Queue
// Time Complexity: O(N) - Visit every tree node once
// Space Complexity: O(W + H) - The queue can hold W nodes and the answer has H levels

class Solution1 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;

        queue<TreeNode *> q; 

        q.push(root);

        while(!q.empty())
        {
            double curr_level = q.size() ;
            double sum_of_current_level = 0 ;
            for(int i = 0 ; i < curr_level ; i++)
            {
                TreeNode * node = q.front() ;
                q.pop() ;

                sum_of_current_level += node->val ;
                if(node->left) q.push(node->left) ;
                if(node->right) q.push(node->right) ;
            }
            ans.push_back(double(sum_of_current_level / curr_level)) ;
        }
        return ans;
    }
};