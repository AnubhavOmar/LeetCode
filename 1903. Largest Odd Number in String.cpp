// Solution of LeetCode Problem 
// 1903. Largest Odd Number in String 
// Solution in CPP 

// Appraoch - 1     Time Complexity = O(n)

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