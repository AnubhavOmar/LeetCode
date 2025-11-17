// Solution of the LeetCode problem 
// 2418. Sort the People

// Approach 1 optimal 
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map <int,string,greater<int>>m ;
        for (int i = 0 ; i<heights.size(); i++)
        {
            m[heights[i]] = names[i];
        }
        int i = 0 ;
        for(auto a : m)
        {
            names[i] = a.second;
            i++;
        }
        return names ;
    }
};




// Approach 2 
// optimal but not that much time = O(n^2) 

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans ;
        for(int i = 0 ; i<heights.size();i++)
        {
            int maxh = i;
            for(int j = i +1; j<heights.size() ;j++)
            {
                if(heights[maxh]<heights[j])
                {
                    maxh = j;
                }
            }
            if (i!= maxh)
                {
                    swap(names[i],names[maxh]);
                    swap(heights[i],heights[maxh]);
                }
        }
        return names ;
    }
};
