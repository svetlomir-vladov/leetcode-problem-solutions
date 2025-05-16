#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int i = digits.size() - 1;

            while (i > -1 && digits[i] == 9) {
                digits[i] = 0;
                i--;
            }

            if (i < 0) {
                digits[0] = 1;
                digits.push_back(0);
            } else {
                ++digits[i];
            }

            return digits;
        }   
    };

int main() {
    Solution sol;
    vector<int> input = {9};
    vector<int> result = sol.plusOne(input);
    
    for (int d : result) {
        cout << d;
    }
    return 0;
}