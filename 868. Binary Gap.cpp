// Solution of LeetCode POTD 
// 868. Binary Gap
// Solution in CPP 

// Approach - 1 
// Time Complexity = O(log n)
// Space Complexity = O(log n)

class Solution {
public:
// __builtin_popcount(number) which counts that how many '1' bits does the number contain in binary.
    int binaryGap(int n) {
        if(__builtin_popcount(n) == 1) 
        {
            return 0 ;
        }
        string bits = "";
        while(n!=0)
        {
            bits += to_string(n%2);
            n /= 2 ;
        }
        int i = 0 ; 
        for(int j = 0 ; j<bits.size() ;j++)
        {
            if(bits[j] == '1')
            {
                i = j  ;
                break ;
            }
        }
        int j = i +1 ;
        int ans = - 1 ;
        while(j<bits.size())
        {
            if(bits[j]=='1')
            {
                ans = max(ans , abs(i-j));
                i = j ; 
            }
            j++;
        }
        return ans ;
    }
};
