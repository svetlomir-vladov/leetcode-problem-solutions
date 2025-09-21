class Solution(object):
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
