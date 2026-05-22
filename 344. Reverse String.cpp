// Solution of LeetCode Problem 
// 344. Reverse String
// Solution in CPP 

// Approach - 3 Using Recursion with two pointers

class Solution {
public:

    void reverseString(vector<char>& s) {
        reversee(0 , s.size()-1 ,s);
    }
private : 
    void reversee(int i , int j , vector<char>& s)
    {
        if(i >= j)
        {
            return  ;
        }
        swap(s[i] , s[j]);
        reversee(i+1 , j-1 , s);
    }
};

// Approach - 2 (Using While Loop Two Pointers)

class Solution2 {
public:
    void reverseString(vector<char>& s) {
        int i = 0 ; 
        int j= s.size()-1;
        while(i<=j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};

// Approach - 1 Using Recursion 

class Solution1 {
public:

    void reverseString(vector<char>& s) {
        reversee(0 ,s);
    }
private : 
    void reversee(int i , vector<char>& s)
    {
        if(i >= s.size()/2)
        {
            return  ;
        }
        swap(s[i] , s[s.size()-i-1]);
        reversee(i+1 , s);
    }
};