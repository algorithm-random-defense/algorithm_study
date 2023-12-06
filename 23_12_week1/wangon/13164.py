n, k = map(int, input().split())

arr = list(map(int, input().split()))
arr.sort()

diff = [arr[i + 1] - arr[i] for i in range(n - 1)]
diff.sort(reverse=True)

result = sum(diff[k-1:])
print(result)
