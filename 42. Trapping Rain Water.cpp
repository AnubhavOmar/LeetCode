// Solution of LeetCode Problem 
// 42. Trapping Rain Water 
// Solution in CPP 

// Main formula will be used  
/*

ans += min(lmax, rmax) - height[i];  
here  
rmax = Right side maximum height building form the i-th building 
lmax = Left side maximum height building form the i-th building 

*/

// Approach - 1  (Brute Force) Time Complexity = n^2 

class Solution {
public:
    int trap(vector<int>& height) {
        // brute force 
        int n = height.size();
        int ans = 0;

        for (int i = 1; i < n - 1; i++) {
            int lmax = 0, rmax = 0;

            for (int j = i; j >= 0; j--) {
                lmax = max(lmax, height[j]);
            }

            for (int j = i; j < n; j++) {
                rmax = max(rmax, height[j]);
            }

            ans += min(lmax, rmax) - height[i]; 
        }

        return ans;
    }
};

// Approach 2 More Time saving 
//  Same like Brute force but in this we take two array's in which store the left max building height and right max building height of the i-th index so 
// Time complexity = O(n)  and Space complexity = O(n^2)

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)
            return 0;
        vector<int> left_side(height.size());

        vector<int> right_side(height.size());

        left_side[0] = height[0];

        for (int i = 1; i < height.size(); i++) 
        {
            left_side[i] = max(left_side[i - 1], height[i]);
        }

        right_side[height.size() - 1] = height[height.size() - 1];

        for (int i = height.size() - 2; i >= 0; i--)
        {
            right_side[i] = max(right_side[i + 1], height[i]);
        }

        int ans = 0;

        for (int i = 0; i < height.size(); i++) 
        {
            ans += min(left_side[i], right_side[i]) - height[i];
        }

        return ans;
    }
};

// Appraoch - 3 Optimal Appraoch 

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int lmax = 0;
        int rmax = 0;

        int ans = 0;

        while (l < r) {
            if (height[l] <= height[r])
            { // left side
                if (lmax > height[l])
                {
                    ans += lmax - height[l]; 
                }
                else
                {
                    lmax = height[l];
                }
                l++; 
            }
            else
            { // right side
                if (rmax > height[r])
                {
                    ans += rmax - height[r]; 
                } 
                else
                {
                    rmax = height[r];
                }
                r--; 
            }
        }

        return ans;
    }
};
