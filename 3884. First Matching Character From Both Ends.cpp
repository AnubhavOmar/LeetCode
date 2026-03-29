//Solution of LeetCode Problem 
// 3884. First Matching Character From Both Ends
// Approach -  1 (Using Two Pointers )

class Solution {
public:
    int firstMatchingIndex(string s) {
        int i = 0 ; 
        int j = s.size() - 1 ;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                return i  ;
            }
            i++;
            j--;
        }
        return -1 ; 
    }
};


// Approach - 2 (Using only i variable)

class Solution {
public:
    int firstMatchingIndex(string s) {
        int i = 0 ; 

        while(i<=s.size() - i - 1)
        {
            if(s[i]==s[s.size() - i - 1])
            {
                return i  ;
            }
            i++; 
        }
        return -1 ; 
    }
};
