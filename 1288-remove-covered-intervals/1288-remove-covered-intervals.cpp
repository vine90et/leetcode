class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        auto lambda = [](vector<int> vec1, vector<int> vec2){
            if(vec1[0] == vec2[0]){
                return vec1[1] > vec2[1];
            }
            return vec1[0] < vec2[0];
        };
        sort(intervals.begin(), intervals.end(), lambda);


        stack<pair<int,int>> res;
        res.push({intervals[0][0], intervals[0][1]});
        for(int i = 1;i < n; i++){
            int st = intervals[i][0];
            int end = intervals[i][1];

            if(st >= res.top().first && end <= res.top().second){
                continue;
            }

            res.push({st, end});
        }
        return res.size();
    }
};