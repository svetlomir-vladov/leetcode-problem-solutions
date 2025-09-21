#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        int result = 0;

        std::unordered_map<char, int> roman_int_map {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for (size_t i = 0; i < s.size(); i++) {
            char roman_numeral = s[i];
            int value = roman_int_map[roman_numeral];

            if (value == 1 || value == 10 || value == 100) {
                // Doesn't break when trying to access an out-of-bounds variable
                char next_roman_numeral = roman_numeral = s[i+1];
                int next_value = roman_int_map[next_roman_numeral];

                if (next_value > value) {
                    result -= value;
                    continue;
                }
            }
            result += value;
        }

        return result;
    }
};
