// Solution of LeetCode problem 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int h = 0 ,width = 0,area = -1 ;
        int i =0 , j =height.size()-1; 
        while(i<j){
            h = min (height[i],height[j]);
            width = j-i ; 
            area = max (area , (h *width)) ;
            if(height[i]>height[j]){
                j--;
            }
            else i++ ;
        }
        return area ;
    }
};