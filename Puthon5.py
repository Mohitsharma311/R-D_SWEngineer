def combination_sum(candidates, target):
    result = []

    def backtrack(combination, start, target):
        if target == 0:
            result.append(list(combination))
            return
        elif target < 0:
            return

        for i in range(start, len(candidates)):
            combination.append(candidates[i])
            backtrack(combination, i, target - candidates[i])
            combination.pop()

    backtrack([], 0, target)
    return result
candidates = [2, 3, 6, 7]
target = 7
output = combination_sum(candidates, target)
print("Combinations that sum to", target, "are:")
for combo in output:
    print(combo)


