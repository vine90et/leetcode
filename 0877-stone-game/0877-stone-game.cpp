class Solution {
public:
    int t[501][501];
    int solve(vector<int>& piles, int i, int j){
        if( i > j ) {
            return 0;
        }

        if(i == j) {
            return piles[i];
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int take_i = piles[i] + min(solve(piles, i+2, j), solve(piles, i+1, j-1));
        int take_j = piles[j] + min(solve(piles, i, j-2), solve(piles, i+1, j-1));

        return t[i][j] = max(take_i, take_j); 
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        int sum = 0;
        for(int pile: piles){
            sum += pile;
        }

        memset(t, -1, sizeof(t));
        int alice = solve(piles, 0, n-1);
        int bob = sum - alice;

        return alice > bob;
    }
};