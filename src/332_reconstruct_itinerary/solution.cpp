class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        sort(tickets.rbegin(), tickets.rend());
        for (auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        std:vector<std::string> answer;
        std::stack<std::string> stk;
        stk.push("JFK");
        while (!stk.empty()) {
            std::string current = stk.top();
            if (adj[current].empty()) {
                answer.emplace_back(current);
                stk.pop();
            }
            else {
                std::string next = adj[current].back();
                adj[current].pop_back();
                stk.push(next);
            }
        }
        std::reverse(answer.begin(), answer.end());
        return answer;
    }
};
