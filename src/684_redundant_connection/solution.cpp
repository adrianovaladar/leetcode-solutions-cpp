class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        std::vector<int> inNode(edges.size() + 1);
        std::vector<std::vector<int>> neighbors(edges.size() + 1);
        for (const auto & edge: edges) {
            neighbors.at(edge.at(0)).emplace_back(edge.at(1));
            neighbors.at(edge.at(1)).emplace_back(edge.at(0));
            inNode.at(edge.at(0))++;
            inNode.at(edge.at(1))++;
        }
        std::queue<int> q;
        for (int i {}; i < edges.size() + 1; i++) {
            if (inNode.at(i) == 1) q.push(i);        
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (const auto &neighbor: neighbors.at(node)) {
                inNode.at(neighbor)--;
                if (inNode.at(neighbor) == 1) q.push(neighbor);        
            }
        }
        for (int i = edges.size() - 1; i >= 0; i--) {
            int u = edges.at(i).at(0);
            int v = edges.at(i).at(1);
            if (inNode[u] == 2 && inNode[v] == 2) return {u, v};
        }
        return {};
    }
};
