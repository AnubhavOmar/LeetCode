// Sollution of LeetCode problem 
// 3783. Mirror Distance of an Integer


// Approach - 2 (Using reverse function)


class Solution2 {
public:
    int mirrorDistance(int n) {
        
        return abs(n - reverse(n));
    }
private : 
    int reverse(int n)
    {
        int  reversed_number = 0 ; 
        while(n%10==0)
        {
            n /= 10 ;
        }

        while(n!=0)
        {
            reversed_number = reversed_number * 10 + n % 10 ; 
            n /= 10 ; 
        }
        return reversed_number ;
    }
};



// Approach - 1 (Using String variable)

class Solution1 {
public:
    int mirrorDistance(int n)
    {
        int number = n ;
        while(number % 10 ==0)
        {
            number /= 10 ;
        }
        string s = to_string(number) ;
        reverse(s.begin() , s.end()) ;
        return abs(n - stoi(s));
    }  
};