class Solution(object):

    @staticmethod
    def largest_good_integer(num: str):
        """
        :type num: str
        :rtype: str
        """

        num += " "
        current_matches = 0
        temp_digit = None
        results = []

        for current_digit in num:

            if current_digit == temp_digit:
                current_matches += 1
                continue

            elif temp_digit is not None:
                if current_matches >= 3:
                    results.append(str(temp_digit) * 3)
                current_matches = 1
                temp_digit = current_digit

            elif temp_digit is None:
                current_matches = 1
                temp_digit = current_digit

        if results:
            return max(results)
        return ""



if __name__ == '__main__':
    solution = Solution()
    result = solution.largest_good_integer("6777133339")
    print(result)