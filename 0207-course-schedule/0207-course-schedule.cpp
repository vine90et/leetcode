class Solution {
public:
    bool isCycleDFS(vector<bool>& visited, vector<list<int>>& adj, int u,vector<bool>& reveBack){
        visited[u] = true;
        reveBack[u] = true;

        for(auto& ngbr: adj[u]){
            if(!visited[ngbr]) {
                if(isCycleDFS(visited, adj, ngbr, reveBack)){
                    return true;
                }
            }else if(reveBack[ngbr]){
                return true;
            }
        }
        reveBack[u] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<list<int>> adj(n);

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        vector<bool> reveBack(n, false);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(isCycleDFS(visited, adj, i, reveBack)){
                    return false;
                }
            }
        }
        return true;
    }
};