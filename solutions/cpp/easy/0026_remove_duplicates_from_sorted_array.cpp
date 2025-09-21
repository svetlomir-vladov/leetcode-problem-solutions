#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i = 0;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
