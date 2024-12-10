class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> pair;
        for (int i {}; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        std::sort(pair.rbegin(), pair.rend());
        std::stack<double> stk;
        for (auto &element: pair) {
            stk.push(static_cast<double>((target - element.first)) / element.second);
            if (stk.size() >= 2 ) {
                double top = stk.top();
                stk.pop();
                if (top > stk.top())
                    stk.push(top);
            }
        }
        return stk.size();
    }
};
