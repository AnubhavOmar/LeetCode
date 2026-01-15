// Solution of LeetCode Problem 
// 2595. Number of Even and Odd Bits
// Solution in C

// Approach - 1 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* evenOddBit(int n, int* returnSize) {
     int* ans = (int*)malloc(2 * sizeof(int));
    ans[0] = 0;  
    ans[1] = 0;  

    int i = 0;

    while (n != 0) {
        if (n % 2 == 1) {
            if (i % 2 == 0)
                ans[0]++;
            else
                ans[1]++;
        }
        n /= 2;
        i++;
    }

    *returnSize = 2;
    return ans;
}