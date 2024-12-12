class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start {1};
        int end = *max_element(piles.begin(), piles.end());
        int answer {end};
        while (start <= end) {
            int middle = start + (end - start) / 2;            
            long long totalTime {};
            for (int p : piles) {
                totalTime += ceil(static_cast<double>(p) / middle);
            }
            if (totalTime <= h) {
                answer = middle;
                end = middle - 1;
            }
            else
                start = middle + 1;
        }
        return answer;
    }
};
