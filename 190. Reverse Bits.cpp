// Solution of LeetCode Problem 
// 190. Reverse Bits
// Solution in CPP 

// Approach - 1 
//  using 32 size of string

class Solution {
public:
    int reverseBits(int n) {
        string bits = "";

        for(int i = 0; i < 32; i++) {
            bits += to_string(n % 2);
            n /= 2;
        }

        int j = 0 ;
        int ans = 0 ;
         
        for(int i =bits.size()-1 ; i>=0 ;i--)
        {
            if(bits[i] == '1')
            {
                ans = ans + pow(2,j);
            }
            j++;
        }  
        return ans;
    }
};

// Appraoch - 2 
// Using bit manipulation

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for(int i = 0; i < 32; i++) {
            result = result << 1;   // shift result left
            result |= (n & 1);      // add last bit of n
            n = n >> 1;             // shift n right
        }
        
        return result;
    }
};