// solution of Leetcode 202 Happy Numbers
// In cpp 

class Solution {
public:
    int sumofdigitofsquare(int n) {
        long long int sum = 0;
        while (n != 0) {
            sum = sum + ((n % 10) * (n % 10));
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        if (n == 1)
            return true;
        int number = n;
        unordered_map<int, int> m;
        while (sumofdigitofsquare(number) != n) {

            int a = sumofdigitofsquare(number);

            if (a == 1)
                return true;
            if (m.find(a) == m.end()) {
                m[a]++;
            } else {
                return false;
            }
            number = a;
        }
        return false;
    }
};


