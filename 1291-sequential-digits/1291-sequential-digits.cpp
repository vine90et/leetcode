class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num = "123456789";
        int lowLen = to_string(low).size();
        int highLen = to_string(high).size();

        vector<int> ans;
        
        for(int len = lowLen; len <= highLen; len++){
            for(int start = 0; start+len <= 9; start++ ){
                int val = stoi(num.substr(start, len));

                if(val >= low && val <= high ){
                    ans.push_back(val);
                }
            }
        }
        return ans;
    }
};