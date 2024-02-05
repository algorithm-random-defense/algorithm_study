def func(n, l):
    for len in range(l, 101):
        if (n * 2) % len == 0:
            start = (2 * n - len * (len - 1)) / (2 * len)
            if start >= 0:
                result = []
                sum = 0
                for i  in range(int(start), int(start + len)):
                    sum = sum + i
                    result.append(i)
                if (sum == n):
                    return result
    return []

n, l = map(int, input().split())
ans = func(n, l)
if len(ans) == 0:
    print("-1")
else:
    print(*ans, sep=' ')




