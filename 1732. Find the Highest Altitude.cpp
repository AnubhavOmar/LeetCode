// Solution of LeetCode POTD
// 1732. Find the Highest Altitude
// Solution in CPP

// Approach - 1 

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int altitude = 0 ;
        int maxx = 0 ;
        for(int i = 0 ; i  < n ; i++)
        {
            altitude += gain[i];
            maxx = max(maxx,altitude) ;
        }
        return maxx;
    }
};