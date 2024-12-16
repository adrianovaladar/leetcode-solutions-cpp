class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk;
        for (const auto &element: tokens) {
            int num1;
            int num2;
            if (element == "+") {
                num2 = stk.top();
                stk.pop();
                num1 = stk.top();
                stk.pop();
                stk.push(num1+num2);                
            }
            else if (element == "-") {
                num2 = stk.top();
                stk.pop();
                num1 = stk.top();
                stk.pop();
                stk.push(num1 - num2);
            }
            else if (element == "*") {
                num2 = stk.top();
                stk.pop();
                num1 = stk.top();
                stk.pop();
                stk.push(num1 * num2);
            }
            else if (element == "/") {
                num2 = stk.top();
                stk.pop();
                num1 = stk.top();
                stk.pop();
                stk.push(num1 / num2);
            }
            else
                stk.push(stoi(element));
        }
        return stk.top();
    }
};
