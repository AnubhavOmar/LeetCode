// Solution of LeetCode Problem 
// 1461. Check If a String Contains All Binary Codes of Size K


// Appraoch - 1  
// (Using set)



class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k )return false ;
        unordered_set<string>sett;
        for(int i = 0 ; i<=s.size() - k ; i++)
        {
            sett.insert(s.substr(i,k));
        }
        if(sett.size() == pow(2,k)) 
        {
            return true ;
        }
        return false ;
    }
};