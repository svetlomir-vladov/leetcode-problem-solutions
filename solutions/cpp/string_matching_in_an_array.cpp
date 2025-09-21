#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    std::vector<std::string> stringMatching(std::vector<std::string>& words) {
        std::unordered_set<std::string> words_set(words.begin(), words.end());
        std::unordered_set<std::string> substrings_found;

        for (const std::string& main_word : words_set) {
            for (const std::string& substring_word : words_set) {
                if (substring_word.length() >= main_word.length()) continue;
                size_t pos = main_word.find(substring_word);
                if (pos != std::string::npos) {
                    substrings_found.insert(substring_word);
                }
            }
        }
        return std::vector<std::string>(substrings_found.begin(), substrings_found.end());
    }
};
