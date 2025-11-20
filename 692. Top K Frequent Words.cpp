// Solution of LeetCode Problem 
// 692. Top K Frequent Words

// Appraoch - 1 
class Solution {
public:
    static bool cmp(const pair<string,int> &a, const pair<string,int> &b) {
        if(a.second == b.second)
            return a.first < b.first;  
        return a.second > b.second;    
    }

    vector<string> topKFrequent(vector<string>& words, int k) {

        map<string,int> m;
        for(auto &a : words)
            m[a]++;

        vector<pair<string,int>> v(m.begin(), m.end());

        sort(v.begin(), v.end(), cmp);

        vector<string> ans;
        for(int i=0 ; i<k ; i++)
            ans.push_back(v[i].first);

        return ans;
    }
};
