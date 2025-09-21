#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int i = digits.size() - 1;

        while (i > -1 && digits[i] == 9) {
            digits[i] = 0;
            i--;
        }

        if (i < 0) {
            digits[0] = 1;
            digits.push_back(0);
        } else {
            ++digits[i];
        }

        return digits;
    }   
};
