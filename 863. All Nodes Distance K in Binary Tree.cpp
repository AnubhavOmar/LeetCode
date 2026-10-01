// Solution of LeetCode Problem
// 863. All Nodes Distance K in Binary Tree
// Solution in CPP

// Approach - 1
// Using Breadth-First Traversal with Parent Tracking
// Time Complexity: O(n) - The tree is traversed once to build parent links, then BFS explores up to O(n) reachable nodes.
// Space Complexity: O(n) - The hash map and queue can each store up to O(n) nodes.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;

        unordered_map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if (node->left != NULL)
            {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right != NULL)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        set<TreeNode *> visited;
        q.push(target) ;
        visited.insert(target) ;

        int idx = 0 ;
        
        // iss wale me hum ye kar rhe hai ki har ek while loop ke baad 4 sides ko 1 - 1 distance badh rhe hai and agr uss node ko visit kar chuke hai to nahi if nahi kare hai visit to kar rhe haii 

        while (!q.empty() && idx < k)
        {
            int curr_level = q.size();

            for(int i = 0; i < curr_level; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL && visited.find(node->left) == visited.end())
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right != NULL && visited.find(node->right) == visited.end())
                {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                if(parent.find(node) != parent.end() && visited.find(parent[node]) == visited.end())
                {
                    // parent se parent upper move kiya
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }

            idx++;
        }

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            ans.push_back(node->val);
        }
        return ans ;
    }
};


// Approach - 2
// Using DFS with Parent Navigation
// Time Complexity: O(n) - Each node can be visited at most once while traversing from the target and its ancestors.
// Space Complexity: O(n) - The recursion stack and parent map may each hold O(n) entries.

class Solution1 {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> ans;
        set<int> st;

        unordered_map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if (node->left != NULL)
            {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right != NULL)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // from this dfs we can get the values which at k-distance downside form the target node ;
        dfs(target, 0, k, st);

        // now from this function we will move upside k-distance and find the value
        parent_side_finder(target, 0, k, st, parent);

        // converting set into vector
        for (int x : st) {
            ans.push_back(x);
        }

        return ans;
    }

    void dfs(TreeNode* node, int idx, int k, set<int>& st) {

        if (node == NULL || idx > k)
        {
            return;
        }

        if (idx == k)
        {
            st.insert(node->val);
            return;
        }

        dfs(node->left, idx + 1, k, st);
        dfs(node->right, idx + 1, k, st);
    }

    void parent_side_finder(TreeNode* node, int idx, int k,
                            set<int>& st,
                            unordered_map<TreeNode*, TreeNode*>& parent) {

        if (node == NULL || idx > k)
        {
            return;
        }

        if (idx == k)
        {
            st.insert(node->val);
            return;
        }

        if (parent.find(node) == parent.end())
        {
            return;
        }

        TreeNode* par = parent[node];

        parent_side_finder(par, idx + 1, k, st, parent);

        // agr node ke left wala target hota hai to udher nahi jana hai 
        if (par->left == node) {
            dfs(par->right, idx + 2, k, st);
        }
        else {
            dfs(par->left, idx + 2, k, st);
        }
    }
};