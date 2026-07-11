class Solution {
public:
    void dfs(vector<bool>& visited,vector<list<int>>& adj,int& degreeSum,int& vertices, int u){
        visited[u] = true;
        degreeSum += adj[u].size();
        vertices++;
        for(auto& v: adj[u]){
            if(!visited[v]){
                dfs(visited, adj, degreeSum, vertices, v);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<list<int>> adj(n);
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int degreeSum;
        int vertices;
        int ans = 0;
        for(int i = 0;i < n; i++){
            if(!visited[i]){
                degreeSum = 0;
                vertices = 0;
                dfs(visited, adj, degreeSum, vertices, i);

                int edgeCount = degreeSum / 2;
                if(edgeCount == (vertices * (vertices - 1)) / 2) ans++;
            }
        }
        return ans;
    }
};