class Solution {
public:
    long long sumAndMultiply(int n) {
        string str = to_string(n);
        if(n == 0 ) return n;
        string ans;
        long long sum = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] - '0' != 0){
                ans += str[i];
                sum += str[i] - '0';
            }
        }
        long long res = stoi(ans) * sum;
        return res;
    }
};