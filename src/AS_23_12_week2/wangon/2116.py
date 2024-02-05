n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
idx = [5, 3, 4, 1, 2, 0]
sumArr = []
for i in range(6):
    tmp_f = arr[0].copy()
    first_bot = tmp_f[i]
    first_op = tmp_f[idx[i]]
    tmp_f.remove(first_bot)
    tmp_f.remove(first_op)
    sumArr.append(max(tmp_f))
    op = first_op
    for j in range(1, n):
        tmp = arr[j].copy()
        bot = op
        op = tmp[idx[arr[j].index(bot)]]
        tmp.remove(bot)
        tmp.remove(op)
        sumArr[i] += max(tmp)

print(max(sumArr))
