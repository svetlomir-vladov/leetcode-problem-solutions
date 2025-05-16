#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
    public:
        int balancedStringSplit(string s) {
            int result = 0 , r = 0, l = 0;
            
            for (char c : s) {
                if (c == 'R') r += 1;
                else l += 1;

                if (r == l) {
                    result += 1;
                    r = 0;
                    l = 0;
                }
            }

            return result;
        }
    };

int main() {
    string input = "RLRRLLRLRL";
    Solution sol;
    cout << sol.balancedStringSplit(input) << endl;
    return 0;
}