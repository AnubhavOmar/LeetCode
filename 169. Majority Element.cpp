// Solution of LeetCode Problem
// 169. Majority Element
// Solution in CPP 

// Approach - 1 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        if (n == 1 ) return nums[0];
        map<int , int > m; 
        for(int a : nums)
        {
            m[a]++;
        }
        int maxtime=n/2 ;
        int number=0 ;
        for(auto a: m)
        {
            if(maxtime<a.second)
            {
                maxtime = a.second ;
                number = a.first;
            }
            
        }
        return number; 
    }
};

// Appraoch - 2 
// Moore's Voting Algorithm
// Idea: If an element appears more than n/2 times, it cannot be completely cancelled out
// by all other elements. By increasing/decreasing a counter, the final candidate is the majority element.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ; 
        int count = 0; 
        int element = 0; 
        for(int i  = 0 ; i < n ; i++)
        {
            if(count == 0)
            {
                element = nums[i];
                count++;
            }
            else if(nums[i] == element)
            {
                count++;
            }
            else 
            {
                count-- ;
            }
        }    


/*
        // this is only to verify that the element is present in array more than n/2 times

        int count1 = 0;
        for(int i = 0 ;  i < n ; i++)
        {
            if(nums[i] == element)
            {
                count1++;
            }
        }

        if(count1 >= n/2 )
        {
            return element ;
        }
        
        return -1; // unreachable state
*/

    return element;

    }
};