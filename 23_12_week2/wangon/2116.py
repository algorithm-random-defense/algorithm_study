#첫줄에는 주사위의 개수가 입력된다.
#그 다음 줄부터는 한 줄에 하나씩 주사위의 종류가 1번 주사위부터 주사위 번호 순서대로 입력된다.
#주사위의 종류는 각 면에 적혀진 숫자가 그림1에 있는 주사위의 전개도에서 A, B, C, D, E, F 의 순서로 입력된다.
#입력되는 숫자 사이에는 빈 칸이 하나씩 있다.
#주사위의 개수는 10,000개 이하이며 종류가 같은 주사위도 있을 수 있다.
#0 - 5, 1 - 3, 2 - 4
#A - F, B - D, C - E

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
