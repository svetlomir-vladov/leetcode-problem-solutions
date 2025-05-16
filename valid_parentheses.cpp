#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
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


int main() {
    Solution sol;
    cout << sol.isValid("}") << endl;
    return 0;

}