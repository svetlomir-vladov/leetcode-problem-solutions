#include <vector>
#include <unordered_map>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::unordered_map<int, int> freq_map = {};

        for (int num : nums) {
            freq_map[num]++;
        }

        for (const auto& pair : freq_map) {
            if (pair.second == 1) {
                return pair.first;
            }
        }

        return -1;
    }
};