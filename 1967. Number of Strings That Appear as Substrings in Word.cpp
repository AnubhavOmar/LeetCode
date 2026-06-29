// Solution of LeetCode POTD 
// 1967. Number of Strings That Appear as Substrings in Word
// Solution in CPP

// Approach - 1 (Using built-in function to find substring in word)

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0 ; 
        for(int i = 0 ; i<patterns.size(); i++)
        {
            if(word.contains(patterns[i]))
            {
                count++;
            }
        }
        return count;
    }
};