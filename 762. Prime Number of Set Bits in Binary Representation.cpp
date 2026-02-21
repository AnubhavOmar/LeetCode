// Solution of LeetCode POTD 
// 762. Prime Number of Set Bits in Binary Representation
// Solution in CPP 


// Approach - 3 
// using a built in function which can give count of 1 bits in number  

// Time Complexity = O(N)
// Space Complexity = O(1)


class Solution{
    public:
    int countPrimeSetBits(int left, int right) {
        
        int ans = 0 ;
        for(int i = left ; i<=right ;i++)
        {
            int bits_1 = __builtin_popcount(i) ;
            if(check_prime(bits_1))
            {
                ans++;
            }
        }
        return ans ;
    }
    private : 
    bool check_prime(int n )
    {
        if(n==0 || n==1 ) return false ;
        for(int i = 2 ; i<= sqrt(n); i++)
        {
            if( n % i == 0 )
            {
                return false ;
            }
        }
        return true ;
    }
};

// Approach - 2 
// more space optimal that appraoch - 1 beacuse in this we are not creating the counted_bits array 

// Time Complexity = O(N * log n)
// Space Complexity = O(1)

class Solution {
    public:
    int countPrimeSetBits(int left, int right) {
        
        int ans = 0 ;
        for(int i = left ; i<=right ;i++)
        {
             if(check_prime(count_1(i)))
            {
                ans++;
            }
        }
        return ans ;
    }

private :
    
    int count_1(int n)
    {
        int count = 0 ; 
        while(n != 0)
        {
            if(n%2==1)
            {
                count++;
            }
            n /= 2;
        }
        return count ;
    }
private : 
    bool check_prime(int n )
    {
        if(n==0 || n==1 ) return false ;
        for(int i = 2 ; i<= sqrt(n); i++)
        {
            if( n % i == 0 )
            {
                return false ;
            }
        }
        return true ;
    }

};


// Appraoch - 1 
// Time Complexity = O(N * log n)
// Space Complexity = O(N)


class Solution {
    public:
    int countPrimeSetBits(int left, int right) {
        
        vector<int>counted_bits ;
        
        for(int i = left ; i<=right ;i++)
        {
            counted_bits.push_back(count_1(i));
        }
        int ans = 0 ;
        for(int i = 0 ; i<counted_bits.size();i++)
        {
            if(check_prime(counted_bits[i]))
            {
                ans++;
            }
        }
        
        return ans ;
    }
    
    private :
    
    int count_1(int n)
    {
        int count = 0 ; 
        while(n != 0)
        {
            if(n%2==1)
            {
                count++;
            }
            n /= 2;
        }
        return count ;
    }
    private : 
    bool check_prime(int n )
    {
        if(n==0 || n==1 ) return false ;
        for(int i = 2 ; i<= sqrt(n); i++)
        {
            if( n % i == 0 )
            {
                return false ;
            }
        }
        return true ;
    }
    
};