#include <vector>
#include <unordered_map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> freq_map;
        int majority_threshold = nums.size() / 2;

        for (int num : nums) {
            if (++freq_map[num] > majority_threshold) {
                return num;
            }
        }
        return -1;
    }
};
