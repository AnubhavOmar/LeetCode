// Solution of LeetCode POTD
// 1331. Rank Transform of an Array
// Solution in CPP 

// Approach - 1

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size() ;
        if (n==0) return {} ;
        unordered_map<int,vector<int>> ump1 ;
        unordered_map<int,int> ump2 ;
        for(int i = 0 ; i < n; i++)
        {
            ump1[arr[i]].push_back(i); 
        }

        sort(arr.begin(),arr.end());
        
        ump2[arr[0]] = 1;
        int rank = 1;
        for(int i = 1 ; i < n; i++)
        {
            if(arr[i] == arr[i-1])
            {
                ump2[arr[i]] = rank ;
            }
            else
            {
                rank++;
                ump2[arr[i]] = rank ;
            }
        }

        vector<int>ans(n);
        
        for(auto a : ump1)
        {
            if(a.second.size() == 1)
            {
                auto it = ump2.find(a.first);
                ans[a.second[0]] = it->second;
            }
            else
            {
                int m = a.second.size() ;
                auto it = ump2.find(a.first);
                for(int i = 0 ; i<m ; i++)
                {
                    ans[a.second[i]] = it->second;
                }
            }
        }
        return ans;
    }
};

// Approach - 2 
class Solution1 {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size() ;

        if (n==0) return {} ;

        unordered_map<int,int> ump ;
        
        vector<int> original = arr;
        sort(arr.begin(),arr.end());
        
        ump[arr[0]] = 1;
        int rank = 1;
        for(int i = 1 ; i < n; i++)
        {
            if(arr[i] == arr[i-1])
            {
                ump[arr[i]] = rank ;
            }
            else
            {
                rank++;
                ump[arr[i]] = rank ;
            }
        }

        vector<int>ans(n);
        
        for(int i = 0 ; i < n ; i++)
        {
            ans[i] = ump[original[i]];
        }
        return ans;
    }
};