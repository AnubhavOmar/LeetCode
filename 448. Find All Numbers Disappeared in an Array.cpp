// Solution of LeetCode 
//  448. Find All Numbers Disappeared in an Array

// Appraoch - 1   using maps and find function of map 

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans ;
        map <int ,int > m ;
        for(int a : nums)
        {
            m[a]++ ; 
        }
        
        for(int i = 1 ; i<=nums.size() ; i++)
        {
            if(m.find(i) == m.end())
            {
                ans.push_back(i) ;  
            }
        }




        return ans; 

    }
};