
// Solution of LeetCode Problem
// 2124. Check if All A's Appears Before All B's
// Solution in CPP

// Approach - 1
// Using Linear Scan with Two While Loops
// Time Complexity: O(N) - Scan the string once or twice
// Space Complexity: O(1) - Use only constant extra variables

// Normal while Loop
class Solution1 {
public:
    bool checkString(string s) {
        int n = s.size() ;
        int i = 0 ; 
        while(i < n)
        {
            if(s[i] == 'b')
            {
                break;
            }
            i++;
        }
        if( i == n - 1) return true;
        i++;
        while(i < n)
        {
            if(s[i] == 'a')
            {
                return false;
            }
            i++;
        }
        return true;
    }
};

// Approach - 2
// Using Sorting
// Time Complexity: O(N log N) - Sort the copied string of size N
// Space Complexity: O(N) - Create a copy of the string

class Solution {
public:
    bool checkString(string s) {
        string temp = s ;
        sort(s.begin() , s.end()) ;
        return temp == s;
    }
};