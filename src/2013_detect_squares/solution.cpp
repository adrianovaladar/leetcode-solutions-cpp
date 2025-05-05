class DetectSquares {
    std::unordered_map<int, std::unordered_map<int, int>> mp;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[point.at(0)][point.at(1)]++;
    }
    
    int count(vector<int> point) {
        int x1 = point.at(0);
        int y1 = point.at(1);
        int answer{};
        for (const auto &[y2, count]: mp[x1]) {
            int side = abs(y1 - y2);
            if (side == 0) continue; 
            int x3 = x1 - side;
            int x4 = x1 + side;
            answer += count * mp[x3][y2] * mp[x3][y1];
            answer += count * mp[x4][y2] * mp[x4][y1];
        }
        return answer;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
