#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int end = -1;
        int i = s.size() - 1;

        while (-1 < i) {
            while (end == -1) {
                if (s[i] != ' ') {
                    end = i;
                    break;
                }
                i--;
            }

            if (s[i] == ' ') break;
            i--;
        }
        return end - i;
    }
};