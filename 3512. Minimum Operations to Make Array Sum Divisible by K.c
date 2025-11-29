// Solution of LeetCode problem 
// 3512. Minimum Operations to Make Array Sum Divisible by K
// Solution in C Language 

// Appraoch   

int minOperations(int* nums, int numsSize, int k) {
        int sum = 0 ; 
        for(int i= 0 ; i<numsSize ;i++)
        {
            sum += nums[i];
        }
        return sum % k;
}