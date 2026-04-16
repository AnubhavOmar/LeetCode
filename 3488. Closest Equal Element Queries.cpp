// Solution of LeetCode Problem 
// 3488. Closest Equal Element Queries
// Solution in CPP 

// Approach - 2 (Using Binary Search)

class Solution {
public:
    
    // function to find the element 
    int findPosition(vector<int>& list, int target) {
        int low = 0, high = list.size() - 1;
        int ans = list.size(); 

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(list[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        // processing queries
        for(int i = 0; i < queries.size(); i++) {
            int q = queries[i];
            vector<int>& list = mp[nums[q]];

            if(list.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int pos = findPosition(list, q);
            int m = list.size();

            // circular next and prev
            int next = list[(pos + 1) % m];
            int prev = list[(pos - 1 + m) % m];

            int dist1 = abs(q - next);
            int dist2 = abs(q - prev);

            int minn = min({dist1, n - dist1, dist2, n - dist2});

            ans.push_back(minn);
        }

        return ans;
    }
};


// Approach - 1 (Brute Force)


class Solution1 {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;

        // inserted all elements with their indexes in the array 
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        // processing each query and finding the closest distance 
        for(int i = 0; i < queries.size(); i++) {
            int q = queries[i];  
            vector<int> list = mp[nums[q]]; 

            int minn = INT_MAX;

            for(int j = 0; j < list.size(); j++) {
                int idx = list[j];  

                if(q != idx) {
                    int dist = abs(q - idx);                    
                    int circularDist = nums.size() - dist;     // for circular list   
                    minn = min(minn, min(dist, circularDist));   
                }
            }

            if(minn == INT_MAX) ans.push_back(-1);
            else ans.push_back(minn);
        }

        return ans;
    }
};