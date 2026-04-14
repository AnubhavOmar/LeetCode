// Solution of LeetCode Problem 
// 167. Two Sum II - Input Array Is Sorted 
// Solution in CPP 

// Approach - 1 (Using Two Pointers)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans; 
        int i = 0 ; 
        int j = numbers.size() - 1;
        while(i<j)
        {
            int sum = numbers[i] + numbers[j] ;
            
            if(sum == target)
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                break ;
            }
            else if(sum > target)
            {
               j-- ;
            }
            else
            {
                i++;
            }
           
        }
        return ans ;
    }
};