// Solution of LeetCode Problem 
// 129. Sum Root to Leaf Numbers
// Solution in CPP

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

// Approach - 3
// Using Morris Traversal
// Time Complexity: O(2N) - Traversing each node and finding predecessors in the binary tree of size N
// Space Complexity: O(1) - Constant auxiliary space used
class Solution {
public:
    int sumNumbers(TreeNode* root) {

        int sum = 0 ;
        int current_number = 0 ;

        while(root != NULL)
        {
            if(root->left == NULL)
            {
                // if root has the left child so update current_number
                current_number = current_number * 10 + root->val ;
                if(root->right == NULL)
                {
                    // and if the left node is the leaf node so add the current_numebr to the sum 
                    sum += current_number;
                }
                root = root->right ;
            }
            else
            {
                // if root have left child so find predecessor 
                TreeNode * pred = root->left ;
                
                int steps = 1 ;

                while(pred->right != NULL && pred->right != root)
                {
                    pred = pred->right;
                    // and also count the depth of the tree which we will further use for resetting the current_number ;
                    steps++ ;
                }
                if(pred->right == NULL)
                {
                    // means we have not visited the left subtree yet 
                    pred->right = root ;
                    // update the current number
                    current_number = current_number * 10 + root->val ;
                    // so moving the root or curr node to left subtree
                    root = root->left ;

                }
                else
                {
                    // if the left subtree is already visited so we have perform 4 tasks here 
                    /*
                    1.it means that we have the root to leaf path so first we add the current node value to  current number ans then we  can add current_number it in to our sum 
                    2. reset the pred->right to null
                    3. reset the current_number by dividing it steps times
                    4. move the root node or current node to right side
                    */
                    if(pred->left == NULL)
                    {
                        sum += current_number ;
                    }
                    pred->right  = NULL ;
                    while(steps != 0)
                    {
                        current_number /= 10 ;
                        steps--;
                    } 
                    root = root->right;
                }
            }
        }
        return sum ;
    }
};


// Approach - 2
// Iterative approach using stack
// Time Complexity: O(N) - Visiting every node in the binary tree of size N once
// Space Complexity: O(H) - Stack space proportional to the height H of the binary tree
class Solution2 {
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }

        int total_sum = 0 ;

        stack<pair<TreeNode * , int>> st;

        st.push({root , 0 });

        while(!st.empty())
        {
            // pair<TreeNode * , int> p = st.top() ;
            auto p = st.top() ;
            st.pop() ;

            TreeNode * node = p.first ;
            int Current_Number = p.second;

            // updating the Current_Number

            Current_Number = Current_Number * 10 + node->val ;
    
            if(node->left == NULL && node->right == NULL)
            {
                // you are leaf
                total_sum += Current_Number;
            }
            else
            {
                if(node->left != NULL)
                {
                    st.push({node->left , Current_Number});
                }
                
                if(node->right != NULL)
                {
                    st.push({node->right , Current_Number});
                }

            }

        }
        return total_sum ;
    }
};

// Approach - 1
// Using Recursion (DFS)
// Time Complexity: O(N) - Visiting every node in the binary tree of size N once
// Space Complexity: O(H) - Recursive call stack space proportional to the height H of the binary tree
class Solution1 {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0 ;
        dfs(root , 0 , sum);
        return sum ;
    }
    
    void dfs(TreeNode* node , int currno , int& sum)
    {
        if(node == NULL)
        {
            return ;
        }
        // following pre order traversal 

        currno = currno * 10 + node->val ;

        // Only adding the child when the node is at child node 
        if(node->left == NULL && node->right == NULL)
        {
            sum += currno ;
        }

        dfs(node->left , currno , sum);
        dfs(node->right , currno , sum);

        return ;
    }
};