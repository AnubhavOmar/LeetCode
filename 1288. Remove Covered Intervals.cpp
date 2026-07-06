// Solution of LeetCode POTD
// 1288. Remove Covered Intervals
// Solution in CPP 

// Approach - 1 (Sorting Using a Comparator and checking every interval with its previous interval)

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b)
        {
        if (a[0] == b[0])
            return a[1] > b[1];   // same start → bigger end first

        return a[0] < b[0];       // smaller start first
        }
        );
        
        int n = intervals.size() - 1; 
        int count = 0 ; 

        for(int i = n ; i >= 0 ;i--)
        {
            for(int j = i - 1; j >= 0 ; j--)
            {
                if((intervals[j][0] <= intervals[i][0])&&(intervals[j][1] >= intervals[i][1]))
                {
                    count++;
                    break;
                }
            }
        }
        return intervals.size() - count;
    }
};