#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) {
            return !std::isalnum(c);
        }), s.end());

        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        int left = 0, right = (int)s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};

int main() {
    Solution sol;
    std::string input = "A man, a plan, a canal: Panama";
    std::cout << "LeetCode solution result:" << "\n";
    std::cout << sol.isPalindrome(input) << "\n";
    return 0;
}