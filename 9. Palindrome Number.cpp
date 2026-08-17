// Solution of LeetCode Problem 
// 9. Palindrome Number
// Solution in CPP 

// Approach - 1 (Using String)

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false ;
        string s = to_string(x) ;
        int i = 0 ; 
        int j = s.size() - 1;
        while(i<j)
        {
            if(s[i] != s[j]) return false ;
            i++ ;
            j--;
        }
        return true;
    }
};

// Approach - 2 (Reversing the number)

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false ;
        long int n = x ; 
        long int reverse =0 ; 
        
        while(n!=0)
        {
            reverse = (reverse *10) + (n%10);
            n = n/10 ;
        }
        if (x == reverse)
        {
            return true ;
        }
        else return false ; 
    }
};