// Solution of LeetCode Problem 
// 1711. Count Good Meals 
// Solution in CPP 

// Appraoch  - 1 (Brute Force)
class Solution {
public:
    bool check_divisible_by_2(int n)
    {
        for(int i = 0 ; i< sqrt(n)+1 ;i++)
        {
            if(pow(2,i) == n)
            {
                return true ;
            }
        }
        return false ;
    }
    int countPairs(vector<int>& deliciousness)
    {
        int count = 0 ; 
        for(int i = 0 ; i<deliciousness.size() ; i++)
        {
            for(int j = i+1 ; j <deliciousness.size() ; j++)
            {
                if(check_divisible_by_2(deliciousness[i]+deliciousness[j]))
                {
                    count++;
                }
            }
        }
        return count ; 
        
    }
};


// Appraoch - 2 

