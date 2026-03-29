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
