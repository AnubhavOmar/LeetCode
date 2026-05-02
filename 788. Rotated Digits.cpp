// Solution of LeetCode POTD 
// 788. Rotated Digits
// Solution in CPP 

// Approach - 1  

class Solution {
public:
    int rotatedDigits(int n) {
      int count = 0 ; 
      for(int i = 1 ; i<=n; i++)
      {
        bool valid = true;
        bool changed = false;
        int number = i ;
        while(number != 0)
        {
            int digit  = number % 10 ;
            if( digit == 3 || digit == 7 || digit == 4)
            {
                valid = false ;
                break ;
            }
            if( digit == 2 || digit == 5 || digit == 6 || digit == 9 )
            {
                changed = true ;
            }
            number /= 10 ;
        }
        if(valid && changed)
        {
            count++;
        }
      }  
      return count ;
    }
};