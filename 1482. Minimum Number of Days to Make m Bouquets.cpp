// Solution of LeetCode Problem
// 1482. Minimum Number of Days to Make m Bouquets
// Solution in CPP

// Approach - 1
// Using Binary Search on Days
// Time Complexity: O(N log(MAX_DAY)) - Binary search over the range of days from min to max bloom day, with linear scan of size N in each check
// Space Complexity: O(1) - Constant auxiliary space used

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(  1LL * m * k > bloomDay.size()) return -1; 

        int n = bloomDay.size() ;

        int high = INT_MIN ;
        int low = INT_MAX ;

        for(int i = 0 ; i < n ; i++)
        {
            high = max(high , bloomDay[i]) ;
            low = min(low , bloomDay[i]) ;
        }

        int ans = -1 ;
        while(low <= high)
        {
            int mid = (low + high) / 2 ;
            bool choose = possible(bloomDay , mid , m , k) ;
            
            if(choose)
            {
                ans = mid ;
                high = mid - 1 ;
            }
            else
            {
                low = mid + 1 ;
            }
        }
        return ans;
    }
    bool possible(vector<int>& bloomDay,int day , int m, int k)
    {
        int flower = 0 ; 
        int no_of_bloom = 0 ;
        for(int i = 0 ; i < bloomDay.size() ;i++)
        {
            if(bloomDay[i] <= day)
            {
                flower++ ;
            }
            else
            {
                no_of_bloom += (flower / k) ;
                flower = 0 ;
            }
        }
        no_of_bloom += (flower / k) ;
        if(no_of_bloom >= m) return true ;
        return false ;        
    }
};

// Approach - 2
// Using Linear Search Over Days with Helper Function
// Time Complexity: O((MAX_DAY - MIN_DAY + 1) * N) - Iterating through each possible day and checking feasibility in linear time
// Space Complexity: O(1) - Constant auxiliary space used

class Solution2 {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if( m * k > bloomDay.size()) return -1; 

        int n = bloomDay.size() ;

        int maxx = INT_MIN ;
        int minn = INT_MAX ;

        for(int i = 0 ; i < n ; i++)
        {
            maxx = max(maxx , bloomDay[i]) ;
            minn = min(minn , bloomDay[i]) ;
        }

        for(int i = minn ; i <= maxx ; i++)
        {
            if(possible(bloomDay , i , m , k))
            {
                return i ;
            }
        }
        return -1 ;
    }
    bool possible(vector<int>& bloomDay,int day , int m, int k)
    {
        int flower = 0 ; 
        int no_of_bloom = 0 ;
        for(int i = 0 ; i < bloomDay.size() ;i++)
        {
            if(bloomDay[i] <= day)
            {
                flower++ ;
            }
            else
            {
                no_of_bloom += (flower / k) ;
                flower = 0 ;
            }
        }
        no_of_bloom += (flower / k) ;
        if(no_of_bloom >= m) return true ;
        return false ;        
    }
};

// Approach - 3
// Using Brute Force Linear Scan
// Time Complexity: O((MAX_DAY - MIN_DAY + 1) * N) - Checking each day from max to min bloom day with nested loops
// Space Complexity: O(1) - Constant auxiliary space used

class Solution1 {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if( m * k > bloomDay.size()) return -1; 

        int n = bloomDay.size() ;

        int maxx = INT_MIN ;
        int minn = INT_MAX ;

        for(int i = 0 ; i < n ; i++)
        {
            maxx = max(maxx , bloomDay[i]) ;
            minn = min(minn , bloomDay[i]) ;
        }
        
        int ans = INT_MAX;

        for(int day = maxx; day >= minn; day--)
        {
            int flowers = 0;
            int made_banquet = 0;

            for(int i = 0; i < n; i++)
            {
                if(bloomDay[i] <= day)
                {
                    flowers++;

                    if(flowers == k)
                    {
                        made_banquet++;
                        flowers = 0;
                    }
                }
                else
                {
                    flowers = 0;
                }
            }

            if(made_banquet == m)
            {
                ans = day;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};