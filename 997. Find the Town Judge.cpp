// Solution of LeetCode Problem 
// 997. Find the Town Judge
// Solution in CPP 


// Appraoch 2  
// Time complexity = O(n+k)


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> px(n+1) ;
        vector<int>  xp (n+1) ;
        for(vector<int>& t :trust)
        {
            px[t[0]]++; // truster 
            xp[t[1]]++; // trusted 
        }
        for(int person = 1 ;person<=n ;person++)
        {
            if(px[person] == 0 && xp[person] == n-1) return person ;
        }
        return -1 ;
    }
};



// Appraoch 1  
// Time complexity = O(n*k)

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        for(int person = 1 ;person<=n ;person++)
        {
            int px = 0 , xp = 0 ;
            for(vector<int>& t :trust)
            {
                if(t[0] == person)
                {
                    px++;
                    break ;
                }
                else if(t[1] == person)
                {
                    xp++ ;
                }
            }
            if(px == 0 && xp == n-1) return person ;
        }
        return -1 ;
    }
};
