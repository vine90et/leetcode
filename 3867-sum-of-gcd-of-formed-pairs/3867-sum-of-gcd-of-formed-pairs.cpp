class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int m = INT_MIN;
        vector<int> Prefixgcd(n);

        for(int i = 0;i < n; i++){
            m = max(nums[i], m);
            Prefixgcd[i] = gcd(m, nums[i]);
        }

        sort(Prefixgcd.begin(), Prefixgcd.end());
        int i = 0, j = n-1;
        long long ans = 0;
        while(i < j){
            ans += gcd(Prefixgcd[i], Prefixgcd[j]);
            i++;j--;
        }
        return ans;
    }
};