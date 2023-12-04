from collections import deque

n, m = map(int, input().split())
targets = list(map(int, input().split()))
q = deque(range(1, n+1))

cnt = 0
for target in targets:
	while True:
		if q[0] == target:
			q.popleft()
			break
		else:
			if q.index(target) <= len(q) // 2:
				q.rotate(-1)
				cnt += 1
			else:
				q.rotate(1)
				cnt += 1
print(cnt)
