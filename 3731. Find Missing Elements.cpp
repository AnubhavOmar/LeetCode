// Solution of LeetCode POTD
// 3731. Find Missing Elements
// Solution in CPP

// Approach - 6 (Sorting + Single Pointer Traversal)
// Time Complexity  = O(n log n + (max - min))
// Space Complexity = O(1) (Ignoring the output array)

class Solution6 {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minn = INT_MAX ;
        int maxx = INT_MIN ;

        vector<int>ans; 

        int n = nums.size() ;

        for(int i = 0 ; i < n ; i++)
        {
            minn = min(minn , nums[i]) ;
            maxx = max(maxx , nums[i]) ;
        } 

        sort(nums.begin() , nums.end()) ;
        
        int idx = 0 ;
        
        for (int i = minn + 1; i < maxx; i++)
        {

            while (idx < n && nums[idx] < i)
            {
                idx++;
            }

            if (idx == n || nums[idx] != i)
            {
                ans.push_back(i);
            }
        }

        return ans;    
    }
};

// Approach - 5 (Sorting + Binary Search)
// Time Complexity  = O(n log n + (max - min) * log n)
// Space Complexity = O(1) (Ignoring the output array)

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minn = INT_MAX ;
        int maxx = INT_MIN ;

        vector<int>ans; 

        int n = nums.size() ;

        for(int i = 0 ; i < n ; i++)
        {
            minn = min(minn , nums[i]) ;
            maxx = max(maxx , nums[i]) ;
        } 

        sort(nums.begin() , nums.end()) ;
        
        for(int i = minn + 1 ; i < maxx ; i++)
        {
            if(!binary_search(nums.begin() , nums.end() , i))
            {
                ans.push_back(i) ;
            }
        }

        return ans;
    }
};

// Approach - 4 (Sorting and Comparing with Expected Values)
// Time Complexity  = O(n log n)
// Space Complexity = O(1) 

class Solution4 {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minn = INT_MAX ;
        int maxx = INT_MIN ;

        vector<int>ans; 

        int n = nums.size() ;

        for(int i = 0 ; i < n ; i++)
        {
            minn = min(minn , nums[i]) ;
            maxx = max(maxx , nums[i]) ;
        }

        sort(nums.begin() , nums.end());

        int idx = 0 ; 
        
        int correct_value = minn ;

        while(idx < n )
        {
            if(nums[idx] != correct_value)
            {
                ans.push_back(correct_value) ;
                correct_value++;
            }
            else
            {
                idx++ ;
                correct_value++ ;
            }
        }
        return ans;
    }
};

// Approach - 3 (Using Unordered Set to check every element in the range)
// Time Complexity  = O(n + (max - min))
// Space Complexity = O(n)
class Solution3 {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minn = INT_MAX ;
        int maxx = INT_MIN ;

        vector<int>ans; 

        int n = nums.size() ;
        unordered_set<int>st;

        for(int i = 0 ; i < n ; i++)
        {
            minn = min(minn , nums[i]) ;
            maxx = max(maxx , nums[i]) ;
            st.insert(nums[i]) ;
        }
  

        for(int i = minn + 1 ; i < maxx ; i++)
        {
            if(st.find(i) == st.end() )
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// Approach - 2 (Using Unordered Map to find the elements of the range does they exist in the nums or not)
// Time Complexity = O(n + (max - min))
// Space Complexity = O(n)
class Solution2 {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minn = INT_MAX ;
        int maxx = INT_MIN ;
        
        int n = nums.size() ;
        unordered_map<int,int>ump;

        for(int i = 0 ; i < n ; i++)
        {
            minn = min(minn , nums[i]) ;
            maxx = max(maxx , nums[i]) ;
            ump[nums[i]]++;
        }

        vector<int>ans;

        for(int i = minn + 1 ; i < maxx ; i++ )
        {
            if(ump.find(i) == ump.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Approach - 1 (Using Linear Search Function)
// Time Complexity = O(n^2)
// Space Complexity = O(1)

class Solution1 {
public:

    bool linear_search(vector<int>& nums , int target)
    {
        int n = nums.size() ; 
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] == target)
            {
                return true;
            }
        }
        return false; 
    }

    vector<int> findMissingElements(vector<int>& nums) {
        int minn = INT_MAX ;
        int maxx = INT_MIN ;
        
        int n = nums.size() ;

        for(int i = 0 ; i < n ; i++)
        {
            minn = min(minn , nums[i]) ;
            maxx = max(maxx , nums[i]) ;
        }

        vector<int>ans;

        for(int i = minn + 1 ; i < maxx ; i++)
        {
            if(!linear_search(nums , i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};