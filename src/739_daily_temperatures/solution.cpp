class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<pair<int, int>> stk; 
        int index {};
        for (const auto &temperature: temperatures) {
            while(1) {
                if (stk.empty()) {
                    stk.push(std::make_pair(temperature, index));
                    break;
                }
                auto value = stk.top();
                if (value.first < temperature) {
                    answer.at(value.second) = index - value.second;
                    stk.pop();
                }
                else {
                    stk.push(std::make_pair(temperature, index));
                    break;
                }
            }
        index++;
        }
        return answer;
    }
};
