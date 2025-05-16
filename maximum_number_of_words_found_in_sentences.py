class Solution(object):

    @staticmethod
    def most_words_found(sentences):
        """
        :type sentences: List[str]
        :rtype: int
        """
        temp_highest_num = 0

        for sentence in sentences:
            sentence_words = len(sentence.split())
            if sentence_words > temp_highest_num:
                temp_highest_num = sentence_words

        return temp_highest_num

if __name__ == '__main__':
    solution = Solution()
    result = solution.most_words_found(["alice and bob love leetcode","i think so too","this is great thanks very much"])
    print(result)