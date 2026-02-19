// Solution of LeetCode POTD 
// 696. Count Binary Substrings
// Solution in CPP 


// Approach - 1 
// using an vector to store group size 
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> countt ;
        int count = 1 ; 
        for(int i = 0 ; i<s.size()-1;i++)
            if(s[i]==s[i+1])
            {
                count++;
            }
            else 
            {
                countt.push_back(count);
                count=1 ;
            }
        
        countt.push_back(count);
        int ans = 0 ;

        for(int i = 1 ; i<countt.size(); i++)
        {
            ans += min(countt[i-1] , countt[i]);
        }
        return ans; 
    }
};


// Appraoch - 2 

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevGroup = 0;
        int currGroup = 1;
        int ans = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                currGroup++;
            } else {
                ans += min(prevGroup, currGroup);
                prevGroup = currGroup;
                currGroup = 1;
            }
        }
        ans += min(prevGroup, currGroup);
        return ans;
    }
};