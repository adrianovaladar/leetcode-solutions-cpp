class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i {}; i < n; i++) {
            nums1.pop_back();
        }
        for (const auto &num: nums2) {
            nums1.emplace_back(num);
        }
        sort(nums1.begin(), nums1.end());
    }
};
