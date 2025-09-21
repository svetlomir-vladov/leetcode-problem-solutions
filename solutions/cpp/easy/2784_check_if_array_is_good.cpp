#include <vector>
#include <algorithm>

class Solution {
public:
    bool isGood(std::vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());
        if (max_num + 1 != nums.size()) return false;
        sort(nums.begin(), nums.end());

        int current = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != current) {
                if (i != nums.size() - 1) return false;
            }
            current++;
        }
        return true;
    }
};
