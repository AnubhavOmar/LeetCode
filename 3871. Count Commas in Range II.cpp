// Solution of LeetCode POTD
// 3871. Count Commas in Range II
// Solution in CPP

// Approach - 1
// Using Mathematical Powers of 1000 Iteration
// Time Complexity: O(log_{1000}(N)) - Logarithmic time complexity based on the base-1000 scaling of N
// Space Complexity: O(1) - Constant auxiliary space used

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0 ;
        long long  base = 1000 ;
        while( base <= n)
        {
            ans += ( n - base + 1 ) ;
            // if ( base > LLONG_MAX / 1000) break ; // this is used when the constraint are more than 10^15 
            base *= 1000;
        }
        return ans;
    }
};

// Approach - 2
// Using Linear Scan and Range Digit Grouping
// Time Complexity: O(N) - Linear iteration from 1000 to N
// Space Complexity: O(1) - Constant auxiliary space used

class Solution1 {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0 ;

        long long commas = 0 ;

        for(long long i = 1000 ; i <= n ; i++)
        {
            if(i >= 1000 && i < 1000000 )
            {
                commas++ ;
            }
            else if(i >= 1000000 && i < 1000000000)
            {
                commas += 2 ;
            }
            else if( i >= 1000000000 && i < 1000000000000)
            {
                commas += 3 ;
            }
            else if(i >= 1000000000000 )
            {
                commas += 4 ;
            }
        }
        return commas ;
    }
};