class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white {};
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') white++;
        }
        int answer = white;
        for (int right{k}; right < blocks.size(); right++) {
            if (blocks[right] == 'W') white++;
            if (right - k >= 0 && blocks[right - k] == 'W') white--;
            answer = std::min(white, answer);
        }
        return answer;
    }
};
