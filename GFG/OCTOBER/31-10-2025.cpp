//Shortest Cycle




class Solution {
  public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Code here
    vector<vector<int>> g(V);
    for (auto& e : edges) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    int ans = INT_MAX;
    for (int src = 0; src < V; src++) {
        vector<int> dist(V, -1), parent(V, -1);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                } else if (parent[u] != v) {
                    ans = min(ans, dist[u] + dist[v] + 1);
                }
            }
        }
        if (ans == 3) break;
    }
    return ans == INT_MAX ? -1 : ans;
    }
};
