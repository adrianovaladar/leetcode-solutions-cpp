class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> stonesQueue(stones.begin(), stones.end());
        while(stonesQueue.size() > 1) {
            int top1 = stonesQueue.top();
            stonesQueue.pop();
            int top2 = stonesQueue.top();
            stonesQueue.pop();
            if (top1 != top2)
                stonesQueue.push(abs(top1-top2));
        }
        return stonesQueue.size() == 0 ? 0 : stonesQueue.top();
    }
};
