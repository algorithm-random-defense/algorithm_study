n, k = map(int, input().split())

ret = 0
while True:
    cnt = 0
    bottles = n
    while bottles:
        if bottles % 2:
            cnt += 1
        bottles //= 2
    if cnt <= k:
        break
    n += 1
    ret += 1
print(ret)
