class Solution {
public:
    int maxArea(vector<int>& height) {
        int start {};
        int end = height.size() - 1;
        int maxArea {(end - start) * std::min(height.at(start), height.at(end))};
        while(start < end) {
            if (height.at(start) < height.at(end))
                start++;
            else
                end--;
            int area {(end - start) * std::min(height.at(start), height.at(end))};
            maxArea = std::max(maxArea, area);
        }
        return maxArea;
    }
};
