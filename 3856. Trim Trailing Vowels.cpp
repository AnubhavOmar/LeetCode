//  Solution of LeetCode Problem 
// 3856. Trim Trailing Vowels 
// Solution in CPP 

// Appraoch - 1 

class Solution {
public:
    string trimTrailingVowels(string s) {
        for(int i = s.size() - 1 ; i>=0 ; i--)
        {
            if(s[i] == 'a' || s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u')
            {
                s.pop_back() ;
            }
            else return s ;
        }  
        return s ;
    }
};