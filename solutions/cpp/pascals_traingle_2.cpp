#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> solution_2(int rowIndex) {
        std::vector<int> row{1};

        for (int i = 1; i <= rowIndex; ++i) {
            std::vector<int> next_row;
            next_row.reserve(i + 1);
            next_row.push_back(1);
            
            for (int j = 1; j < i; ++j) {
                next_row.push_back(row[j - 1] + row[j]);
            }

            next_row.push_back(1);
            row = std::move(next_row);
        }

        return row;
    }

    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }
        return row;
    }
};


int main() {
    Solution sol;
    std::vector<int> result = sol.getRow(6);

    for (const auto& i : result) {
        std::cout << i << "\n";
    }
}