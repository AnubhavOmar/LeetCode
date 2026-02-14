// Solution of LeetCode Problem 
// 236. Lowest Common Ancestor of a Binary Tree
// Solution in CPP 

// Approach - 1 (Using DFS to iterate through tree)

// traversel used is postorder (Left child , Right child , Parent node )


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        (DFS(root , p , q));
        return ans ;
        
    }

private : TreeNode *ans =NULL ;


public : 
    bool DFS(TreeNode *node , TreeNode * p , TreeNode * q )
    {
        if(node == NULL )return false ;

        bool left_side = DFS(node->left , p ,q);
        bool right_side = DFS(node->right, p ,q);

        bool mid = (node == p || node == q);

        if( ((mid ? 1 :0 ) + (left_side ? 1: 0) +(right_side ? 1: 0) ) >=2 )
        {
            ans = node; 
        }
        
        return mid || left_side || right_side  ;
    }

};




//  Appraoch - 2 
// (Using Stack)


class Solution {
public:
    
    // Ye states batate hain ki node ka kaunsa part process hua hai
    
    static const int BOTH_PENDING = 2; // Abhi left aur right dono baaki hain
    static const int LEFT_PENDING = 1; // Left ho chuka hai, right baaki hai
    static const int BOTH_DONE   = 0;  // Left aur right dono complete ho gaye
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Agar tree empty hai to LCA possible hi nahi
        if (!root) return nullptr;

        // Ye vector stack ki tarah kaam karega
        // Har element me:
        // first  -> node
        // second -> us node ka current state
        vector<pair<TreeNode*, int>> stackk;

        // Root se traversal start karo
        stackk.push_back({root, BOTH_PENDING});

        bool foundOne = false; // Kya p ya q me se koi mil chuka hai?
        TreeNode* lca = nullptr; // Temporary LCA store karne ke liye

        // Jab tak stack empty nahi hota, traversal chalta rahega
        while (!stackk.empty()) {

            // Stack ka top element lo
            auto &top = stackk.back();

            // Jab abhi tak left aur right dono visit nahi hue
            if (top.second == BOTH_PENDING) {

                // Check karo: kya ye node p ya q hai?
                if (top.first == p || top.first == q) {

                    // Agar pehli baar mila hai
                    if (!foundOne) {

                        foundOne = true;

                        // Abhi ke node ko LCA maan lete hain
                        // Baad me update ho sakta hai
                        lca = top.first;
                    } 
                    else {
                        // Agar pehle ek mil chuka hai
                        // Aur ab doosra mil gaya
                        // To jo lca hai wahi final answer hai
                        return lca;
                    }
                }

                // Ab left child par jaane ki tayari
                top.second = LEFT_PENDING;

                if (top.first->left) {
                    stackk.push_back({top.first->left, BOTH_PENDING});
                }
            }

            // Jab left subtree complete ho chuka ho
            // Ab right subtree par jaayenge
            else if (top.second == LEFT_PENDING) {

                top.second = BOTH_DONE;

                if (top.first->right) {
                    stackk.push_back({top.first->right, BOTH_PENDING});
                }
            }

            // Jab left aur right dono complete ho jaaye
            // Ab backtrack karna hai
            else {

                // Agar ye node current LCA hai
                if (top.first == lca && foundOne) {

                    // Is node se upar move karo
                    stackk.pop_back();

                    // Parent ko new LCA bana do
                    if (!stackk.empty())
                        lca = stackk.back().first;
                } 
                else {
                    // Normal case: sirf pop karo
                    stackk.pop_back();
                }
            }
        }

        // Agar dono nodes nahi mile to nullptr return
        return nullptr;
    }
};


