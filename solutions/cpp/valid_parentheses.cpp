#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        for (const char& c : s) {
            if (c == '(') st.push(')');
            else if (c == '[') st.push(']');
            else if (c == '{') st.push('}');
            else {
                if (st.empty() || c != st.top()) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
