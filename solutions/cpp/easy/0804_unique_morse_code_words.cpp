#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    int uniqueMorseRepresentations(std::vector<std::string>& words) {
        std::vector<std::string> morse_list = {
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
        std::unordered_set<std::string> unique_morse;
        
        for (std::string word : words) {
            std::string morse;

            for (char c : word) {
                morse += morse_list[c - 'a'];
            }
            unique_morse.insert(morse);
        }

        return unique_morse.size();
    }
};
