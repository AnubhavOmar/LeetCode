// Solution of LeetCode POTD 
// 1404. Number of Steps to Reduce a Number in Binary Representation to One 
// Solution in CPP 

// Appraoch - 1 

class Solution {
public:
    int numSteps(string s) {
        long long  number = 0 ; 
        int j = 0 ;
        for(int i = s.size() - 1 ; i>=0 ; i--)
        {
            if(s[i] == '1')
            {
                number += pow(2,j);
            }
            j++;
        }
        
        int ans = 0 ; 
        while(number != 1)
        {
            if(number % 2 == 0)
            {
                number /= 2 ;
            }
            else 
            {
                number++;
            }
            ans++;
        }
        return ans ;
    }
};

// Approach - 2 
// not finding the number only interating to the string of bits and updating it according to the even odd conditions 

class Solution {
public:
    int numSteps(string s) {
        int carry = 0 ; 
        int ans = 0 ; 
        for(int i = s.size() - 1 ; i>0; i--)
        {
            int bit = (s[i] - '0' ) + carry ;
            if(bit == 0)
            {
                // number agar even hai to seedha divide kiya 
                ans++;
            }
            else if(bit == 1)
            {
                // agr number odd hota hai to 
                carry = 1 ;
                ans += 2 ;
            }
            else
            {
                // agr carry hone ke baad 1 bit number increase ho jata hai to  
                // means 11 + 1 = 100  bits 
                ans++;
                carry = 1; 
            }
        }
        return  ans +carry ;
    }
};