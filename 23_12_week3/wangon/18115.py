#카드 놓기
from collections import deque

n = int(input())
method = list(map(int, input().split()))
dq = deque()

num = 1
while len(method):
    if method[-1] == 1:
        dq.appendleft(num)
    elif method[-1] == 2:
        dq.insert(1, num)
    elif method[-1] == 3:
        dq.append(num)
    num += 1
    method.pop()

print(*dq)
