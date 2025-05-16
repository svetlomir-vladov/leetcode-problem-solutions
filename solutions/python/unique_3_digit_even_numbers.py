class Solution(object):

    @staticmethod
    def total_numbers(digits):
        """
        :type digits: List[int]
        :rtype: int
        """
        evens = [digit for digit in digits if digit % 2 == 0]
        combinations_list = []
        def find_combinations(even):
            temp_digits = list(digits)
            temp_digits.remove(even)

            for i, digit_1 in enumerate(temp_digits):
                for k, digit_2 in enumerate(temp_digits):
                    if i == k or digit_1 == 0:
                        continue

                    combination = str(digit_1) + str(digit_2) + str(even)
                    if combination not in combinations_list:
                        combinations_list.append(combination)

        for even in evens:
            find_combinations(even)
        return len(combinations_list)


if __name__ == '__main__':
    solution = Solution()
    result = solution.total_numbers(digits=[6,6,6])
    print(result)
