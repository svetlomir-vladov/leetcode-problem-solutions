#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int i = 0;

            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] != val) {
                    nums[i] = nums[j];
                    i++;
                }
            }
            return i;
        }
    };

int main() {
    Solution sol;
    vector<int> input = {3,2,2,3};
    sol.removeElement(input, 3);
    return 0;
}