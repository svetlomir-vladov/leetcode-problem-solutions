#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result;
        result.reserve(numRows);
        result.push_back({1});

        for (int i = 1; i < numRows; ++i) {
            const auto& prev_row = result.back();
            std::vector<int> new_row;
            new_row.reserve(i + 1);
            new_row.push_back(1);
            
            for (int j = 1; j < i; ++j) {
                new_row.push_back(prev_row[j-1] + prev_row[j]);
            }
            
            new_row.push_back(1);
            result.push_back(new_row);
        }

        return result;
    }
};