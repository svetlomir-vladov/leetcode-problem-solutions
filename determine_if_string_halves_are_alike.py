class Solution(object):

    @staticmethod
    def halves_are_alike(s):
        """
        :type s: str
        :rtype: bool
        """
        def count_vowels(input_string):
            vowels_count = 0
            vowels = ['a', 'e', 'i', 'o', 'u']

            for letter in input_string:
                if letter in vowels:
                    vowels_count += 1
            return vowels_count

        s = s.lower()
        a = s[:(int(len(s)/2))]
        b = s[(int(len(s)/2)):]
        return count_vowels(a) == count_vowels(b)


if __name__ == '__main__':
    solution = Solution()
    result = solution.halves_are_alike(s="book")
    print(result)