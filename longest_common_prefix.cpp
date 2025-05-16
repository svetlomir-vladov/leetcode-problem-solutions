#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.empty()) return "";
            if (strs[0].empty()) return "";
    
            size_t min_len = strs[0].length();
            for (const string& w : strs) {
                min_len = min(min_len, w.length());
            }
    
            for (size_t i = 0; i < min_len; i++) {
                char letter = strs[0][i];
                for (const string& w : strs) {
                    if (w[i] != letter) return strs[0].substr(0, i);
                }
            }
            return strs[0].substr(0, min_len);
        }
    };

int main() {
    Solution sol;
    vector<string> input = {"a"};
    cout << sol.longestCommonPrefix(input) << endl;
    return 0;
}