class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int first = INT_MAX, second = INT_MAX;
        for(auto& num: nums){
            if(num < first) first = num;
            else if(num > first && num < second) second = num;
            else if(first != INT_MAX && second != INT_MAX && num > first && num > second) return true; 
        }
        return false;
    }
};