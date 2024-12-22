class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int,int>> stk;
        int index {};
        int maxArea {};
        for (const auto &height: heights) {
            int start = index;
            while (!stk.empty() && stk.top().second > height) {
                int previousIndex = stk.top().first;
                int previousHeight = stk.top().second;
                stk.pop();
                std::cout << previousHeight << std::endl;
                maxArea = std::max(maxArea, (index - previousIndex) * previousHeight);
                start = previousIndex;
            }
            stk.push({start, height});
            index++;
        }
        while(!stk.empty()) {
            int index = stk.top().first;
            int height = stk.top().second;
            maxArea = max(maxArea, height * (static_cast<int>(heights.size()) - index));
            stk.pop();
        }
        return maxArea;
    }
};
