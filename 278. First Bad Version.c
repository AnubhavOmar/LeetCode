// Solution of LeetCode Problem 
// 278. First Bad Version
// Solution in C 

// Approach - 1 ( Using Binary Search )
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1 ; 
        int end = n ;
        while( start < end)
        {
            int mid = start + (end - start) / 2 ;

            bool called_api = isBadVersion(mid) ;

            if(called_api == true)
            {
                end = mid ;
            }
            else 
            {
                start = mid + 1 ;
            }
        }
        return start ;
    }
};