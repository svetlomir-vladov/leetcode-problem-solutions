#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        if (strs[0].empty()) return "";

        size_t min_len = strs[0].length();
        for (const std::string& w : strs) {
            min_len = std::min(min_len, w.length());
        }

        for (size_t i = 0; i < min_len; i++) {
            char letter = strs[0][i];
            for (const std::string& w : strs) {
                if (w[i] != letter) return strs[0].substr(0, i);
            }
        }
        return strs[0].substr(0, min_len);
    }
};
