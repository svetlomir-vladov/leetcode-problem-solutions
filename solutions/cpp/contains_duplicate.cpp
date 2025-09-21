#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;

        for (int num : nums) {
            if (!seen.insert(num).second) {
                return true;
            }
        }
        return false;
    }
};
