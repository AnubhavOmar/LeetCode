// Solution of LeetCode problem 
// 374. Guess Number Higher or Lower
// Solution in CPP 

// Approach - 1 : Using Binary search 

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 0 ; 
        int end = n ;
        while(start <= end)
        {
            int mid = start + (end - start) / 2 ;
            int response = guess(mid); // this returns the response from the guess API 
            if(response == 0 ) return mid ;
            else if (response == 1) start = mid + 1 ;
            else end = mid - 1 ;
        }
        return -1 ;
    }
};