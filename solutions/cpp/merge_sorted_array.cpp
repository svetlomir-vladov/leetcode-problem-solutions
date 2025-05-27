#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m + n - 1;
            int j = m - 1;
            int k = n - 1;

            while (k >= 0) {
                if (j > -1 && nums1[j] > nums2[k]) {
                    nums1[i--] = nums1[j--];
                } else {
                    nums1[i--] = nums2[k--];
                }
            }
        }
    };

int main() {
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    int m = 0;
    int n = 1;
    Solution sol;
    sol.merge(nums1, m , nums2, n);
    return 0;
}