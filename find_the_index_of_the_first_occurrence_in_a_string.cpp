#include <iostream>
#include <string>
#include <string_view>
using namespace std;

class Solution {
    public:
        int strStr(string haystack, string needle) {
            if (needle.size() > haystack.size()) return -1;
            for (int i = 0; i <= haystack.size() - needle.size(); i++) {
                if (string_view(haystack).substr(i, needle.size()) == needle) {
                    return i;
                }
            }
            return -1;
        }
    };

int main() {
    Solution sol;
    string needle = "sad";
    string haystack = "sadbutsad";
    cout << sol.strStr(haystack, needle) << endl;
    return 0;
}