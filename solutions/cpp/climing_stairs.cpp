#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        
        int prev_1 = 1, prev_2 = 1;

        for (int i = 2; i < n; i++) {
            int current = prev_1 + prev_2;
            prev_1 = prev_2;
            prev_2 = current;
        }
        return prev_1 + prev_2;
    }
};