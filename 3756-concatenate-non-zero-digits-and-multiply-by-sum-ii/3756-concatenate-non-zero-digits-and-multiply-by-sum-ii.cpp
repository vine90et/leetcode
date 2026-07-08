#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int M = 1e9+7;
    typedef long long ll;
    
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> nonZeroCount(n, 0);
        vector<ll> numberUpto(n, 0);
        vector<ll> sumUpto(n, 0);
        vector<ll> Pow10(n + 1, 0); 

        Pow10[0] = 1;
        for(int i = 1; i <= n; i++){
            Pow10[i] = (Pow10[i-1] * 10) % M; 
        }
        
        numberUpto[0] = s[0] - '0';
        for(int i = 1; i < n; i++){
            int digit = s[i] - '0';
            if(digit != 0){
                numberUpto[i] = ((numberUpto[i-1] * 10) + digit) % M;
            } else {
                numberUpto[i] = numberUpto[i-1];
            }
        }

        nonZeroCount[0] = (s[0] - '0' == 0) ? 0 : 1;
        for(int i = 1; i < n; i++){
            nonZeroCount[i] = nonZeroCount[i-1] + ((s[i] - '0' == 0) ? 0 : 1);
        }

        sumUpto[0] = s[0] - '0';
        for(int i = 1; i < n; i++){
            int digit = s[i] - '0';
            sumUpto[i] = sumUpto[i-1] + digit; 
        }

        int m = queries.size();
        vector<int> result(m, 0);
        for(int i = 0; i < m; i++){
            int li = queries[i][0];
            int ri = queries[i][1];

            ll sum = sumUpto[ri] - ((li != 0) ? sumUpto[li-1] : 0);

            ll numBefore = (li != 0) ? numberUpto[li-1] : 0;
            int k = nonZeroCount[ri] - ((li == 0) ? 0 : nonZeroCount[li-1]);
            
            ll num = (numberUpto[ri] - (numBefore * Pow10[k]) % M + M) % M;

            result[i] = ((num % M) * (sum % M)) % M;
        }
        return result;
    }
};
