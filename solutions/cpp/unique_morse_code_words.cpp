#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        int uniqueMorseRepresentations(vector<string>& words) {
            vector<string> morse_list = {
                ".-",   // a
                "-...", // b
                "-.-.", // c
                "-..",  // d
                ".",    // e
                "..-.", // f
                "--.",  // g
                "....", // h
                "..",   // i
                ".---", // j
                "-.-",  // k
                ".-..", // l
                "--",   // m
                "-.",   // n
                "---",  // o
                ".--.", // p
                "--.-", // q
                ".-.",  // r
                "...",  // s
                "-",    // t
                "..-",  // u
                "...-", // v
                ".--",  // w
                "-..-", // x
                "-.--", // y
                "--.."  // z
            };
            unordered_set<string> unique_morse;
            
            for (string word : words) {
                string morse;

                for (char c : word) {
                    morse += morse_list[c - 'a'];
                }
                unique_morse.insert(morse);
            }

            return unique_morse.size();
        }
    };

int main() {
    vector<string> input = {"gin", "zen", "gig", "msg"};
    Solution sol;
    cout << sol.uniqueMorseRepresentations(input) << endl;
    return 0;
}