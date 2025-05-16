class Solution(object):

    @staticmethod
    def kth_grammar(n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """

        if n == 1:
            return 0
        half = 1 << (n - 2)
        if k <= half:
            return Solution.kth_grammar(n - 1, k)
        else:
            return 1 - Solution.kth_grammar(n - 1, k - half)


if __name__ == '__main__':
    solution = Solution()
    result = solution.kth_grammar(n=30, k=1)
    print(result)