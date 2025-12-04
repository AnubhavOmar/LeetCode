// Solution of LeetCode problem
// 1979. Find Greatest Common Divisor of Array
// Solution in CPP

// Appraoch - 1

class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        int smallest = nums[0];
        int greatest = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            smallest = min(smallest, nums[i]);
            greatest = max(greatest, nums[i]);
        }
        for (int i = greatest; i > 0; i--)
        {
            if ((smallest % i == 0) && (greatest % i == 0))
            {
                return i;
            }
        }
        return 1;
    }
};

// Approach - 2  (Euclidean Algorithm)

class Solution
{
public:
    int GCD(int min, int max)
    {
        if (min == 0)
            return max;
        else
            return GCD(max % min, min);
    }
    int findGCD(vector<int> &nums)
    {
        int smallest = nums[0];
        int greatest = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            smallest = min(smallest, nums[i]);
            greatest = max(greatest, nums[i]);
        }
        return GCD(greatest, smallest);
    }
};

// Appraoch - 3 (Using in-built GCD Function)

class Solution
{
public:
    int findGCD(vector<int> &nums)
    {

        int smallest = nums[0];
        int greatest = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            smallest = min(smallest, nums[i]);
            greatest = max(greatest, nums[i]);
        }

        return gcd(smallest, greatest);
    }
};