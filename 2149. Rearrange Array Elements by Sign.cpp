// Solution of LeetCode Problem 
// 2149. Rearrange Array Elements by Sign
// Solution in CPP 

// Approach - 2

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size() ;
        
        int positive_index = 0 ;
        int negative_index = 1 ;
        vector<int>ans(n) ;

        for(int i = 0 ; i<n ; i++)
        {
            if(nums[i] > 0)
            {
                ans[positive_index] = nums[i];
                positive_index += 2 ;
            }
            else
            {
                ans[negative_index] = nums[i];
                negative_index += 2 ;
            }
        }
        return ans;
        
    }
};

// Approach - 1 

class Solution1 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size() ;
        int i = 0 ; 
        int positive_number = -1 ;
        int negative_number = -1 ;
        while(i<n)
        {
            if(nums[i] > 0 && positive_number == -1)
            {
                positive_number = i ;
            }
            else if(nums[i]<0 && negative_number == -1)
            {
                negative_number = i ;
            }
            else if(positive_number != -1 && negative_number != -1 )
            {
                break;
            }
            i++;
        }
        int position = 0 ;
        vector<int>ans(n) ;
        
        while(position < n)
        {
            if(position % 2 == 0)
            {
                ans[position] = nums[positive_number];

                positive_number++;

                while( positive_number < n && nums[positive_number] < 0 )
                {
                    positive_number++;
                }
            }

            else
            {
                ans[position] = nums[negative_number];

                negative_number++;

                while( negative_number < n && nums[negative_number] > 0 )
                {
                    negative_number++;
                }
            }

            position++;
        }
        return ans;
    }
};