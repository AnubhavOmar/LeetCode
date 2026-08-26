// Solution of LeetCode POTD
// 2904. Shortest and Lexicographically Smallest Beautiful String
// Solution in CPP

// Approach - 1
// Using Sliding Window and String Comparison
// Time Complexity: O(N^2) - Iterating through substrings of length N, with string operations in the worst case
// Space Complexity: O(N) - Storing candidate beautiful strings in an auxiliary vector

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int count_one = 0;
        int beautiful_len = INT_MAX;

        int i = 0;
        int j = 0;

        while (j < n)
        {
            if (s[j] == '1')
                count_one++;

            if (count_one >= k)
            {
                while (i <= j && s[i] == '0')
                    i++;

                beautiful_len = min(beautiful_len, j - i + 1);

                i++;
                count_one--;
            }

            j++;
        }

        vector<string> ans;

        for (int i = 0; i + beautiful_len <= n; i++)
        {
            string temp = s.substr(i, beautiful_len);

            int count = 0;

            for (char ch : temp)
            {
                if (ch == '1')
                    count++;
            }

            if (count == k)
            {
                ans.push_back(temp);
            }
        }
        
        if (ans.empty())
            return "";

        sort(ans.begin(), ans.end());

        return ans[0];
    }
};