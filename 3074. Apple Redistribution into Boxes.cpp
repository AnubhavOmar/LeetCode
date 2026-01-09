// Solution of LeetCode Problem 
// 3074. Apple Redistribution into Boxes 
// Solution in CPP 

// Approach - 1 

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int total_apple = 0;
        for(int i = 0 ; i<apple.size(); i++)
        {
            total_apple += apple[i];
        }
        int count = 0 ;
        int i = capacity.size()-1;
        while(total_apple>0 && i >=0)
        {
            count++;
            total_apple -= capacity[i--];
        }
        return count ;
    }
};