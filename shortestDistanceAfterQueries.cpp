class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, list<int>> graph;
        for (int i = 0; i < n - 1; ++i) {
            graph[i].push_back(i + 1);
        }
        auto bfs = [&]() {
            vector<int> dist(n, -1);
            dist[0] = 0;
            queue<int> q;
            q.push(0);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[node] + 1;
                        q.push(neighbor);
                    }
                }
            }
            return dist[n - 1];
        };
        vector<int> result;
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            graph[u].push_back(v);
            result.push_back(bfs());
        }
        return result;
    }
};