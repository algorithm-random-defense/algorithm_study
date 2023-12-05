from collections import deque
n = int(input())

arr = []
q = deque()

for i in range(10):
    arr.append(i)
    q.append(i)

while len(q) != 0:
    idxN = q.popleft()
    for i in range(idxN % 10):
        descN = 10 * idxN + i
        arr.append(descN)
        q.append(descN)
if (n > len(arr)):
    print("-1")
else:
    print(arr[n-1])
