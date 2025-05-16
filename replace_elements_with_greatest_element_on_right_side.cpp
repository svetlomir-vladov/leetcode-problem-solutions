#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> replaceElements(vector<int>& arr) {
            int bn = -1;
            for (int i = arr.size() - 1; i > -1; i--) {
                int current = arr[i];
                arr[i] = bn;
                bn = max(bn, current);
            }
            return arr;
        }
    };

int main() {
    Solution sol;
    vector<int> input = {17,18,5,4,6,1};
    vector<int> result = sol.replaceElements(input);
    return 0;
}