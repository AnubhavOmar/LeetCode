// Solution of LeetCode POTD
// 796. Rotate String
// Solution in CPP 

// Approach : 1 (Concating the given string and then finding the goal as a substring of it) 

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        // concating the given string and then finding subtring which is the goal  
        string conctenated_String = s + s ;
        return conctenated_String.find(goal) != string::npos;
    }
};