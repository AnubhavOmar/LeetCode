// Solution of LeetCode Problem 
// 989. Add to Array-Form of Integer 
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

        int i = num.size() - 1;
        int carry = k;

        vector<int> ans;

        while (i >= 0 || carry > 0) 
        {
            if (i >= 0) 
            {
                carry += num[i];
                i--;
            }

            ans.push_back(carry % 10); 
            carry /= 10;               
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
