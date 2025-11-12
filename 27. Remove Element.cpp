//Solution in CPP 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>vec ;
        for(int i: nums){
            if(i!=val){
                vec.push_back(i);
            }
        }
        nums.clear();
        for(int i : vec){
            nums.push_back(i);
        }
        return nums.size() ;
    }
};