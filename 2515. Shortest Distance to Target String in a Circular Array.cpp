// Solution of LeetCode POTD
// 2515. Shortest Distance to Target String in a Circular Array
// Solution in CPP 

// Approach  - 1  (Using two pointers)

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();

        if(words[startIndex] == target) return 0 ;
       
        int i = startIndex  - 1 ;
        int j = startIndex  + 1 ;


        for(int step = 1; step < n; step++)
        {
            if (words[(i + n) % n] == target)
            {
                return step;
            }

            if (words[j % n] == target)
            {
                return step;
            }

            i--;
            j++;
        }

        return -1; 
    }
};