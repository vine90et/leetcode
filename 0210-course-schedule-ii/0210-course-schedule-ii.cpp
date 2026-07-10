class Solution {
public:
    bool checkCycle(vector<list<int>>& adj, vector<bool>& visited, vector<bool>& recPath, int s){
        visited[s] = true;
        recPath[s] = true;

        for(auto& v: adj[s]){

            if(!visited[v]){

                if(checkCycle(adj, visited, recPath, v)){
                    return true;
                }

            }else if(recPath[v]){
                return true;
            }

        }

        recPath[s] = false;
        return false;
    }

    void dfs(vector<list<int>>& adj, stack<int> &st, vector<bool> &visited, int u){
        visited[u] = true;
        for(auto& v: adj[u]){
            if(!visited[v]){
                dfs(adj, st, visited, v);
            }
        }
        st.push(u);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<list<int>> adj(n);

        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        vector<bool> recPath(n, false);
        for(int i = 0;i < n; i++){
            if(!visited[i]){
                if(checkCycle(adj, visited, recPath, i)) 
                    return{};
            }
        }

        vector<int> ans;
        stack<int> st;
        visited.assign(n, false);
        for(int i = 0;i < n; i++){
            if(!visited[i]){
                dfs(adj, st, visited, i);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};