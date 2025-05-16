#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int low = 0, high = nums.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] < target) {
                    low = mid + 1;
                }
                else if (nums[mid] > target) {
                    high = mid - 1;
                }
                else {
                    return mid;
                }
            }
            return low;
        }
    };

int main() {
    vector<int> nums = {1, 3, 5, 6};
    Solution sol;
    cout << sol.searchInsert(nums, 7) << endl;
    return 0;
}