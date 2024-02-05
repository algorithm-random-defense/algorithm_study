
def func(mid, size):
    cnt = 0
    for i in range(1, size):
      distance = road[i] - road[i - 1]
      cnt += distance // mid
      if distance % mid == 0:
        cnt -= 1
    return cnt > m

n, m, l = map(int, input().split())
road = [0, l]

values = list(map(int, input().split()))

for val in values:
   road.append(val)

road.sort()

start = 1
end = l
ret = 0

while start <= end:
    mid = (start + end) // 2
    if func(mid, len(road)) == True:
        start = mid + 1
    else:
        ret = mid
        end = mid - 1

print(ret)
