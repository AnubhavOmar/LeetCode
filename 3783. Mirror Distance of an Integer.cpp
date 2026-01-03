// Sollution of LeetCode problem 
// 3783. Mirror Distance of an Integer



// Approach - 1 


class Solution {
public:
    int mirrorDistance(int n) {
        int num = n ;
        int reverse = 0 ;  
        while(num !=0)
        {
            reverse = reverse *10 + num % 10 ;
            num /= 10 ;
        }
        return (abs(reverse - n));
    }
};