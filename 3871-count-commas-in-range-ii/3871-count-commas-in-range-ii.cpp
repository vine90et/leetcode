class Solution {
public:
    typedef long long ll;
    long long countCommas(long long n) {
        ll ans = 0;
        ll threshold = 1000;

        while(threshold <= n){
            ans += (n - threshold +1);
            threshold *= 1000;
        }
        return ans;
    }
};