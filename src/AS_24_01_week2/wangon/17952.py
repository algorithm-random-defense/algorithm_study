class subject:
    def __init__(self, score, deadline):
        self.score = score
        self.deadline = deadline

n = int(input())
ret = 0
arr = []

for _ in range (n):
    inputs = list(map(int, input().split()))
    if inputs[0]:
        obj = subject(inputs[1], inputs[2])
        arr.append(obj)
    if len(arr) == 0:
        continue
    arr[-1].deadline -= 1
    if arr[-1].deadline == 0:
        ret += arr[-1].score
        arr.pop()
print(ret)
