n = int(input())
arr = [0] * 10000001
arr[1] = 1
arr[2] = 2
for i in range(3, n+1):
    arr[i] = (arr[i-2] + arr[i-1]) % 10
print(arr[n])
