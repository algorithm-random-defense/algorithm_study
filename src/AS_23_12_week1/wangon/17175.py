n = int(input())
arr = [0] * 51
arr[0] = 1
arr[1] = 1
for i in range(2, 51):
    arr[i] = (arr[i-2]+arr[i-1]+1) % 1000000007
print(arr[n])
