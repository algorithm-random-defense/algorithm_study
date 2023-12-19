from collections import deque

t = int(input())
for _ in range(t):
    n = int(input())
    ret = -1
    arr = list(map(int, input().split()))
    d = deque()
    arr.sort()
    d.append(arr[-1])
    arr.pop()
    flag = 1
    while len(arr):
        if flag == 1:
            d.append(arr[-1])
        else:
            d.appendleft(arr[-1])
        flag *= -1
        arr.pop()
    for i in range(n-1):
        ret = max(ret, abs(d[i] - d[i+1]))
    ret = max(ret, abs(d[-1] - d[0]))
    print(ret)


