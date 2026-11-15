// Solution of LeetCode Problem
// 1524. Number of Sub-arrays With Odd Sum
// Solution in CPP

// Approach - 1
// Using Prefix Sum Parity Counts
// Time Complexity: O(N) - Build the prefix sums and count odd-sum subarrays in two passes
// Space Complexity: O(N) - Store all prefix sums in a vector

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1000000007 ;
        long long count = 0 ; 
        int n = arr.size() ;

        vector<long long>pref(n) ;

        pref[0] = arr[0] ;

        for(int i = 1 ; i < n ; i++)
        {
            pref[i] = pref[i-1] + arr[i];
        }

        long long even_count = 1;
        long long odd_count = 0;


        for(int i = 0 ; i < n ; i++)
        {
            if(pref[i] % 2 != 0)
            {
                count += even_count ;

                odd_count++ ;
            }
            else
            {
                count += odd_count ;

                even_count++ ;
            }
            count = count % MOD ;
        }
        return count;
    }
};

// Approach - 2
// Using Prefix Sums and Brute Force Subarray Checks
// Time Complexity: O(N^2) - Check every subarray using prefix sums
// Space Complexity: O(N) - Store all prefix sums in a vector

class Solution3 {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1000000007 ;
        int count = 0 ; 
        int n = arr.size() ;

        vector<long long>pref(n) ;

        pref[0] = arr[0] ;

        for(int i = 1 ; i < n ; i++)
        {
            pref[i] = pref[i-1] + arr[i];
        }

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i ; j < n ; j++)
            {
                long long summ ;
                if(i == 0)
                {
                    summ = pref[j] ;
                }
                else
                {
                    summ = pref[j] - pref[i-1] ;
                }

                if(summ % 2 != 0)
                {
                    count++ ;
                    count = count % MOD ;
                }
            }
        }
        return count;
    }
};

// Approach - 3
// Using Brute Force with Running Subarray Sum
// Time Complexity: O(N^2) - Check every subarray while updating its sum
// Space Complexity: O(1) - Use only constant extra variables

class Solution2 {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1000000007 ;
        int count = 0 ; 
        int n = arr.size() ;

        for(int i = 0 ; i < n ; i++)
        {
            int sum = 0 ;
            for(int j = i ; j < n ; j++)
            {
                sum += arr[j] ;
                if(sum % 2 != 0)
                {
                    count++;
                    count = count % MOD ;
                }
            }
        }
        return count;
    }
};

// Approach - 4
// Using Brute Force with Temporary Vectors
// Time Complexity: O(N^3) - Build and check every subarray, including a full sum scan
// Space Complexity: O(N) - The temporary vector can store up to N elements

class Solution1 {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1000000007 ;
        int count = 0 ; 
        int n = arr.size() ;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i ; j < n ; j++)
            {
                vector<int>vec;
                for(int k = i ; k <= j ; k++)
                {
                    vec.push_back(arr[k]);
                }
                if(check(vec))
                {
                    count++;
                    count = count % MOD ;
                }
            }
        }
        return count;
    }
    
    bool check(vector<int>&vec)
    {
        int sum = 0 ;
        int n = vec.size() ;
        for(int i = 0 ; i < n ; i++)
        {
            sum += vec[i] ;
        }
        return sum % 2 != 0 ;
    }
};