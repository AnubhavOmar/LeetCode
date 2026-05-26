// Solution of LeetCode POTD
// 3120. Count the Number of Special Characters I
// Solution in CPP 

// Approach - 1 (Using HashMap)

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>ump;

        for(int i = 0 ; i<word.size();i++)
        {
            ump[word[i]]++;
        }
        int count = 0 ;
        for(auto a : ump)
        {
            if(ump.find(int(a.first+32)) != ump.end())
            {
                count++;
            }
        }
        return count;
    }
};