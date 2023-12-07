n = int(input())
direct = [[0] * n for _ in range(n)]

for i in range(n):
    row = input().strip()
    for j in range(n):
        if row[j] == 'Y':
            direct[i][j] = 1

indirect = [row[:] for row in direct]
for i in range(n):
    for j in range(n):
        for k in range(n):
            if i != j and direct[i][j] == 0:
                if direct[j][k] == 1 and direct[k][i] == 1:
                    indirect[i][j] = 1

ans = 0
for i in range(n):
    count = 0
    for j in range(n):
        if indirect[i][j] == 1:
             count += 1
    friends = count
    ans = max(ans, friends)
print(ans)

