def isBadVersion(version):
    if version >= 1:
        return True
    return False


class Solution(object):
    def first_bad_version(n):
        """
        :type n: int
        :rtype: int
        """
        low, high = 1, n
        while high > low:
            mid = (low + high) // 2
            if isBadVersion(mid):
                high = mid - 1
            else:
                low = mid + 1
        return low
