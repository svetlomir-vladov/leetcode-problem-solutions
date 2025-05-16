#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        bool isGood(vector<int>& nums) {
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


int main() {
    Solution sol;
    vector<int> nums = {2,2,2};
    cout << sol.isGood(nums) << endl;
    return 0;
}