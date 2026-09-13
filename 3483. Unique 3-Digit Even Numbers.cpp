// Solution of LeetCode Problem
// 3483. Unique 3-Digit Even Numbers
// Solution in CPP

// Approach - 1
// Using Frequency Vector and Number Enumeration
// Time Complexity: O(N) - Building the frequency vector takes O(N), followed by a fixed range of three-digit numbers
// Space Complexity: O(1) - Using a fixed-size frequency vector of size 10

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // set<int> st(digits.begin(), digits.end());
        int ans = 0;
        
        // unordered_map<int,int>ump;
        vector<int>mp_vec (10 , 0) ;

        for(int i = 0 ; i < digits.size() ; i++)
        {
            mp_vec[digits[i]]++ ;
        }

        for (int i = 100; i <= 999; i++)
        {
            int number = i;

            if (i % 2 == 0)
            {
                int c = number % 10;
                number /= 10;

                int b = number % 10;
                number /= 10;

                int a = number % 10;

                mp_vec[a]--;
                mp_vec[b]--;
                mp_vec[c]--;

                if(mp_vec[a] >= 0 && mp_vec[b] >= 0 && mp_vec[c] >= 0)
                {
                    ans++;
                }
                
                mp_vec[a]++;
                mp_vec[b]++;
                mp_vec[c]++;
                
            }
        }

        return ans;
    }
};



// Approach - 2
// Using Ordered Set and Frequency Vector
// Time Complexity: O(N) - Building containers over digits 0 through 9 takes O(N), followed by fixed-range enumeration
// Space Complexity: O(1) - The set and frequency vector store values from a fixed digit range

class Solution3 {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> st(digits.begin(), digits.end());
        int ans = 0;

        // unordered_map<int,int>ump;
        vector<int>mp_vec (10 , 0) ;

        for(int i = 0 ; i < digits.size() ; i++)
        {
            mp_vec[digits[i]]++ ;
        }

        for (int i = 100; i <= 999; i++)
        {
            int number = i;

            if (i % 2 == 0)
            {
                int c = number % 10;
                number /= 10;

                int b = number % 10;
                number /= 10;

                int a = number % 10;

                if (st.find(c) != st.end() &&
                    st.find(b) != st.end() &&
                    st.find(a) != st.end())
                {
                    mp_vec[a]--;
                    mp_vec[b]--;
                    mp_vec[c]--;

                    if(mp_vec[a] >= 0 && mp_vec[b] >= 0 && mp_vec[c] >= 0)
                    {
                        ans++;
                    }
                    
                    mp_vec[a]++;
                    mp_vec[b]++;
                    mp_vec[c]++;
                }
            }
        }

        return ans;
    }
};


// Approach - 3
// Using Unordered Set and Unordered Map
// Time Complexity: O(N) - Building the hash containers takes O(N) on average, followed by fixed-range enumeration
// Space Complexity: O(1) - Hash containers hold only the fixed set of possible digits

class Solution2 {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> st(digits.begin(), digits.end());
        int ans = 0;
        unordered_map<int,int>ump;

        for(int i = 0 ; i < digits.size() ; i++)
        {
            ump[digits[i]]++ ;
        }

        for (int i = 100; i <= 999; i++)
        {
            int number = i;

            if (i % 2 == 0)
            {
                int c = number % 10;
                number /= 10;

                int b = number % 10;
                number /= 10;

                int a = number % 10;

                if (st.find(c) != st.end() &&
                    st.find(b) != st.end() &&
                    st.find(a) != st.end())
                {
                    ump[a]--;
                    ump[b]--;
                    ump[c]--;

                    if(ump[a] >= 0 && ump[b] >= 0 && ump[c] >= 0)
                    {
                        ans++;
                    }

                    ump[a]++;
                    ump[b]++;
                    ump[c]++;
                }
            }
        }

        return ans;
    }
};


// Approach - 4
// Using Ordered Set and Unordered Map
// Time Complexity: O(N) - Building containers over digits 0 through 9 takes O(N) on average, followed by fixed-range enumeration
// Space Complexity: O(1) - Containers hold only the fixed set of possible digits

class Solution1 {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> st(digits.begin(), digits.end());
        int ans = 0;
        unordered_map<int,int>ump;

        for(int i = 0 ; i < digits.size() ; i++)
        {
            ump[digits[i]]++ ;
        }

        for (int i = 100; i <= 999; i++)
        {
            int number = i;

            if (i % 2 == 0)
            {
                int c = number % 10;
                number /= 10;

                int b = number % 10;
                number /= 10;

                int a = number % 10;

                if (st.find(c) != st.end() &&
                    st.find(b) != st.end() &&
                    st.find(a) != st.end())
                {
                    ump[a]--;
                    ump[b]--;
                    ump[c]--;

                    if(ump[a] >= 0 && ump[b] >= 0 && ump[c] >= 0)
                    {
                        ans++;
                    }
                    
                    ump[a]++;
                    ump[b]++;
                    ump[c]++;
                }
            }
        }

        return ans;
    }
};
