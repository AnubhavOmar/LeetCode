// Solution of LeetCode POTD 
// 2833. Furthest Point From Origin
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0 ; 
        int right = 0 ; 
        int space = 0 ;
        for(int i =0 ; i<moves.size() ; i++)
        {
            if(moves[i]=='L')
            {
                left++;
            }
            else if(moves[i]=='R')
            {
                right++;
            }
            else space++;
        }
        // we have to go furtheset from point origin so 
        return abs(left-right) + space ;
    }
};