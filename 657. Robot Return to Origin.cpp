// Solution of LeetCode Problem 
// 657. Robot Return to Origin
// Solution in CPP

// Approach - 1  (Using  Unordered Map)

class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char , int> mp ;
        for(int i = 0 ; i<moves.size() ; i++)
        {
            mp[moves[i]]++ ;
        }  

        int left_right_movement = abs(mp['L'] - mp['R']);
        int up_down_movement = abs(mp['U'] - mp['D']);
        
        if(left_right_movement==0 && up_down_movement== 0)
        {
            return true ;
        }
        return false ;

    }
};