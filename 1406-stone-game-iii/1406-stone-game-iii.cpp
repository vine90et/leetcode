class Solution {
public:
    int solve(vector<int>& stoneValue, int n, int i, vector<int> &dp){
        if(i >= n){
            return 0;
        }
        if(dp[i] != INT_MIN) return dp[i];
        int result = INT_MIN;
        result = max(result, stoneValue[i] - solve(stoneValue, n ,i+1, dp));
        if(i + 1 < n)
            result = max(result, stoneValue[i] + stoneValue[i+1] - solve(stoneValue, n ,i+2, dp));
        if(i + 2 < n)
            result = max(result, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(stoneValue, n ,i+3, dp));

        return dp[i] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);
        int diff = solve(stoneValue, n, 0, dp);

        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";

        return "Tie";
    }
};