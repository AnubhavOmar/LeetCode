// Solution of LeetCode Problem
// 38. Count and Say
// Solution in CPP

// Appraoch - 1 (Brute Force) 

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string ans = "1";

        for (int i = 1; i < n; i++)
        {
            string ss = "";
            int k = 0;

            while (k < ans.size())
            {
                char s = ans[k];
                int count = 0;

                while (k < ans.size() && ans[k] == s)
                {
                    count++;
                    k++;
                }

                ss = ss + to_string(count) + s;
            }

            ans = ss;
        }

        return ans;
    }
};
