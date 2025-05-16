#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> words_set(words.begin(), words.end());
        unordered_set<string> substrings_found;

        for (const string& main_word : words_set) {
            for (const string& substring_word : words_set) {
                if (substring_word.length() >= main_word.length()) continue;
                size_t pos = main_word.find(substring_word);
                if (pos != string::npos) {
                    substrings_found.insert(substring_word);
                }
            }
        }
        return vector<string>(substrings_found.begin(), substrings_found.end());
    }
};

int main() {
    vector<string> input = {"awzzjcv","zzjc","zjc"};
    Solution sol;
    vector<string> result = sol.stringMatching(input);
    for (const string& s : result) {
        cout << s << endl;
    }
    return 0;
}