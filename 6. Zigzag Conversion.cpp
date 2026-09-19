// Solution of LeetCode Problem
// 6. Zigzag Conversion
// Solution in CPP

// Approach - 1
// Using Row String Accumulation and Direction Flag
// Time Complexity: O(N) - Traversing each character of the string of size N once
// Space Complexity: O(N) - Storing characters in row strings of combined length N

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string> rows(numRows);

        int row = 0;
        int direction = -1;
        int n = s.size();

        for(int i = 0; i < n; i++)
        {
            rows[row] += s[i];

            if(row == 0 || row == numRows - 1)
            {
                direction = -direction;
            }

            row += direction;
        }

        string ans = "";

        for(int i = 0; i < rows.size(); i++)
        {
            ans += rows[i];
        }

        return ans;
    }
};

// Approach - 2
// Using 2D Character Vector and Direction Tracking
// Time Complexity: O(N) - Traversing each character of the string of size N once
// Space Complexity: O(N) - Storing characters in a 2D vector of combined size N

class Solution1 {
public:
    string convert(string s, int numRows) {
        if( numRows == 1 ) return s ;
        vector<vector<char>> vec(numRows) ;
        int row = 0 ;
        int direction = 1 ;
        int n = s.size() ;
        for(int i = 0 ; i < n ; i++)
        {
            if( (row == 0 && i != 0) || row == numRows - 1)
            {
                direction = -direction ;
            }
            vec[row].push_back(s[i]);
            row += direction ;
        }
        string ans = "" ;
        for(int i = 0 ; i < vec.size() ; i++)
        {
            for(int j = 0 ; j < vec[i].size() ; j++ )
            {
                ans += vec[i][j]  ;
            }
        }
        return ans;
    }
};