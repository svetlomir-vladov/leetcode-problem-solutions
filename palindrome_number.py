class Solution(object):

    @staticmethod
    def is_palindrome(x):
        """
        :type x: int
        :rtype: bool
        """
        x = str(x)
        reversed_num = ''
        for i in range(len(x) - 1, -1, -1):
            reversed_num += x[i]
        return x == reversed_num


if __name__ == '__main__':
    solution = Solution()
    result = solution.is_palindrome(x=222)
    print(result)