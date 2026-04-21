// Solution of LeetCode Problem 
// 2839. Check if Strings Can be Made Equal With Operations I
// Solution in CPP

// Approach - 1 

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        string s1_even = "";
        string s1_odd = "";


        for(int i= 0 ; i<4;i++)
        {
            if(i%2==0)
            {
                s1_even += s1[i];
            }
            else
            {
                s1_odd += s1[i];
            }
        }

        string s2_even = "";
        string s2_odd = "";


        for(int i= 0 ; i<4;i++)
        {
            if(i%2==0)
            {
                s2_even += s2[i];
            }
            else
            {
                s2_odd += s2[i];
            }
        }
        sort(s1_even.begin(), s1_even.end());
        sort(s1_odd.begin(), s1_odd.end());
        sort(s2_even.begin(), s2_even.end());
        sort(s2_odd.begin(), s2_odd.end());
        if( s1_even == s2_even && s1_odd == s2_odd )  return true ;
        return false;
    }
};