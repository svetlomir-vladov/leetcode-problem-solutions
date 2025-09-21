#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
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
