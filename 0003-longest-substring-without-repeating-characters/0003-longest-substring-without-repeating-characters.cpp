class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        unordered_set<int> st;
        int maxCount = 0;

        for(int right = 0;right < n && left <= right; right++){
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxCount = max(maxCount, right-left+1);
        }
        return maxCount;
    }
};