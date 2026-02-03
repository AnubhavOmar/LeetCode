// Solution of LeetCode 
// 823. Binary Trees With Factors
// Solution of Cpp 

// Appraoch - 1 (Optimized with Explanation)


class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7; // this is for large values 
        sort(arr.begin(),arr.end());
        unordered_map<int,long long>ump;
        int n = arr.size() ;
        for(int i = 0 ;i<n;i++)
        {
            ump[arr[i]]=1;
        }

        for(int i = 0 ; i<n ;i++)
        {
            for(int j = 0 ; j<i;j++) // or we can alos may be do this .
            // i.e for (int j = i ; j>=0;j--) 
            {
                if(arr[i] % arr[j] == 0)
                {
                    if(ump.find( (arr[i]/arr[j] )) !=ump.end() )
                    // in this loop we are calculating that if the tree is formed then how many will be the tree including the internal nodes the tree will form 
                    {
                        auto it_m = ump.find(arr[j]) ;
                        long long  m = it_m->second;
                        auto it_n = ump.find(arr[i]/arr[j]);
                        long long  n = it_n->second; 

                        ump[arr[i]] = (ump[arr[i]] + m * n) % MOD;
                    }
                }
            }
        }

        int count = 0 ;
        for(auto a : ump)
        {
            count = (count + a.second) % MOD;
        }
        return count;
    }
};



// main things 
/* 

sort the array 
map insert all arr elements 
process elements of array 

// main thing or formula i.e 

(arr[i] > arr[j]) we will not use this conditon because we already sorted the array  

if( (arr[i] % arr[j] == 0) )
{
here arr[i] is parent node and arr[j] will be childeren which divide the parent node 

now when we find that a tree exists which follow the question condtion then 
store that in map value 
}

at last we add the map values to get answer 



*/