class Solution {
public:
    void dfs(unordered_map<int, vector<pair<int, int>>>& adj, vector<bool>& visited, int& result, int s){
        visited[s] = true;

        for(auto& edge: adj[s]){
            int v = edge.first;
            int d = edge.second;

            result = min(result, d);
            if(!visited[v]){
                dfs(adj, visited, result, v);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto road: roads){
            int u = road[0];
            int v = road[1];
            int d = road[2];

            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        vector<bool> visited(n, false);
        int result = INT_MAX;
        dfs(adj, visited, result, 1);
        return result; 
    }
};