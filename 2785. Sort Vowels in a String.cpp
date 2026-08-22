// Solution of LeetCode Problem
// 2785. Sort Vowels in a String
// Solution in CPP

// Approach - 1
// Using Frequency Counting and Two-Pass Replacement
// Time Complexity: O(N) - Two passes over the string of size N to count and then sort the vowels
// Space Complexity: O(1) - Using a fixed-size auxiliary data structure (size 10) to store vowel counts

class Solution {
public:
    string sortVowels(string s) {
        vector<pair<char,int>> vowels = { 
            {'A',0},
            {'E',0},
            {'I',0},
            {'O',0},
            {'U',0},
            {'a',0},
            {'e',0},
            {'i',0},
            {'o',0},
            {'u',0}
        };

        int n = s.size();

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'A')
                vowels[0].second++;
            else if(s[i] == 'E')
                vowels[1].second++;
            else if(s[i] == 'I')
                vowels[2].second++;
            else if(s[i] == 'O')
                vowels[3].second++;
            else if(s[i] == 'U')
                vowels[4].second++;
            else if(s[i] == 'a')
                vowels[5].second++;
            else if(s[i] == 'e')
                vowels[6].second++;
            else if(s[i] == 'i')
                vowels[7].second++;
            else if(s[i] == 'o')
                vowels[8].second++;
            else if(s[i] == 'u')
                vowels[9].second++;
        }

        int idx = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'A' || s[i] == 'E' ||
               s[i] == 'I' || s[i] == 'O' ||
               s[i] == 'U' || s[i] == 'a' ||
               s[i] == 'e' || s[i] == 'i' ||
               s[i] == 'o' || s[i] == 'u')
            {
                while(idx < 10 && vowels[idx].second == 0)
                {
                    idx++;
                }

                s[i] = vowels[idx].first;
                vowels[idx].second--;
            }
        }

        return s;
    }
};