class Solution {
    void bfs(int node, std::vector<std::vector<int>> neighbors, std::unordered_set<int> &visited) {
        std::queue<int> q;
        q.push(node);
        while(!q.empty()) {
            int n = q.front();
            visited.insert(n);
            q.pop();
            for (const auto &neighbor: neighbors.at(n)) {
                if (visited.find(neighbor) != visited.end()) continue;
                q.push(neighbor);
            }
        }

    }
public: 
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> neighbors(n);
        for (const auto &edge: edges) {
            neighbors.at(edge.at(0)).emplace_back(edge.at(1));
            neighbors.at(edge.at(1)).emplace_back(edge.at(0));
        }
        std::unordered_set<int> visited;
        int answer {};
        for(int node {} ; node < n ; node++) {
            if (visited.find(node) == visited.end()) { 
                bfs(node, neighbors, visited);
                answer++;
            }
        }
        return answer;
    }
};
