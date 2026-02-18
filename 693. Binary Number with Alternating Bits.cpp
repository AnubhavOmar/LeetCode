// Solution of LeetCode (POTD)
// 693. Binary Number with Alternating Bits
// Solution in CPP 

// Appraoch - 1 
// Storing the whole string then finding that adjacent bits exists or not 

// Time Complexity: O(log n)
// Space Complexity: O(log n)


class Solution {
public:
    bool hasAlternatingBits(int n) {
       string bits = "";
       while(n!=0)
       {
            bits += to_string(n%2);
            n /= 2 ;
       }

       for(int i = 1 ; i<bits.size();i++)
       {
        //checking previous bit with next bit 
        if(bits[i-1] == bits[i])
        {
            return false ;
        }
       } 
       return true ;

    }
};


// Appraoch - 2 
// without Storing the whole string, only storing previous bit because we have compare only adjacent bits only 

// Time Complexity: O(log n)
// Space Complexity: O(1)


class Solution {
public:
    bool hasAlternatingBits(int n) {
        int previous_bit = n % 2 ; // getting the previous bit 
        int current_bit ;
        n /= 2 ; // so dividing it one time because we have the last bit 
        while(n != 0)
        {
            current_bit = n % 2 ; // finding the current_bit 
            if(current_bit == previous_bit)
            {
                // checking the current and previous bit because adjacent does not have to be same 
                return false ;
            }
            previous_bit = current_bit ;
            // updating the previous bit 
            n /= 2 ;
        }
        return  true ;
    }
};



// Approach 3: XOR Trick (Optimal)

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        unsigned int x = n ^ (n >> 1); // shifts bits right and makes all bits 1 if number is alternating
        
        return (x & (x + 1)) == 0; //  checks if x is of form 111...111.
    }
};

