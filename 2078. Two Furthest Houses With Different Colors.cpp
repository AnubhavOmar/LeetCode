// Solution of LeetCode POTD 
// 2078. Two Furthest Houses With Different Colors
// Solution in CPP 

// Approach - 1 
// first fixing the i and traversing to the right 
// second fixing the j and traversing to the left  

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = INT_MIN ;
        
        if(colors[0] != colors[colors.size()-1]) return colors.size() - 1;

        int i = 0 ; 
        int j = colors.size() - 1 ;
        while( i < j )
        {
            if(colors[i] != colors[j])
            {
                ans = max(ans , abs(i-j));
            }
            j--;
        }

        i = 0 ; 
        j = colors.size() - 1;
        while( i < colors.size() )
        {
            if(colors[i] != colors[j])
            {
                ans = max(ans , abs(i-j));
            }
            i++;
        }
        return ans ;
    }
};