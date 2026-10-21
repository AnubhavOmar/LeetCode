// Solution of LeetCode Problem
// 658. Find K Closest Elements
// Solution in CPP

// Approach - 1
// Using Binary Search, Two Pointers, and Sorting
// Time Complexity: O(log n + k log k) - Binary search takes O(log n), selecting k elements takes O(k), and sorting the result takes O(k log k).
// Space Complexity: O(k) - The result vector stores k elements; auxiliary space excluding the output is O(1).

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size() == 1) return arr;
        int low = 0 ;
        int high = arr.size() - 1;
        while(low < high)
        {
            int mid = low + (high - low) / 2;

            if(arr[mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid ;
            }
        }
        
        int left = low - 1;
        int right = low ;
        vector<int>ans ;

        while(ans.size() < k && left >= 0 && right < arr.size())
        {
            // here we calculate the distance 
            int leftDistance = abs(arr[left] - x);
            int rightDistance = abs(arr[right] - x);

            if(leftDistance < rightDistance)
            {
                ans.push_back(arr[left]);
                left-- ;
            }
            else if(leftDistance > rightDistance)
            {
                ans.push_back(arr[right]);
                right++;
            }
            else
            {
                if(arr[left] < arr[right])
                {
                    ans.push_back(arr[left]) ;
                    left--;
                }
                else
                {
                    ans.push_back(arr[right]);
                    right++;
                }
            }
        }

        // let assume that right reach to end of array ans still answer vector doesnot have k elements in it then moving the opposite pointer and reaching to kth elements in the answer vector 
        while(ans.size() < k && left >= 0)
        {
            ans.push_back(arr[left]);
            left--;
        }
        // let assume that left reached start of the array ans still answer vector doesnot have k elements in it then moving the opposite pointer and reaching to kth elements in the answer vector
        while(ans.size() < k && right < arr.size())
        {
            ans.push_back(arr[right]) ;
            right++;
        }

        sort(ans.begin() ,ans.end());
        return ans;
    }
};