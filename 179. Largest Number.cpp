//  Solution of Hackerrank Problem 
// 179. Largest Number 
// Solution in CPP 

// Appraoch - 1 (Brute force Approach) 

class Solution {
public:

    int firstDigit(int n) {
        while (n >= 10)
            n /= 10;
        return n;
    }

    string largestNumber(vector<int>& nums) {
        int count_zeros = 0; 
        int count_hundred = 0;
        string ans = "";

        vector<int> number;           
        vector<int> single_number;     
        vector<int> divisible_number;  

        for (int n : nums) {
            if (n != 0 && n > 9 && n % 10 != 0) {
                number.push_back(n);
            } else if (n == 0) {
                count_zeros++;
            } else if (n % 10 == 0) {
                if (n == 100) count_hundred++;
                else divisible_number.push_back(n);
            } else {
                single_number.push_back(n);
            }
        }

        if (count_zeros == nums.size())
            return "0";

        vector<int> merged;
        merged.insert(merged.end(), single_number.begin(), single_number.end());
        merged.insert(merged.end(), number.begin(), number.end());
        merged.insert(merged.end(), divisible_number.begin(), divisible_number.end());

        sort(merged.begin(), merged.end(), [&](int a, int b) {
            string A = to_string(a);
            string B = to_string(b);
            return A + B > B + A;
        });

        for (int x : merged)
            ans += to_string(x);

        for (int i = 0; i < count_hundred; i++)
            ans += "100";

        for (int i = 0; i < count_zeros; i++)
            ans += "0";

        return ans;
    }
};
