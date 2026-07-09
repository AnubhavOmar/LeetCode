// Solution of LeetCode POTD
// 3532. Path Existence Queries in a Graph I
// Solution in CPP 

// Approach - 3 (Preprocess the connected components and track them using a prefix array)

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<bool>connected( n - 1, true);
        for(int i = 0 ; i<n-1;i++)
        {
            if((abs(nums[i] - nums[i+1] ) > maxDiff))
            {
                connected[i] = false;
            }
        }

        vector<int> prefix(n, 0);

        for (int i = 0; i < n - 1; i++)
        {
            prefix[i + 1] = prefix[i];

            if (connected[i] == false)
            {
                prefix[i + 1]++;
            }
        }

        vector<bool> ans;

        for (int i = 0; i < m; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];

            int brokenEdges = prefix[r] - prefix[l];

            if (brokenEdges == 0)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }

        return ans;
    }
};

// Approach - 2 (Pre-processing the connected paht)
class Solution2 {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<bool>connected( n - 1, true);
        for(int i = 0 ; i<n-1;i++)
        {
            if((abs(nums[i] - nums[i+1] ) > maxDiff))
            {
                connected[i] = false;
            }
        }

        vector<bool>ans( m , false);

        for(int i = 0 ; i < m ; i++)
        {
            int left = min(queries[i][0] , queries[i][1]);
            int right = max(queries[i][0] , queries[i][1]);
            
            ans[i] = true ;

            int j = left ;

            while( j < right )
            {
                if(!(connected[j]))
                {
                    ans[i] = false ;
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};

// Approach - 1 (Brute Force Approach)
class Solution1 {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) 
    {
            int m = queries.size(); 
            vector<bool> ans(m, false);

            for (int i = 0; i < m; i++)
            {
                int left = min(queries[i][0], queries[i][1]);
                int right = max(queries[i][0], queries[i][1]);

                int j = left;

                if (left == right)
                {
                    ans[i] = true;
                    continue;
                }

                int k = j + 1;
                int count = 0;

                while (k <= right)
                {
                    if (abs(nums[j] - nums[k]) <= maxDiff)
                    {
                        count++;
                    }
                    else 
                    {
                        break; 
                    }

                    j++;
                    k++;
                }

                int ans_canBe = right - left;

                if (count == ans_canBe)
                {
                    ans[i] = true;
                }
            }

            return ans;
    }
};
