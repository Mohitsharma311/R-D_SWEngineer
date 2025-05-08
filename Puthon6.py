from itertools import permutations
nums = [7, 8, 5]
all_perms = list(permutations(nums))
all_perms = [list(p) for p in all_perms]
print("All possible permutations:")
for p in all_perms:
    print(p)
