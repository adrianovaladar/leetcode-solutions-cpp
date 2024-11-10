class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer;
        bool begin = false;
        for (int i {}; i < nums.size(); i++) {
            if (nums.at(i) == target && !begin) {
                answer.emplace_back(i);
                begin = true;
            }
            if (nums.at(i) != target && begin) {
                answer.emplace_back(i-1);
                break;
            }
        }
        if (begin == false) {
            answer.emplace_back(-1);
            answer.emplace_back(-1);
        }
        else if(answer.size() == 1)
            answer.emplace_back(nums.size() - 1);

        return answer;
    }
};
