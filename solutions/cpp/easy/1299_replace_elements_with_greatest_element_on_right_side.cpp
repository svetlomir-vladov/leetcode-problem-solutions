#include <vector>

class Solution {
public:
    std::vector<int> replaceElements(std::vector<int>& arr) {
        int bn = -1;
        for (int i = arr.size() - 1; i > -1; i--) {
            int current = arr[i];
            arr[i] = bn;
            bn = std::max(bn, current);
        }
        return arr;
    }
};
