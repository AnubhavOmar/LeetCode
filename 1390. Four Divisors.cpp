// Solution of LeetCode Problem 
// 1390. Four Divisors
// Solution in CPP  

// Approach - 1 

class Solution {
public:
    int divisor(int number)
{
    int count = 0;
    int sum = 0;

    for(int i = 1; i * i <= number; i++)
    {
        if(number % i == 0)
        {
            if(i * i == number)
            {
                count += 1;
                sum += i;
            }
            else
            {
                count += 2;
                sum += i + number / i;
            }
        }
    }

    return (count == 4) ? sum : 0;
}

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0 ; 
        for(int i = 0 ; i<nums.size() ;i++)
        {
            ans += divisor(nums[i]);
        }
        return ans;
    }
};