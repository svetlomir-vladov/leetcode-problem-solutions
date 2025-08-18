from collections import defaultdict, deque


class Solution(object):
    @staticmethod
    def find_all_recipes(recipes, ingredients, supplies):
        """
        :type recipes: List[str]
        :type ingredients: List[List[str]]
        :type supplies: List[str]
        :rtype: List[str]
        """

        recipe_ingredients = [(r, set(ing)) for r, ing in zip(recipes, ingredients)]
        supplies = set(supplies)
        created_items = []

        new_items = [True]
        while new_items:
            remaining = []
            new_items = []

            for item, ingredients_needed in recipe_ingredients:
                if ingredients_needed.issubset(supplies):
                    new_items.append(item)
                else:
                    remaining.append((item, ingredients_needed))

            recipe_ingredients = remaining
            created_items.extend(new_items)
            supplies.update(new_items)

        return created_items


if __name__ == '__main__':
    solution = Solution()
    result = solution.find_all_recipes(recipes=["bread","sandwich"], ingredients=[["yeast","flour"],["bread","meat"]], supplies=["yeast","flour","meat"])
    print(result)
