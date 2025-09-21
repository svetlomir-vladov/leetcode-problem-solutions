#include <string>
#include <cctype>

class Solution {
private:
    std::string create_permutation(const std::string& letters, const std::string& numbers, int difference) {
        std::string result;
        int number_iterator = 0;
        int letter_iterator = 0;

        if (difference == 1) {
            result += letters[letter_iterator++];
            while (number_iterator < numbers.size() && letter_iterator < letters.size()) {
                result += numbers[number_iterator++];
                result += letters[letter_iterator++];
            }
        }
        else if (difference == -1) {
            result += numbers[number_iterator++];
            while (number_iterator < numbers.size() && letter_iterator < letters.size()) {
                result += letters[letter_iterator++];
                result += numbers[number_iterator++];
            }
        } 
        else {
            while (number_iterator < numbers.size() && letter_iterator < letters.size()) {
                result += letters[letter_iterator++];
                result += numbers[number_iterator++];
            }
        }
        return result;
    }
public:
    std::string reformat(std::string s) {
        std::string numbers, letters;

        for (char c : s) {
            if (isdigit(c)) numbers += c;
            else if (isalpha(c)) letters += c;
        }

        int difference = letters.size() - numbers.size();
        if (abs(difference) > 1) return "";

        return create_permutation(letters, numbers, difference);
    }
};
