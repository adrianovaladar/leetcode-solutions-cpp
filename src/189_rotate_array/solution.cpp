class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0 || (k %= nums.size()) == 0 ) return;
        std::reverse(nums.begin(),nums.end());  
        std::reverse(nums.begin()+k,nums.end()); 
        std::reverse(nums.begin(),nums.begin()+k);  
    }
};
