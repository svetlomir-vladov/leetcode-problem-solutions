#include <string>

class Solution {
public:
    int maxPower(std::string s) {
        char previous_char = s[0];
        int max_power = 1;
        int count = 0;

        for (char c : s) {
            if (previous_char != c) {
                if (count > max_power) max_power = count;
                count = 0;
            }
            count += 1;
            previous_char = c;
        }
        return (max_power > count) ? max_power : count;
    }
};
