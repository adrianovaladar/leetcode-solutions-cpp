class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        std::vector<std::string> answer;
        answer.resize((s.size() / k) + 1);
        for (int i {}; i < s.size(); i++) {
            answer[i / k] += s[i];
        }        
        int size = answer.back().size();
        if (size == 0) answer.pop_back();
        else if (size != k) {
            for (int i {size}; i < k; i++) {
                answer.back() += fill;
            }
        } 
        return answer;
    }
};
