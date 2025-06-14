class Solution {
public:
    int minMaxDifference(int num) {
        std::string text = std::to_string(num);
        std::string copy = text;
        int position = text.find_first_not_of('9');
        if (position != string::npos) {
            char a = text[position];
            replace(text.begin(), text.end(), a, '9');
        }
        int maximum = stoi(text);
        char b = copy[0];
        std::replace(copy.begin(), copy.end(), b, '0');
        int minimum = stoi(copy);
        return maximum - minimum;
    }
};
