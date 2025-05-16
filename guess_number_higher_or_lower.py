def guess(answer):
    number = 1
    if answer == number:
        return 0
    elif answer < number:
        return 1
    else:
        return -1


class Solution(object):

    @staticmethod
    def first_bad_version(n):
        """
        :type n: int
        :rtype: int
        """
        low = 1
        high = n
        while high >= low:
            mid = (low + high) // 2
            guess_a = guess(mid)

            if guess_a == 0:
                return mid

            elif guess_a == -1:
                high = mid - 1
            else:
                low = mid + 1

if __name__ == '__main__':
    solution = Solution()
    result = solution.first_bad_version(n=1)
    print(result)