// Solution of LeetCode Problem 
// 1373. Maximum Sum BST in Binary Tree 
// Solution in CPP 


// Appraoch - 1 
class Solution {
public:
    
    // Har node se 4 cheezein return karenge
    struct Info {
        bool isBST;     // Batata hai ki current subtree BST hai ya nahi
        int sum;        // Agar BST hai to subtree ka total sum
        int minVal;     // Subtree ka minimum element
        int maxVal;     // Subtree ka maximum element
    };
    
    int ans = 0; // Isme maximum BST ka sum store karenge
    
    // DFS function (Postorder traversal: Left -> Right -> Root)
    Info dfs(TreeNode* root) {
        
        // Base Case:
        // Agar node NULL hai, to usko valid BST mana jata hai
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }
        
        // Pehle left child se info lo
        Info left = dfs(root->left);
        
        // Phir right child se info lo
        Info right = dfs(root->right);
        
        // Current node ka info store karne ke liye
        Info curr;
        
        // Ab check karenge ki kya current subtree BST ban sakta hai
        
        // Yahan jo values left aur right se aayi hain:
        
        // left.isBST   -> Kya left subtree BST hai?
        // right.isBST  -> Kya right subtree BST hai?
        
        // left.maxVal  -> Left subtree ka maximum element
        // right.minVal -> Right subtree ka minimum element
        
        // BST banne ke liye conditions:
        // 1. Left subtree BST hona chahiye
        // 2. Right subtree BST hona chahiye
        // 3. Root ka value left ke max se bada hona chahiye
        // 4. Root ka value right ke min se chhota hona chahiye
        
        if (left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal) {
            
            // Agar upar wali sab conditions true hain
            // Matlab current subtree ek valid BST hai
            
            curr.isBST = true;
            
            // Total sum calculate karo:
            // Left subtree ka sum
            // + Right subtree ka sum
            // + Current root ka value
            
            curr.sum = left.sum + right.sum + root->val;
            
            // Minimum value update karo:
            // Ya to root chhota hoga
            // Ya left subtree ka min chhota hoga
            
            curr.minVal = min(root->val, left.minVal);
            
            // Maximum value update karo:
            // Ya to root bada hoga
            // Ya right subtree ka max bada hoga
            
            curr.maxVal = max(root->val, right.maxVal);
            
            // Global answer update karo
            // Taaki ab tak ka maximum BST sum store rahe
            ans = max(ans, curr.sum);
        }
        else {
            // Agar koi bhi condition fail ho jaaye
            // Matlab current subtree BST nahi hai
            
            curr.isBST = false;
            
            // Sum ka use nahi hai kyunki BST nahi bana
            curr.sum = 0;
            
            // Invalid range set kar dete hain
            // Taaki parent node is subtree ko BST na maane
            
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
        }
        
        // Current node ka info return karo
        // Taaki parent node use use kar sake
        return curr;
    }
    
    int maxSumBST(TreeNode* root) {
        
        // Root se DFS start karo
        dfs(root);
        
        // Final maximum BST sum return karo
        return ans;
    }
};


/* 
// Revision Purpose 


Har node se kya milta ye saari cheeeze miltii hai 

isBST  -> BST hai ya nahi
sum    -> Agar BST hai to total sum
minVal -> Minimum element
maxVal -> Maximum element


Parent inko kyun use karta hai iss wajah se use karta hai 
root > left.maxVal
root < right.minVal

*/
