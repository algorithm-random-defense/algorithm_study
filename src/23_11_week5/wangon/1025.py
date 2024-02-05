import math

def is_square(n):
    root = int(math.sqrt(n))
    return root * root == n

n, m = map(int, input().split())
arr = [input() for _ in range(n)]

maxr = -1
for i in range(n):
    for j in range(m):
        for diff_i in range(-n, n):
            for diff_j in range(-m, m):
                if diff_i == 0 and diff_j == 0:
                    continue
                nb = ""
                cur_i, cur_j = i, j
                while cur_i >= 0 and cur_i < n and cur_j >= 0 and cur_j < m:
                    nb += arr[cur_i][cur_j]
                    if is_square(int(nb)):
                        maxr = max(maxr, int(nb))
                    cur_i += diff_i
                    cur_j += diff_j
print(maxr)

