// Solution of LeetCode POTD
// 3517. Smallest Palindromic Rearrangement I
// Solution in CPP

// Approach - 3
// Time Complexity: O(n log k)
// Space Complexity: O(n)

class Solution3 {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        string ans_string = "";

        map<char,int> mp ;

        for(int i = 0 ; i < n ; i++)
        {
            mp[s[i]]++;
        }

        string middle = "";

        for(auto a : mp)
        {
            if(a.second % 2 != 0 )
            {
                middle += a.first;
            }
        
            for(int j = 0 ; j < a.second / 2 ; j++)
            {
                ans_string += a.first ;
            }
        }

        string reverse_string = ans_string;

        reverse(reverse_string.begin() , reverse_string.end());

        ans_string = ans_string + middle + reverse_string ;

        return ans_string;
    }
};



// Approach - 2
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution2 {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        string ans_string = "";

        int limit = (n % 2 == 0) ? (n - 1) / 2 : (n / 2) - 1;

        for (int i = 0 ; i <= limit ; i++)
        {
            ans_string += s[i];
        }

        sort(ans_string.begin(), ans_string.end());

        string reverse_ans_string = ans_string;

        reverse(reverse_ans_string.begin(), reverse_ans_string.end());

        if (n % 2 == 0)
        {
            ans_string += reverse_ans_string;
        }
        else
        {
            ans_string += s[n / 2];
            ans_string += reverse_ans_string;
        }

        return ans_string;
    }
};



// Approach - 1
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution1 {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        if(n % 2 == 0 )
        {
            string ans_string = "" ;

            for(int i = 0 ; i <= (n-1) / 2 ; i++)
            {
                ans_string += s[i];
            }

            sort(ans_string.begin() , ans_string.end());

            string reverse_ans_string = ans_string ;

            reverse(reverse_ans_string.begin() , reverse_ans_string.end() );

            ans_string = ans_string + reverse_ans_string ;

            return ans_string ;
        }
        else
        {
            string ans_string = "" ;
            
            for(int i = 0 ; i < n / 2 ; i++)
            {
                ans_string += s[i];
            }

            sort(ans_string.begin() , ans_string.end()) ; 

            string reverse_ans_string = ans_string ;

            reverse(reverse_ans_string.begin() , reverse_ans_string.end() ) ;

            ans_string = ans_string + s[n/2] + reverse_ans_string ;

            return ans_string ;
        }
    }
};