from collections import defaultdict, deque


class Solution(object):

    @staticmethod
    def deepseek(recipes, ingredients, supplies):
        """
        :type recipes: List[str]
        :type ingredients: List[List[str]]
        :type supplies: List[str]
        :rtype: List[str]
        """

        # Precompute dependencies
        supplies_set = set(supplies)
        dep_map = defaultdict(list)  # Maps ingredients to dependent recipes
        missing_count = {}  # Tracks missing ingredients per recipe
        created = []

        # Initialize dependency tracking
        for recipe, ing in zip(recipes, ingredients):
            required = set(ing)
            missing = required - supplies_set
            missing_count[recipe] = len(missing)
            for item in missing:
                dep_map[item].append(recipe)

        # Initialize queue with recipes that have no missing ingredients
        queue = deque([recipe for recipe, count in missing_count.items() if count == 0])

        # Process recipes in BFS order
        while queue:
            recipe = queue.popleft()
            created.append(recipe)
            # Update dependencies for recipes waiting on this item
            if recipe in dep_map:
                for dependent in dep_map[recipe]:
                    missing_count[dependent] -= 1
                    if missing_count[dependent] == 0:
                        queue.append(dependent)

        return created

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