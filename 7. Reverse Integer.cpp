// Solution of LeetCode Problem 
// 7. Reverse Integer
// Solution in CPP 

// Approach - 1 (Using String)

class Solution {
public:
    int reverse(int x) {
        
        if (x > 0)
        {
            string num = to_string(x);

            std::reverse(num.begin(), num.end());

            long long val = stoll(num); 

            if (val > INT_MAX) return 0;

            return (int)val;
        }
        else
        {
            string num = to_string(-1LL * x);

            std::reverse(num.begin(), num.end());

            long long val = stoll(num);  

            val = -val;

            if (val < INT_MIN) return 0; 

            return (int)val;
        } 
    }
};