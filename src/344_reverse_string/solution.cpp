class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> stack;
        for(const auto &c: s) {
            stack.push(c);
        }
        s.clear();
        while(!stack.empty()) {
            s.emplace_back(stack.top());
            stack.pop();
        }
    }
};
