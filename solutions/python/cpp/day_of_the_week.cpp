#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        std::string dayOfTheWeek(int day, int month, int year) {
            const vector<std::string> weekdays = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
            // Adjust January and February to be months 13 and 14 of the previous year
            if (month < 3) {
                month += 12;
                year -= 1;
            }
    
            // Extract the last two digits (k) and the century (j)
            int k = year % 100;
            int j = year / 100;
    
            // Apply Sakamoto's formula
            int h = (day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    
            // Adjust the index to match standard weekday order (0=Saturday, 1=Sunday, etc.)
            return weekdays[(h + 6) % 7];
        }
    };

int main() {
    Solution sol;
    cout << sol.dayOfTheWeek(31, 8, 2019) << endl;
    return 0;
}