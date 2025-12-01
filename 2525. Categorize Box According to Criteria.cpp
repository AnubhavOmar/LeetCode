// Solution of the LeetCode problem
// 2525. Categorize Box According to Criteria
// Solution in CPP

// Appraoch - 1

class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        bool heavy = false;
        bool bulky = false;
        if ((length >= 10000 || width >= 10000 || height >= 10000) ||
            1LL * length * width * height >= 1000000000LL)
        {
            bulky = true;
        }
        if (mass >= 100)
            heavy = true;

        if (bulky && heavy)
            return "Both";
        if (bulky)
            return "Bulky";
        if (heavy)
            return "Heavy";
        else
            return "Neither";
    }
};