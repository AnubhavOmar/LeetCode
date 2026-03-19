// Solution of LeetCode 
// 2278. Percentage of Letter in String 
// Solution in CPP

// Approach - 1 (Using a For loop)

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0; 
        for(int i = 0 ; i <s.size() ; i++)
        {
            if(s[i] == letter ) count++;
        }
        return int((count *100 /s.size())) ;
    }
};


// Approach - 2 (Using in built Function)

class Solution {
public:
    int percentageLetter(string s, char letter) {
        
        int countt = count(s.begin() , s.end() , letter); 
        
        return int((countt *100 /s.size())) ;
    }
};