// Solution of LeetCode Problem
// 1903. Largest Odd Number in String
// Solution in CPP

// Approach - 1
// Using Right-to-Left Trimming
// Time Complexity: O(N) - Scan and remove characters from the end once
// Space Complexity: O(1) - Modifying the input string directly

class Solution {
public:
    string largestOddNumber(string num) {
        
        for(int i = num.size()-1;i>=0;i--)
        {
            int d = num[i] - '0';
            if(d % 2 != 0)
            {
                break ;
            }
            else
            {
                num.pop_back();
            }
        }
        return num;
       
    }
};

// Approach - 2
// Using Right-to-Left Search and Substring
// Time Complexity: O(N) - Scan from the end, then copy the prefix up to the first odd digit
// Space Complexity: O(N) - Return a new substring of size up to N

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size() ;

        for(int i = n-1 ; i >= 0 ; i--)
        {
            if( ((num[i]) - '0') % 2 != 0 )
            {
                return num.substr(0 , i+1);
            }
        }
        return "" ;
    }
};