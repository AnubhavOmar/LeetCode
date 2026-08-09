// Solution of GFG Problem 
// Find Kth Rotation = https://www.geeksforgeeks.org/problems/rotation4723/1
// Solution in CPP 


// Approach 1 :
// - Use Binary Search to find the minimum element in the rotated sorted array.
// - The index of the minimum element corresponds to the number of times the array has been rotated (K times).
// - Keep track of the minimum value and its index as we narrow down the search space in each step.
// Time Complexity: O(log N), where N is the size of the array, as the search space is halved in each step.
// Space Complexity: O(1), as no extra space is used.

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size() ;
        int low = 0 ;
        int high = n - 1 ;
        int ans = INT_MAX ;
        int idx = 0 ;
        while(low <= high)
        {

            int mid = low + (high - low) / 2 ;

            if(arr[low] <= arr[mid])   // Left half is sorted
            {
                // first find left is sorted then storing the low ptr value because it will pointing to the smallest element on that sorted part 
                if(arr[low] < ans)
                {
                    idx = low ;
                    ans = arr[low] ;
                }
                low = mid + 1;
            }
            else                         // Right half is sorted
            {
                // here right part is sorted then storing the mid ptr value because it will pointing to the smallest element on the right sorted part 
                if(arr[mid] < ans)
                {
                    idx = mid ;
                    ans = arr[mid] ;
                }
                high = mid - 1;
            }
        }        
        return idx;
    }
};


// Approach 2 :
// Time Complexity: O(N), where N is the size of the array.
// Space Complexity: O(1), as no extra space is used.

class Solution1 {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size() ;
        int idx = -1 ;
        for(int i = 1 ; i < n ; i++)
        {
            if(arr[i] < arr[i-1])
            {
                return i ;
            }
        }
         return 0 ;
    }
};