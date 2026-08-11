class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st;
        for(int num: nums){
            st.insert(num);
        }
        int n = nums.size();
        int sum = nums[0];
        for(int i = 1;i < n;i++){
            if(nums[i-1]+1 == nums[i] ){
                sum += nums[i];
            }else{
                break;
            }
        }

        while(st.find(sum) != st.end()){
            sum++;
        }
        return sum;
    }
};