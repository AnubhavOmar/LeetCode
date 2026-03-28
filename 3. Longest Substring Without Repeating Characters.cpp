// Solution of LeetCode Problem 
// 3. Longest Substring Without Repeating Characters
// Solution in  CPP 

// Approach - 1 (Using Map and sliding window Concept )

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 1 ) return 1 ;
        if(s.empty()) return 0 ;
        
        unordered_map<char , int > mp ;
        int ans = 0 ;
        int left  = 0 ; 

        for(int i = 0 ; i<s.size() ; i++)
        {
            if(mp.find(s[i]) != mp.end() )  // when we find the duplicate          
            {
                
                left =  max(left,mp[s[i]] + 1); // this will update the left pointer which will help us to calculate the actual substring size 
                mp[s[i]] = i ;
            }
            else 
            {
                mp[s[i]]= i ;
            }
                ans = max(ans, i - left + 1);
                // every time updting the window size 
        } 
        return ans ;
    }
};