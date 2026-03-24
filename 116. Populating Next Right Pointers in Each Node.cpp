// Solution of LeetCode Problem 
// 116. Populating Next Right Pointers in Each Node
// Solution in CPP 

// Approach - 1 (Using BFS)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // using BFS
        if(root == NULL) return root ;

        queue<Node *> q ;
        q.push(root) ;
        while(!q.empty())
        {
            int curr_level_size = q.size();
            
            for(int i = 0 ; i<curr_level_size;i++ )
            {
                Node *node = q.front() ;
                q.pop() ;

                // connecting the next node of the levels one by one and when reach the last element of the current level so storing last next = NULL ;
                
                node->next = (i == curr_level_size - 1) ? NULL : q.front();

                // handling the child nodes of parent node 
                if(node->left != NULL)
                {
                    q.push(node->left);
                }
                
                if(node->right != NULL)
                {
                    q.push(node->right);
                }
            }

        }
        return root ;
    }
};