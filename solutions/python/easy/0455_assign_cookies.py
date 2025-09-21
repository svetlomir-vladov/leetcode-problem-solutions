class Solution(object):
    def find_content_children(g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        children_sorted = sorted(g)
        cookies_sorted = sorted(s)
        children_pointer = 0
        cookies_pointer = 0
        content_children = 0

        while children_pointer < len(children_sorted) and cookies_pointer < len(cookies_sorted):
            if children_sorted[children_pointer] <= cookies_sorted[cookies_pointer]:
                content_children += 1
                children_pointer += 1
            cookies_pointer += 1
        return content_children
