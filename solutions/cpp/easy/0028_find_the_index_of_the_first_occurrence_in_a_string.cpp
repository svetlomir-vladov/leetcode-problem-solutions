#include <string>
#include <string_view>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.size() > haystack.size()) return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            if (std::string_view(haystack).substr(i, needle.size()) == needle) {
                return i;
            }
        }
        return -1;
    }
};
