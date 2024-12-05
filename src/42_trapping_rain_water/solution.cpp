class Solution {
public:
    int trap(vector<int>& height) {
        int answer {};
        int left {};
        int right = height.size()-1;
        int leftMax = height[left];
        int rightMax = height[right];
        int res {};
        while (left < right) {
            if (height.at(left) < height.at(right)) {
                left++;
                leftMax = std::max(height.at(left), leftMax);
                res = leftMax - height.at(left);
            }
            else {
                right--;
                rightMax = std::max(height.at(right), rightMax);
                res = rightMax - height.at(right);
            }
            answer+= res >= 0 ? res : 0;
        }
        return answer;
    }
};
