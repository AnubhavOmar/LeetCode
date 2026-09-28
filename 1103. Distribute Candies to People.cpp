// Solution of LeetCode POTD  
// 1103. Distribute Candies to People
// Solution in CPP 

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> vec(num_people , 0) ;
        int n = vec.size() ;
        int repeat = 0 ;
        int given_candy = 0 ;

        while(true)
        {
            for(int i = 0 ; i < n ; i++)
            {
                if(given_candy > candies)
                {
                    return vec;
                }
                int current_candy = (repeat * num_people) + i + 1;
                if(given_candy + current_candy <= candies)
                {
                    vec[i] +=  current_candy ;
                    given_candy += current_candy ;
                }
                else
                {
                    vec[i] += candies - given_candy ;
                    given_candy += current_candy ;
                }
                
            }
            repeat++ ;
            if(given_candy > candies)
            {
                return vec;
            }
        }
        return vec;
    }
};