// Solution of LeetCode Problem 
// 1022. Sum of Root To Leaf Binary Numbers
// Solution in CPP 

// Approach - 1 (Using DFS and Stroing every path in the array then calculating the sum)

 
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        DFS(root, "");
        // code to convet bin to dec and add them 
        int sum = 0 ; 
        for(int i = 0 ; i<bitss.size();i++)
        {
            sum += bin_to_dec(bitss[i]);
        }
        return sum ;
    }

private : vector<string>bitss ;

// har node pe ye ho rha hai ki wo jo usspe node pe value hai to ussko path me add karo and then check karo kya hum leaf node pe hai agar hai to path ko bitss wale array pe push kar do agr nahi hai to  left child ki taraf jaao aur agr leftnode pe kuch nahi hai to  right ki side jaao and har baar path ko update and pass karte jaao  
    void DFS(TreeNode *node , string path )
    {
        if(node == nullptr)
        {
            return  ;
        }

        path += to_string(node->val);
        
        if(node->left == NULL && node->right == NULL)
        {
            bitss.push_back(path);
            return ;
        }
        DFS(node->left , path);
        DFS(node->right,path);
    }
private : 
    int bin_to_dec(string s)
    {
        int number = 0 ; 
        int  j = 0 ;
        for(int i = s.size() - 1; i>=0 ;i--)
        {
           if(s[i]=='1')
           {
            number = number + pow(2,j);
           }
           j++ ;
        }
        return number ;
    }
};



// Approach - 2 (Using DFS and Optimizing the space by not storing every path)

class Solution {
public:
    int total_sum = 0 ;
    int sumRootToLeaf(TreeNode* root) {
        DFS(root, "");
        
        return total_sum ;
    }

// har node pe ye ho rha hai ki wo jo usspe node pe value hai to ussko path me add karo and then check karo kya hum leaf node pe hai agar hai to path bits ko turant decimal me convert karke global total_sum variable me add kar de rahe then left child ki taraf jaao aur agr leftnode pe kuch nahi hai to  right ki side jaao and har baar path ko update and pass karte jaao  

    void DFS(TreeNode *node , string path )
    {
        if(node == nullptr)
        {
            return  ;
        }

        path += to_string(node->val);
        
        if(node->left == NULL && node->right == NULL)
        {
           total_sum += bin_to_dec(path);
        }
        DFS(node->left , path);
        DFS(node->right,path);
    }
private : 
    int bin_to_dec(string s)
    {
        int number = 0 ; 
        int  j = 0 ;
        for(int i = s.size() - 1; i>=0 ;i--)
        {
           if(s[i]=='1')
           {
            number = number + pow(2,j);
           }
           j++ ;
        }
        return number ;
    }
};


// Approach = 3 (Calculating sum at every node and when reach to the leaf node then adding that sum to total sum )
// Optimal Appraoch 

class Solution {
public:
    int total_sum = 0 ;
    int sumRootToLeaf(TreeNode* root) {
        DFS(root,0);
        
        return total_sum ;
    }

private : 
    void DFS(TreeNode *node , int current)
    {
        if(node == nullptr)
        {
            return  ;
        }

        current = current * 2 + node->val;   

        if(node->left == NULL && node->right == NULL)
        {
           total_sum += current;
        }
        DFS(node->left , current);
        DFS(node->right , current);
    }
};

