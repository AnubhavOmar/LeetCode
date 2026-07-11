// Solution of LeetCode problem 
// 3079. Find the Sum of Encrypted Integers
// Solution in CPP 

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0 ; 
        for(int i = 0 ; i <nums.size() ; i++)
        {
            sum += encrypt(nums[i]) ;
        }
        return sum ;
    }
    int encrypt(int number)
    {
        int count = 0 ; 
        int maxx = -1 ;
        while(number != 0)
        {
            maxx = max(maxx , number % 10);
            number /= 10 ;
            count++;
        }
        int encrypted_number = 0 ;
        int i  = 1 ;

        while(i<=count)
        {
            encrypted_number = (encrypted_number * 10) + maxx ; 
            i++;
        }
        return encrypted_number ;
    }
};