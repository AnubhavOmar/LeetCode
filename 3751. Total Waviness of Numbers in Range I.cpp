// Solution of LeetCode POTD
// 3751. Total Waviness of Numbers in Range I
// Solution in CPP

// Approach - 2
// Not storing the numbers directly processing them

class Solution {
public:
    int totalWaviness(int num1, int num2) {

        int count = 0;

        for (int i = num1; i <= num2; i++) {
            string s = to_string(i);

            if (s.size() > 2) {
                for (int j = 1; j < s.size() - 1; j++) {

                    if ((s[j - 1] < s[j]) && (s[j + 1] < s[j])) {
                        count++;
                    }
                    else if ((s[j - 1] > s[j]) && (s[j + 1] > s[j])) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};


// Approach - 1
// First storing the numbers and then processing them
class Solution1 {
public:
    int totalWaviness(int num1, int num2) {
        vector<string> number;
        for (int i = num1; i <= num2; i++)
        {
            number.push_back(to_string(i));
        }

        int count = 0;
        for (int i = 0; i < number.size(); i++)
        {
            if (number[i].size() > 2)
            {
                string s = number[i];
                for (int j = 1; j < s.size() - 1; j++)
                {
                    if ((s[j - 1] < s[j]) && (s[j + 1] < s[j]))
                    {
                        count++;
                    }
                    else if ((s[j - 1] > s[j]) && (s[j + 1] > s[j]))
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
