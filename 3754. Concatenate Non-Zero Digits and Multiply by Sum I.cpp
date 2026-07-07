// Solution of LeetCode POTD
// 3754. Concatenate Non-Zero Digits and Multiply by Sum I
// Solution in CPP 

// Approach - 2 (Without Reversing the digits array)
class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<long long>digits;
        
        while(n!=0)
        {
            int digit = n % 10 ;
            if(digit != 0 )
            {
                digits.push_back(digit);
            }
            n /= 10 ;
        }

        long long sum = 0 ; 
        long long number = 0 ;
         
        for(int i = digits.size() - 1 ; i >= 0 ; i--)
        {
            sum += digits[i];
            number = (number * 10 ) + digits[i];
        }
        return sum * number ; 
    }
};

// Approach - 1 

class Solution1 {
public:
    long long sumAndMultiply(int n) {
        vector<long long>digits;
        
        while(n!=0)
        {
            int digit = n % 10 ;
            if(digit != 0 )
            {
                digits.push_back(digit);
            }
            n /= 10 ;
        }
        reverse(digits.begin(),digits.end());

        long long sum = 0 ; 
        long long number = 0 ;
         
        for(int i = 0 ; i < digits.size(); i++)
        {
            sum += digits[i];
            number = (number * 10 ) + digits[i];
        }
        return sum * number ;
    }
};