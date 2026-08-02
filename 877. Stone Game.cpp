// Soluiton of LeetCode POTD
// 877. Stone Game
// Solution in CPP

/** 
 * Because there are an even number of piles, Alex can force himself to take either all even-indexed piles or all odd-indexed piles. He first compares the total stones in those two groups, chooses the larger one, and since the total number of stones is odd, the two sums cannot be equal. Therefore, Alex is guaranteed to finish with more stones than Lee. This is why the mathematical solution is simply:   
 * 
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

// Approach - 1 (Using recusrsion)

class Solution1 {
public:
    int solve(vector<int>&piles , int i , int j  )
    {
        if( i == j )
        {
            return piles[i];
        }

        int left = piles[i] - solve(piles , i + 1 , j );
        int right = piles[j] - solve(piles , i , j - 1 );

        return max(left , right);

    }

    bool stoneGame(vector<int>& piles) {
        return int(solve(piles , 0 , piles.size() - 1)) > 0;
    }
};