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

int main () {
    Solution sol;
    std::vector<int> input{0,4,5,0,3,6};
    std::cout << sol.containsDuplicate(input) << "\n";
    return 0;
}