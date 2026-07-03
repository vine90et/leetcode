class Solution {
public:
    bool dijk(unordered_map<int, vector<pair<int, int>>>& adj, int mid, int n, long long k) {
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& [v, w] : adj[u]) {
                if (w < mid) continue;

                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        int n = online.size(); 
        
        int l = 0, r = 0; 

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int c = edge[2];

            if (!online[u] || !online[v]) continue;

            adj[u].push_back({v, c});

            r = max(r, c);
        }

        int ans = -1; 
        
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (dijk(adj, mid, n, k)) {
                ans = mid;     
                l = mid + 1;   
            } else {
                r = mid - 1;   
            }
        }
        
        return ans;
    }
};